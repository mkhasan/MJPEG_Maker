/*
 * stream_source.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#include "stream_source.h"

#include <stdio.h>
#include <new>

StreamSource::StreamSource(int _width, int _height, CStreamer * _streamer, ImageWriter * _writer)
	: width(_width)
	, height(_height)
	, streamer(_streamer)
	, writer(_writer)
{
	streamer->data = new (std::nothrow) char[writer->GetMaxDataSize()];
	printf(" ************************  source created ************************** \n ");
}

StreamSource::~StreamSource() {
	printf("In StreamSource Destructor \n");
	delete[] streamer->data;
}



