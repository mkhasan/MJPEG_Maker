/*
 * stream_source.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#include "stream_source.h"

#include <stdio.h>
#include <new>
#include <assert.h>

StreamSource::StreamSource(int _width, int _height, CStreamer * _streamer, ImageWriter * _writer)
	: width(_width)
	, height(_height)
	, streamer(_streamer)
	, writer(_writer)

{
	if (width > 0 && height > 0) {
		streamer->data = new (std::nothrow) char[writer->GetMaxDataSize()];
		printf(" ************************  source created ************************** \n ");
	}
	else
		assert(0);

}


StreamSource::~StreamSource() {
	printf("In StreamSource Destructor \n");
	delete[] streamer->data;
}




