/*
 * stream_source.h
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#ifndef SRC_STREAM_SOURCE_H_
#define SRC_STREAM_SOURCE_H_

#include "CStreamer.h"

class StreamSource {

protected:
	int width;
	int height;
	CStreamer * streamer;
public:
	StreamSource(int width, int height, CStreamer * streamer);
	virtual ~StreamSource();
};


#endif /* SRC_STREAM_SOURCE_H_ */
