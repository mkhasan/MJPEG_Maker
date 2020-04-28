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

StreamSource::StreamSource(int _width, int _height, int _streamID, CStreamer * _streamer, ImageWriter * _writer)
	: width(_width)
	, height(_height)
	, streamer(_streamer)
	, writer(_writer)
	, streamID(_streamID)
{
	//channel = streamer->m_
	//printf("channel is %d \n", streamID );
	//assert(streamID == 0 || streamID == 1);


}


StreamSource::~StreamSource() {
	printf("In StreamSource Destructor \n");

}

void StreamSource::SetStreamID(int _streamID) {
	streamID = _streamID;

	printf("streamID is %d \n", streamID );
	assert(streamID == 0 || streamID == 1);

}


