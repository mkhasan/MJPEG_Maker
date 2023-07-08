/*
 * fake_source.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#include "utils.h"
#include "fake_source.h"
#include "JPEGSamples.h"

#include <pthread.h>
#include <unistd.h>

#ifdef __cplusplus

extern "C" {
#endif

#include <jpeglib.h>
#include "jpeg_writer.h"



#ifdef __cplusplus
}
#endif

#include <assert.h>


using namespace std;
using namespace mjpeg_maker;


FakeSource::FakeSource(CStreamer * streamer, int streamID)
	: StreamSource(width, height, streamID, streamer, NULL)
	, quit(false), tid(NULL)
{
	
	printf("FakeSource gonna be created (%d %d)\n", width, height);
	info.quit = &quit;
	info.streamer = streamer;
	info.width = width;
	info.height = height;

	int err = pthread_create(&tid, NULL, &stream_generator, (void *) &info);
	if (err != 0)
	{
		stringstream ss;
		ss << "can't create thread :[" << err << "]";
		THROW(RobotException, ss.str().c_str());
	}

	printf("FakeSource created \n");

}

FakeSource::~FakeSource() {

	printf("In FakeSource Destructor \n");
	if (tid != NULL && quit == false) {
		quit = true;
		printf("waiting for thread to finish \n");
		pthread_join(tid, NULL);
		printf("done \n");
	}

}


void * FakeSource::stream_generator(void * arg) {

	info_struct *info = (info_struct *) arg;
    
    

	int count = 0;
    int len = 0;
	const int offset = 100;
	char payload[offset+KJpegCh1ScanDataLen];

	while(*(info->quit) == false) {
		
		len = KJpegCh1ScanDataLen;
		if (count % 2 == 0) {
			memcpy(&payload[offset], JpegScanDataCh1A, KJpegCh1ScanDataLen);
		}
		else {
			memcpy(&payload[offset], JpegScanDataCh1B, KJpegCh1ScanDataLen);
		}
        
        if (len > 0 && info->streamer->streamStarted && *(info->quit) == false) {
            	info->streamer->StreamImage(&payload[offset], len, info->width, info->height);
			count = 1-count;


        }

		

	    usleep(40000);

	}


	*(info->quit) = true;


	return NULL;
}

