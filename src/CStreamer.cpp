// MediaLAN 02/2013
// CRtspSession
// - JPEG packetizer and UDP/TCP based streaming

#include <iostream>

#include "client_handler.h"

#include "stream_source.h"
#include "CStreamer.h"
#include "JPEGSamples.h"
//#include "mjpeg_tester.h"

#include "config.h"
#include <stdio.h>

#include <assert.h>
#include <new>
#include <arpa/inet.h>
#include <sys/socket.h>


//sig_atomic_t CStreamer::streamStarted = 0;

using namespace std;

//int CStreamer::MAX_DATA_SIZE = 1920*1080*3+1024;
CStreamer::CStreamer(Client_Handler *_aClientHandler)
	: m_ClientHandler(_aClientHandler)
	, finished(0)
	, dataLen(0)
	, data(NULL)
	, streamStarted(0)

{
    m_RtpServerPort  = 0;
    m_RtcpServerPort = 0;
    m_RtpClientPort  = 0;
    m_RtcpClientPort = 0;

    m_SequenceNumber = 0;
    m_Timestamp      = 0;
    m_SendIdx        = 0;
    m_TCPTransport   = false;

    //data = new (nothrow) char[MAX_DATA_SIZE];


    //this->activate();

	//printf("++++++++++++++++++++++++++++++++++++ %d\n", MAX_DATA_SIZE);
};

CStreamer::~CStreamer()
{
	finished = 1;
	//this->wait();
    m_RtpSocket.close();
    m_RtcpSocket.close();

    //delete[] data;

    // do no allocate or deallocate this data...StreamSource is responsible for that

    cout << "in destructor " << endl;
};

unsigned char CStreamer::GetQualityFactor() {
	return QUALITY_FACTOR;
}


void CStreamer::SendRtpPacket(char * Jpeg, int JpegLen, int width, int height) {

	const int MAX_PAYLOAD_SIZE = 1456;

	int offset = 0;
    
	for(int len = JpegLen; len > 0; len -= MAX_PAYLOAD_SIZE, offset += MAX_PAYLOAD_SIZE) {
		SendRtpPacket(&Jpeg[offset], std::min(len, MAX_PAYLOAD_SIZE), width, height, len <= MAX_PAYLOAD_SIZE, offset);
		//SendRtpPacket(&Jpeg[len], std::min(len, MAX_PAYLOAD_SIZE), width, height, len <= MAX_PAYLOAD_SIZE, offset);
	}
    

    
}

void CStreamer::SendRtpPacket(char * Jpeg, int JpegLen, int width, int height, bool isLastPacket, unsigned int offset)
{
#define KRtpHeaderSize 12           // size of the RTP header
#define KJpegHeaderSize 8           // size of the special JPEG payload header

	assert(Jpeg-data >= 4+12+8);
    char*        RtpBuf = Jpeg-24;



    int         RtpPacketSize = JpegLen + KRtpHeaderSize + KJpegHeaderSize;

    ACE_INET_Addr remoteAddr;
    m_ClientHandler->peer().get_remote_addr(remoteAddr);

    remoteAddr.set_port_number(m_RtpClientPort);

    // get client address for UDP transport


    // Prepare the first 4 byte of the packet. This is the Rtp over Rtsp header in case of TCP based transport
    RtpBuf[0]  = '$';        // magic number
    RtpBuf[1]  = 0;          // number of multiplexed subchannel on RTPS connection - here the RTP channel
    RtpBuf[2]  = (RtpPacketSize & 0x0000FF00) >> 8;
    RtpBuf[3]  = (RtpPacketSize & 0x000000FF);
    // Prepare the 12 byte RTP header
    RtpBuf[4]  = 0x80;                               // RTP version
    if (isLastPacket)								 // JPEG payload (26) and marker bit
    	RtpBuf[5] = 0x9a;
    else
    	RtpBuf[5] = 0x1a;
    RtpBuf[7]  = m_SequenceNumber & 0x0FF;           // each packet is counted with a sequence counter
    RtpBuf[6]  = m_SequenceNumber >> 8;
    RtpBuf[8]  = (m_Timestamp & 0xFF000000) >> 24;   // each image gets a timestamp
    RtpBuf[9]  = (m_Timestamp & 0x00FF0000) >> 16;
    RtpBuf[10] = (m_Timestamp & 0x0000FF00) >> 8;
    RtpBuf[11] = (m_Timestamp & 0x000000FF);
    RtpBuf[12] = 0x13;                               // 4 byte SSRC (sychronization source identifier)
    RtpBuf[13] = 0xf9;                               // we just an arbitrary number here to keep it simple
    RtpBuf[14] = 0x7e;
    RtpBuf[15] = 0x67;
    // Prepare the 8 byte payload JPEG header
    RtpBuf[16] = 0x00;                               // type specific
    RtpBuf[17] = (offset & 0x00FF0000) >> 16;                               // 3 byte fragmentation offset for fragmented images
    RtpBuf[18] = (offset & 0x0000FF00) >> 8;
    RtpBuf[19] = (offset & 0x000000FF);
    RtpBuf[20] = 0x01;                               // type
    RtpBuf[21] = QUALITY_FACTOR;                     // quality scale factor
    RtpBuf[22] = width/8;//0x06;                           // width  / 8 -> 48 pixel
    RtpBuf[23] = height/8;//0x04;                           // height / 8 -> 32 pixel
    // append the JPEG scan data to the RTP buffer
    //memcpy(&RtpBuf[24],Jpeg,JpegLen);
    
    m_SequenceNumber++;                              // prepare the packet counter for the next packet
    if (isLastPacket)
    	m_Timestamp += 3600;                             // fixed timestamp increment for a frame rate of 25fps

    if (m_TCPTransport) { // RTP over RTSP - we send the buffer + 4 byte additional header
    	m_ClientHandler->peer().send_n(RtpBuf, RtpPacketSize + 4,0);
    	printf("using tcp \n");
    }


    else {               // UDP - we send just the buffer by skipping the 4 byte RTP over RTSP header
         
    	if (m_RtpSocket.send (&RtpBuf[4], RtpPacketSize, remoteAddr) < 0) {
            cout << "Error in sending packet in udp" << endl;
        }
    }

};

