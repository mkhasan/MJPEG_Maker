/*
 * fake_source.cpp
 *
 *  Created on: Apr 24, 2020
 *      Author: hasan
 */

#include "utils.h"
#include "fake_source.h"

using namespace std;
using namespace mjpeg_maker;

const string FakeSource::filename = "/media/hasan/External/Movie/IceAge.avi";

FakeSource::FakeSource() : StreamSource(WIDTH, HEIGHT)
{

}


