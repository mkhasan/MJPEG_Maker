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
#include <libavutil/frame.h>

#ifdef __cplusplus
}
#endif

class JPEG_Writer {

	bool isInitialized;
	const static int MAX_DATA_SIZE = 163840;
	int maxDataSize;

	int image_width;
	int image_height;

	void init_JPEG();
	void finalize_JPEG();
	void write_JPEG_file(char * data, AVFrame * curFrame, int quality);

public:

	JPEG_Writer(int maxDataSize = MAX_DATA_SIZE);
	~JPEG_Writer();

	void Initialize(int image_width, int image_height);
	void Finalize();

	void Write(char * dest, AVFrame * src, int quality);
};



#endif /* SRC_JPEG_WRITER_H_ */