void CStreamer::InitTransport(u_short aRtpPort, u_short aRtcpPort, bool TCP)
{

	ACE_INET_Addr addr;

    m_RtpClientPort  = aRtpPort;
    m_RtcpClientPort = aRtcpPort;
    m_TCPTransport   = TCP;

    // assuming that we will not receive any feedback abount image queality

    m_RtpSocket.open(ACE_Addr::sap_any);



 
};

u_short CStreamer::GetRtpServerPort()
{
    return m_RtpServerPort;
};

u_short CStreamer::GetRtcpServerPort()
{
    return m_RtcpServerPort;
};

void CStreamer::StreamImage(char * data, int len, int width, int height) {

	SendRtpPacket(data, len, width, height);
}





bool CStreamer::IsSOI(char x, char y)
{
	int valX = 0xff & x;
	int valY = 0xff & y;
	return (valX == 0xff && valY  == 0xd8);
}

bool CStreamer::IsAPP0(char x, char y)
{
	int valX = 0xff & x;
	int valY = 0xff & y;
	return (valX == 0xff && valY  == 0xe0);
}

bool CStreamer::IsDQT(char x, char y)
{
	int valX = 0xff & x;
	int valY = 0xff & y;
	return (valX == 0xff && valY  == 0xdb);
}

bool CStreamer::IsSOF(char x, char y)
{
	int valX = 0xff & x;
	int valY = 0xff & y;
	return (valX == 0xff && valY  == 0xc0);
}

bool CStreamer::IsDHT(char x, char y)
{
	int valX = 0xff & x;
	int valY = 0xff & y;
	return (valX == 0xff && valY  == 0xc4);
}

bool CStreamer::IsSOS(char x, char y)
{
	int valX = 0xff & x;
	int valY = 0xff & y;
	return (valX == 0xff && valY  == 0xda);
}

int CStreamer::GetLength(char x, char y)
{
	int valX = 0xff & x;
	int valY = 0xff & y;

	int len = (valX << 8 | valY);

	return len;

}


int CStreamer::GetDataFromFile(char * data)
{

	return -1;

	char s[100];
	//sprintf(s, "resized_94/img%02d.jpg", 3);

	sprintf(s, "test.jpg");

	ifstream src(s, ios::binary);

	assert(src.is_open());
	char ch;
	int i=0;

	int imageDataLen = filesize(s);
	for(i=0; i<imageDataLen; i++)
	{
		src.read(&ch, 1);

		data[i] =ch;


	}

	//assert(imageDataLen <= MAX_DATA_SIZE);
	src.close();

	return imageDataLen;


}

std::ifstream::pos_type CStreamer::filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

int CStreamer::GetImageLength(const char * data)
{
	int i=0;
	/*
	int val_1, val_2;
	for (i=0; i<MAX_DATA_SIZE-1; i++)
	{
		val_1 = (int) data[i] & 0xff;
		val_2 = (int) data[i+1] & 0xff;

		if (val_1 == 0xff && val_2 == 0xd9)
			break;
	}

	if (i == MAX_DATA_SIZE -1)
		return -1;

	*/
	return i+2;
}
