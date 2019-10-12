/*
 * compress.cpp
 *
 *  Created on: Nov 24, 2016
 *      Author: usrc
 */


#include <fstream>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <opencv2/opencv.hpp>

#include "config.h"

using namespace std;
using namespace cv;


void compress(char * pattern);
int max_size(char * pattern);
std::ifstream::pos_type filesize(const char* filename);

int main()
{

	char ch = 'a';
	try
	{

		compress("%03d.jpg");
		//max_size("%03d.jpg");



	}
	catch(...)
	{
		cout << "Error" << endl;
	}

	return 0;
}



void compress(char * pattern)
{
	char filename[100];
	sprintf(filename, "%s/img/img%s",DATA_DIR, pattern);
	//VideoCapture cap = VideoCapture(filename);//"temp/img%02d.jpg");

	VideoCapture cap("rtsp://localhost:8555/mjpeg/1");

	assert(cap.isOpened());

	return;


	Mat frame, resizedFrame;

	static vector<uchar> encoded;

	int maxSize = 0;

	char outFilename[100];
	for (int i=0; i<FRAME_COUNT; i++)
	{
		if (i == 5)
		{
			cap = VideoCapture(filename);//"temp/img%02d.jpg");
			assert(cap.isOpened());
		}


		cap >> frame;

		resize(frame, resizedFrame, Size(WIDTH, HEIGHT), 0, 0, INTER_LINEAR);

		vector<int> params;
		params.push_back(cv::IMWRITE_JPEG_QUALITY);
		params.push_back(94);

		imencode(".jpg", resizedFrame, encoded, params);

		string s = "resized1/img";
		s += pattern;

		sprintf(outFilename, s.c_str(), i);

		//cout << outFilename << endl;

		ofstream dest(outFilename, ios::binary);

		char ch[1];
		long size = 1;

		if (maxSize < encoded.size())
			maxSize = encoded.size();
		for (int i=0; i<encoded.size(); i++)
		{
			ch[0] = encoded[i];
			dest.write(ch, size);

		}



		//imwrite(outFilename, resizedFrame);

		dest.close();




	}

	cout << "Max Size is " << maxSize << endl;
}


int max_size (char * pattern)
{

	char filename[100];


	static vector<uchar> encoded;

	int maxSize = 0;


	for (int i=0; i<270; i++)
	{


		string s = "resized/img";
		s += pattern;

		sprintf(filename, s.c_str(), i);

		int size = filesize(filename);
		//cout << "File name " << filename << " Size " << size <<  endl;


		if (maxSize < size)
			maxSize = size;




	}

	cout << "Max Size is " << maxSize << endl;

	return maxSize;
}

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}
