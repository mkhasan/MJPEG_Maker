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


struct source_info_t {
	const std::string filename;
	const int width;
	const int height;
};

//static const source_info_t source_info = {"/home/mecasys/extension/movie_clips/sMoky.avi", 320, 240};
static const source_info_t source_info = {"/dev/video0", 1920, 1080};


class FakeSource : public StreamSource {

public:

	static int WIDTH;
	static int HEIGHT;

private:
	const std::string filename = source_info.filename;
	
	bool quit;
	pthread_t tid;

public:
	const int SLEEP_IN_US = 40000;

	struct info_struct {
		bool * quit;
		CStreamer * streamer;
		ImageWriter * writer;
		std::string filename;
	} info;

	FakeSource(CStreamer * streamer,int streamID);
	~FakeSource();
	static void * stream_generator(void * arg);

};

#endif /* SRC_FAKE_SOURCE_H_ */
