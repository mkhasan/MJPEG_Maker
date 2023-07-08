/*
 * fake_source.h
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#ifndef SRC_FAKE_SOURCE_H_
#define SRC_FAKE_SOURCE_H_

#include "stream_source.h"
#include <string>


class FakeSource : public StreamSource {

public:

private:
	
	bool quit;
	pthread_t tid;

public:
	const int SLEEP_IN_US = 40000;

	const int width = 48;
	const int height = 32;

	struct info_struct {
		bool * quit;
		CStreamer * streamer;
		int width;
		int height;
	} info;

	FakeSource(CStreamer * streamer,int streamID);
	~FakeSource();
	static void * stream_generator(void * arg);

};

#endif /* SRC_FAKE_SOURCE_H_ */
