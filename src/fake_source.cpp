/*
 * fake_source.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#include "utils.h"
#include "fake_source.h"

#include <pthread.h>

using namespace std;
using namespace mjpeg_maker;

const string FakeSource::filename = "/media/hasan/External/Movie/IceAge.avi";

FakeSource::FakeSource(CStreamer * streamer) : StreamSource(WIDTH, HEIGHT, streamer), quit(false)
{
	info.quit = &quit;
	info.streamer = streamer;

	int err = pthread_create(&tid, NULL, &stream_generator, (void *) &info);
	if (err != 0)
	{
		stringstream ss;
		ss << "can't create thread :[" << err << "]";
		THROW(RobotException, ss.str().c_str());
	}


}

void * FakeSource::stream_generator(void * arg) {

	return NULL;
}

