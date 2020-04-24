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
	static const int WIDTH = 520;
	static const int HEIGHT = 274;

private:
	const static std::string filename;
	bool quit;
	pthread_t tid;

public:
	const int SLEEP_IN_US = 40000;

	struct info_struct {
		bool * quit;
		CStreamer * streamer;
		ImageWriter * writer;
	} info;

	FakeSource(CStreamer * streamer);
	~FakeSource();
	static void * stream_generator(void * arg);

};

#endif /* SRC_FAKE_SOURCE_H_ */
