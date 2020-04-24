/*
 * jpeg_writer.h
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#ifndef SRC_JPEG_WRITER_H_
#define SRC_JPEG_WRITER_H_


#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <jpeglib.h>


#ifdef __cplusplus
}
#endif

#include "image_writer.h"


class JPEG_Writer : public ImageWriter {

	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	void init_JPEG();
	void finalize_JPEG();
	//void write_JPEG_file(char * data, AVFrame * curFrame, int quality);
	void write_JPEG_file(unsigned char * dest, unsigned char * src, int stride, int quality);

public:

	JPEG_Writer(int image_width, int image_heigt);
	~JPEG_Writer();

	void Initialize(int image_width, int image_height);
	void Finalize();

	//void Write(char * dest, AVFrame * src, int quality);
	void Write(char * dest, char * src, int stride, int quality);
};



#endif /* SRC_JPEG_WRITER_H_ */
