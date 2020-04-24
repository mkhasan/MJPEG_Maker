/*
 * stream_source.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#include "stream_source.h"

StreamSource::StreamSource(int _width, int _height, CStreamer * _streamer)
	: width(_width)
	, height(_height)
	, streamer(_streamer)
{

}

StreamSource::~StreamSource() {
	printf("In StreamSource Destructor \n");
}



