/*
 * fake_source.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#include "utils.h"
#include "fake_source.h"

#include <pthread.h>
#include <unistd.h>

#ifdef __cplusplus

extern "C" {
#endif

#include <jpeglib.h>
#include "jpeg_writer.h"


#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>


#ifdef __cplusplus
}
#endif



using namespace std;
using namespace mjpeg_maker;

const string FakeSource::filename = "/media/hasan/External/Movie/IceAge.avi";
static void SaveFrame(AVFrame *pFrame, int width, int height, int iFrame, char * data, int qualityFactor, ImageWriter * writer);

/*
GLOBAL(void)
init_JPEG ();

GLOBAL(void)
write_JPEG_file (char * data, int quality);

GLOBAL(void)
finalize_JPEG ();

*/




FakeSource::FakeSource(CStreamer * streamer) : StreamSource(WIDTH, HEIGHT, streamer, new JPEG_Writer(WIDTH, HEIGHT)), quit(false), tid(NULL)
{
	info.quit = &quit;
	info.streamer = streamer;
	info.writer = writer;

	int err = pthread_create(&tid, NULL, &stream_generator, (void *) &info);
	if (err != 0)
	{
		stringstream ss;
		ss << "can't create thread :[" << err << "]";
		THROW(RobotException, ss.str().c_str());
	}

}

FakeSource::~FakeSource() {

	printf("In FakeSource Destructor \n");
	if (tid != NULL && quit == false) {
		quit = true;
		pthread_join(tid, NULL);
	}

	delete writer;
}


void * FakeSource::stream_generator(void * arg) {
	AVFormatContext *pFormatCtx = NULL;
	int             i, videoStream;
	AVCodecContext  *pCodecCtx = NULL;
	AVCodec         *pCodec = NULL;
	AVFrame         *pFrame = NULL;
	AVFrame         *pFrameRGB = NULL;
	AVPacket        packet;
	int             frameFinished;
	int             numBytes;
	uint8_t         *buffer = NULL;

	AVDictionary    *optionsDict = NULL;
	struct SwsContext      *sws_ctx = NULL;


	info_struct *info = (info_struct *) arg;

	av_register_all();

	if(avformat_open_input(&pFormatCtx, filename.c_str(), NULL, NULL)!=0) {
		fprintf(stderr, "Couldn't open file \n");
	    return NULL;
	}

	// Retrieve stream information
	if(avformat_find_stream_info(pFormatCtx, NULL)<0) {
		fprintf(stderr, "Couldn't find stream information \n");
		return NULL;
	}

	av_dump_format(pFormatCtx, 0, filename.c_str(), 0);


	videoStream=-1;
	for(i=0; i<pFormatCtx->nb_streams; i++) {
		if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO) {
			videoStream=i;
			break;
	    }
	}

	if(videoStream==-1) {
		fprintf(stderr, "Didn't find a video stream \n");
		return NULL;
	}


	pCodecCtx=pFormatCtx->streams[videoStream]->codec;


	pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
	if(pCodec==NULL) {
		fprintf(stderr, "Unsupported codec \n");
		return NULL; // Codec not found
	}
	// Open codec
	if(avcodec_open2(pCodecCtx, pCodec, &optionsDict)<0) {
		fprintf(stderr, "Could not open codec \n");
		return NULL;
	}

	// Allocate video frame
	pFrame=av_frame_alloc();

	// Allocate an AVFrame structure
	pFrameRGB=av_frame_alloc();
	if(pFrameRGB==NULL) {
		fprintf(stderr, "Could not get frame \n");
		return NULL;
	}

	// Determine required buffer size and allocate buffer
	numBytes=avpicture_get_size(AV_PIX_FMT_RGB24, pCodecCtx->width,
				  pCodecCtx->height);
	buffer=(uint8_t *)av_malloc(numBytes*sizeof(uint8_t));

	sws_ctx =
			sws_getContext
			(
				pCodecCtx->width,
				pCodecCtx->height,
				pCodecCtx->pix_fmt,
				pCodecCtx->width,
				pCodecCtx->height,
				AV_PIX_FMT_RGB24,
				SWS_BILINEAR,
				NULL,
				NULL,
				NULL
			);

	// Assign appropriate parts of buffer to image planes in pFrameRGB
	// Note that pFrameRGB is an AVFrame, but AVFrame is a superset
	// of AVPicture

	avpicture_fill((AVPicture *)pFrameRGB, buffer, AV_PIX_FMT_RGB24,
		 pCodecCtx->width, pCodecCtx->height);

	// Read frames and save first five frames to disk

	//init_JPEG();


	printf("before data read\n");



	info->writer->Initialize();

	while(av_read_frame(pFormatCtx, &packet)>=0 && (info->streamer->finished == 0) && *(info->quit) == false) {

		//printf("data read\n");
	    // Is this a packet from the video stream?
	    if(packet.stream_index==videoStream) {
	      // Decode video frame
	    	avcodec_decode_video2(pCodecCtx, pFrame, &frameFinished,
				   &packet);

			// Did we get a video frame?
			if(frameFinished) {
	    	  // Convert the image from its native format to RGB
				sws_scale
				(
					sws_ctx,
					(uint8_t const * const *)pFrame->data,
					pFrame->linesize,
					0,
					pCodecCtx->height,
					pFrameRGB->data,
					pFrameRGB->linesize
				);


				if(info->streamer->streamStarted)
				{
					SaveFrame(pFrameRGB, pCodecCtx->width, pCodecCtx->height,
						1, info->streamer->data, (int) info->streamer->GetQualityFactor(), info->writer);

					info->streamer->StreamImage(1);
				}
			}

			//printf("value of index %d \n", i++);
	    }

	    // Free the packet that was allocated by av_read_frame
	    av_free_packet(&packet);
	    usleep(40000);

	    //  cout<< "tsleep : "<<tsleep<<" twakeup : "<<twakeup<<" t1 :"<<t1<<endl;

	}

	*(info->quit) = true;

	return NULL;
}

//JSAMPLE * image_buffer;	/* Points to large array of R,G,B-order data */
//int image_height;	/* Number of rows in image */
//int image_width;		/* Number of columns in image */

//AVFrame *curFrame;

void SaveFrame(AVFrame *pFrame, int width, int height, int iFrame, char * data, int qualityFactor, ImageWriter * writer) {
  FILE *pFile;
  char szFilename[32];
  int  y;


  if (iFrame == 1)
  {
	  //curFrame = pFrame;
	  //image_height = height;
	  //image_width = width;
	  //write_JPEG_file(data, qualityFactor);
	  writer->Write(data, (char *)pFrame->data[0], pFrame->linesize[0], qualityFactor);

  }

}
