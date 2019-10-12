/*
 * example.c
 *
 * This file illustrates how to use the IJG code as a subroutine library
 * to read or write JPEG image files.  You should look at this code in
 * conjunction with the documentation file libjpeg.txt.
 *
 * This code will not do anything useful as-is, but it may be helpful as a
 * skeleton for constructing routines that call the JPEG library.
 *
 * We present these routines in the same coding style used in the JPEG code
 * (ANSI function definitions, etc); but you are of course free to code your
 * routines in a different style if you prefer.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*
 * Include file for users of JPEG library.
 * You will need to have included system headers that define at least
 * the typedefs FILE and size_t before you can include jpeglib.h.
 * (stdio.h is sufficient on ANSI-conforming systems.)
 * You may also wish to include "jerror.h".
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <jpeglib.h>



#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>


#ifdef __cplusplus
}
#endif





#include "config.h"
#include "CStreamer.h"

//const char * STREAM = "rtsp://admin:admin@192.168.1.100:554/12";
const char * STREAM = "rtsp://admin:admin@192.168.1.101:554/stream1";


GLOBAL(void)
init_JPEG ();


GLOBAL(void)
write_JPEG_file (char * data, int quality);

GLOBAL(void)
finalize_JPEG ();


JSAMPLE * image_buffer;	/* Points to large array of R,G,B-order data */
int image_height;	/* Number of rows in image */
int image_width;		/* Number of columns in image */

AVFrame *curFrame;



void SaveFrame(AVFrame *pFrame, int width, int height, int iFrame, char * data) {
  FILE *pFile;
  char szFilename[32];
  int  y;

  if (iFrame == 1)
  {
	  curFrame = pFrame;
	  image_height = height;
	  image_width = width;
	  write_JPEG_file(data, 94);

  }

  // Open file
  /*
  sprintf(szFilename, "frame%d.ppm", iFrame);
  pFile=fopen(szFilename, "wb");
  if(pFile==NULL)
    return;


  // Write header
  fprintf(pFile, "P6\n%d %d\n255\n", width, height);

  // Write pixel data
  for(y=0; y<height; y++)
    fwrite(pFrame->data[0]+y*pFrame->linesize[0], 1, width*3, pFile);

  // Close file
  fclose(pFile);
  */
}


/*

int main(int argc, char *argv[]) {

	finished = 0;
	//Start(NULL);

	int err;
	char *b;

	err = pthread_create(&tid, NULL, &Start, NULL);
	if (err != 0)
		printf("\ncan't create thread :[%s]", strerror(err));
	sleep(10);

	finished = 1;

	pthread_join(tid, (void  **)&b);

	sleep(1);

	printf("return value is %d \n", b);

	free(b);

	return 0;

}

*/

void * Start(void * arg) {
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

  CStreamer * pStreamer = (CStreamer *) arg;
/*
  if(argc < 2) {
    printf("Please provide a movie file\n");
    return -1;
  }
*/
  //CStreamer * pStreamer = (CStreamer *) arg;
  // Register all formats and codecs
  av_register_all();

  // Open video file
  if(avformat_open_input(&pFormatCtx, STREAM, NULL, NULL)!=0)
    return NULL; // Couldn't open file

  // Retrieve stream information
  if(avformat_find_stream_info(pFormatCtx, NULL)<0)
    return NULL; // Couldn't find stream information

  // Dump information about file onto standard error
  av_dump_format(pFormatCtx, 0, STREAM, 0);

  // Find the first video stream
  videoStream=-1;
  for(i=0; i<pFormatCtx->nb_streams; i++)
    if(pFormatCtx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO) {
      videoStream=i;
      break;
    }
  if(videoStream==-1)
    return NULL; // Didn't find a video stream

  // Get a pointer to the codec context for the video stream
  pCodecCtx=pFormatCtx->streams[videoStream]->codec;

  // Find the decoder for the video stream
  pCodec=avcodec_find_decoder(pCodecCtx->codec_id);
  if(pCodec==NULL) {
    fprintf(stderr, "Unsupported codec!\n");
    return NULL; // Codec not found
  }
  // Open codec
  if(avcodec_open2(pCodecCtx, pCodec, &optionsDict)<0)
    return NULL; // Could not open codec

  // Allocate video frame
  pFrame=av_frame_alloc();

  // Allocate an AVFrame structure
  pFrameRGB=av_frame_alloc();
  if(pFrameRGB==NULL)
    return NULL;

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
  i=0;
  init_JPEG();


  while(av_read_frame(pFormatCtx, &packet)>=0 && (pStreamer->finished == 0)) {

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

	// Save the frame to disk


	if(pStreamer->streamStarted)//++i<=5)
	{
	  SaveFrame(pFrameRGB, pCodecCtx->width, pCodecCtx->height,
		    1, pStreamer->data);

	  pStreamer->StreamImage(1);
	}
      }

      printf("value of index %d \n", i++);
    }

    // Free the packet that was allocated by av_read_frame
    av_free_packet(&packet);

  //  cout<< "tsleep : "<<tsleep<<" twakeup : "<<twakeup<<" t1 :"<<t1<<endl;

  }

  finalize_JPEG();
  // Free the RGB image
  av_free(buffer);
  av_free(pFrameRGB);

  // Free the YUV frame
  av_free(pFrame);

  // Close the codec
  avcodec_close(pCodecCtx);

  // Close the video file
  avformat_close_input(&pFormatCtx);

  return NULL;
}
