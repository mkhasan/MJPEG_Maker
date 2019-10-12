/*
 * ImageProc.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: usrc
 */


#include <new>
#include <assert.h>
#include <iostream>

#include "ImageProc.h"


using namespace std;

int ImageProc::index = 0;

sig_atomic_t ImageProc::finished;

sig_atomic_t ImageProc::get_frame;

const double ImageProc::frameRate = FRAME_RATE;

const string ImageProc::pattern = PATTERN;



using namespace cv;

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}


ImageProc::ImageProc()
	: imageDataLen(0)
	, imageData(NULL)
{


	imageData = new (nothrow) char[MAX_DATA_SIZE];

	finished = 0;
	get_frame = 0;

	memset(imageData,0, MAX_DATA_SIZE);

	//lock.acquire();
/////////////////////////////////////////////

	/*

	vector<uchar> v;
	char s[100];
	//sprintf(s, "resized_94/img%02d.jpg", 3);

	sprintf(s, "test.jpg");

	ifstream src(s, ios::binary);

	assert(src.is_open());
	char ch;
	int i=0;

	imageDataLen = filesize(s);
	for(i=0; i<imageDataLen; i++)
	{
		src.read(&ch, 1);

		imageData[i] =ch;


	}



	assert(imageDataLen <= MAX_DATA_SIZE);
	src.close();
*/

///////////////////////////////////////////////////////////////
	//this->activate(THR_NEW_LWP);
}

ImageProc::~ImageProc()
{
	finished = 1;
	this->wait();

	delete[] imageData;
}

int ImageProc::svc()
{
	return 0;
}

int ImageProc::GetNextFrame()
{

	//unsigned int periodUs = (unsigned int) ((1000000.0/frameRate) + epsilon);
	return 0;

	char filename[100];
	sprintf(filename, "%s/img/img%s",DATA_DIR, pattern.c_str());

//	cap = VideoCapture(filename);
	//assert(cap.isOpened());

	//ACE_Time_Value twakeup, tinc, tsleep, t1;

    //tinc.set(0, periodUs);
    //twakeup = ACE_OS::gettimeofday();

    Mat frame, resizedFrame;
    static vector<uchar> encoded;


	if (index == 0)
	{
		cap = VideoCapture(filename);//"temp/img%02d.jpg");
		if(cap.isOpened() == 0)
			return -1;

	}

	//cout << "index is " << index << endl;
	cap >> frame;

	resize(frame, resizedFrame, Size(WIDTH, HEIGHT), 0, 0, INTER_LINEAR);

	vector<int> params;
	params.push_back(CV_IMWRITE_JPEG_QUALITY);
	params.push_back(94);

	imencode(".jpg", resizedFrame, encoded, params);


	PutData(encoded);


	index = (index + 1)%FRAME_COUNT;




	return 0;
}

void ImageProc::PutData(const vector<uchar> & v)
{
	assert(v.size() < MAX_DATA_SIZE);

	ThreadAutoLock guard(&lock);


	int i;
	for (i=0; i<v.size(); i++)
		imageData[i] = v[i];

	imageDataLen = i;

}

int ImageProc::GetData(char * data)
{


	char s[100];
	//sprintf(s, "resized_94/img%02d.jpg", 3);

	sprintf(s, "test.jpg");

	ifstream src(s, ios::binary);

	assert(src.is_open());
	char ch;
	int i=0;

	imageDataLen = filesize(s);
	for(i=0; i<imageDataLen; i++)
	{
		src.read(&ch, 1);

		data[i] =ch;


	}



	assert(imageDataLen <= MAX_DATA_SIZE);
	src.close();

	return imageDataLen;


	/*
	ThreadAutoLock guard(&lock);
	memcpy(data, imageData, imageDataLen);
	return imageDataLen;
	*/


}

