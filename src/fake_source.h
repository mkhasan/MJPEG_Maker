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

	const int WIDTH = 520;
	const int HEIGHT = 274;
	const int SLEEP_IN_US = 40000;
	const static std::string filename;
public:
	FakeSource();
};

#endif /* SRC_FAKE_SOURCE_H_ */
