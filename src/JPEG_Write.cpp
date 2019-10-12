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

#include "config.h"
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
#include <libavutil/frame.h>

#ifdef __cplusplus
}
#endif

#include <setjmp.h>



extern JSAMPLE * image_buffer;	/* Points to large array of R,G,B-order data */
extern int image_height;	/* Number of rows in image */
extern int image_width;		/* Number of columns in image */
extern AVFrame *curFrame;


struct jpeg_compress_struct cinfo;
struct jpeg_error_mgr jerr;


GLOBAL(void)
init_JPEG()
{

	/* More stuff */
		/* target file */



  /* Step 1: allocate and initialize JPEG compression object */

	cinfo.err = jpeg_std_error(&jerr);
	/* Now we can initialize the JPEG compression object. */
	jpeg_create_compress(&cinfo);



}

GLOBAL (void)
write_JPEG_file(char * data, int quality)
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

	memset(data, 0, MAX_DATA_SIZE);

	if ((outfile = fmemopen(data, MAX_DATA_SIZE, "wb")) == NULL) {
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

		row_pointer[0] = curFrame->data[0]+y*curFrame->linesize[0];////& image_buffer[cinfo.next_scanline * row_stride];
		(void) jpeg_write_scanlines(&cinfo, row_pointer, 1);

		y++;
	}

  /* Step 6: Finish compression */

	jpeg_finish_compress(&cinfo);
	/* After finish_compress, we can close the output file. */
	fclose(outfile);



	/* Step 7: release JPEG compression object */

	/* This is an important step since it will release a good deal of memory. */

}

GLOBAL(void)
finalize_JPEG()
{
	jpeg_destroy_compress(&cinfo);
}
