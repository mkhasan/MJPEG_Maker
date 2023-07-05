/*
 * stream_source.h
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#ifndef SRC_STREAM_SOURCE_H_
#define SRC_STREAM_SOURCE_H_

#include "CStreamer.h"
#include "image_writer.h"

class StreamSource {

public:
	static int WIDTH;
	static int HEIGHT;

protected:
	int width;
	int height;
	int streamID;
	CStreamer * streamer;
	ImageWriter * writer;
public:
	StreamSource(int width, int height, int streamID, CStreamer * streamer, ImageWriter * writer);
	virtual ~StreamSource();
	void SetStreamID(int streamID);
};


#endif /* SRC_STREAM_SOURCE_H_ */
