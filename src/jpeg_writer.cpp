/*
 * jpeg_writer.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */



#include "jpeg_writer.h"
#include <string.h>

#include "utils.h"

using namespace mjpeg_maker;



/* abstructing the c interface */

void
JPEG_Writer::init_JPEG()
{

	/* More stuff */
		/* target file */
  /* Step 1: allocate and initialize JPEG compression object */

	cinfo.err = jpeg_std_error(&jerr);
	/* Now we can initialize the JPEG compression object. */
	jpeg_create_compress(&cinfo);

}


void
JPEG_Writer::finalize_JPEG()
{
	jpeg_destroy_compress(&cinfo);
}

/*
void JPEG_Writer::write_JPEG_file(char * data, AVFrame * curFrame, int quality) {

}

*/

//#include "config.h"


void
JPEG_Writer::write_JPEG_file(unsigned char * dest, unsigned char * src, int stride, int quality)
{
	FILE * outfile;

	int row_stride;		/* physical row width in image buffer */

	JSAMPROW row_pointer[1];	/* pointer to JSAMPLE row[s] */

	/*
	if ((outfile = fopen(filename, "wb")) == NULL) {
			fprintf(stderr, "can't open %s\n", filename);
			exit(1);
		}

		*/

	int size = GetMaxDataSize();
	memset(dest, 0, size);

	if ((outfile = fmemopen(dest, size, "wb")) == NULL) {
			fprintf(stderr, "can't open %s\n", "mem file");
			exit(1);
		}



	//printf("widht is %d and height is %d \n", image_width, image_height);
	jpeg_stdio_dest(&cinfo, outfile);

	cinfo.image_width = image_width; 	/* image width and height, in pixels */
	cinfo.image_height = image_height;
	cinfo.input_components = 3;		/* # of color components per pixel */
	cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */

	jpeg_set_defaults(&cinfo);

	jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);

	//cinfo.scale_num = 1;
	//cinfo.scale_denom = 2;
	jpeg_start_compress(&cinfo, TRUE);

	row_stride = image_width * 3;	/* JSAMPLEs per row in image_buffer */

	int y=0;
	while (cinfo.next_scanline < cinfo.image_height) {
		/* row_pointer[0] = curFrame->data[0]+y*curFrame->linesize[0];////& image_buffer[cinfo.next_scanline * row_stride]; */
		row_pointer[0] = &src[y*stride];////& image_buffer[cinfo.next_scanline * row_stride];
		(void) jpeg_write_scanlines(&cinfo, row_pointer, 1);

		y++;
	}

  /* Step 6: Finish compression */

	jpeg_finish_compress(&cinfo);
	/* After finish_compress, we can close the output file. */

	fseek(outfile,0,SEEK_END);
	size = ftell(outfile);

	printf("size is %d \n", size);
	fclose(outfile);



	/* Step 7: release JPEG compression object */

	/* This is an important step since it will release a good deal of memory. */

}



JPEG_Writer::JPEG_Writer(int _image_width, int _image_height)
	: ImageWriter(_image_width, _image_height)
{

}

JPEG_Writer::~JPEG_Writer() {
	if (isInitialized) {
		Finalize();
	}

	isInitialized = false;
	printf("JPEG_Writer desctuctor \n");
}

void JPEG_Writer::Initialize(int _image_width, int _image_height) {

	if (isInitialized) {
		printf("Already initialized \n");
		return;

	}

	if (_image_width == 0 || _image_height == 0 || channel == 0) {
		THROW(RobotException,"Error in initialization");
	}

	image_width = _image_width;
	image_height = _image_height;

	SetMaxDataSize(image_width, image_height);

	init_JPEG();

	isInitialized = true;
}

void JPEG_Writer::Finalize() {
	if (isInitialized == false)
		return;
	finalize_JPEG();
	//isInitialized = false;
}

void JPEG_Writer::Write(char * dest, char * src, int stride, int quality) {
	write_JPEG_file((unsigned char *) dest, (unsigned char *) src, stride, quality);
}

/*
void JPEG_Writer::Write(char * dest, AVFrame * src, int quality) {
	write_JPEG_file(dest, src, quality);
}
*/
