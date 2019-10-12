/*
 * ImageProc.h
 *
 *  Created on: Nov 24, 2016
 *      Author: usrc
 */

#ifndef SRC_IMAGEPROC_H_
#define SRC_IMAGEPROC_H_

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <ace/Task.h>
#include "config.h"
#include "Sync.h"

class ImageProc : public ACE_Task_Base
{
	friend class ACE_Singleton<ImageProc, ACE_SYNCH_MUTEX>;


	static int index;

	static sig_atomic_t finished;

	static const double frameRate;

	static const std::string pattern;


	cv::VideoCapture cap;


	ACE_Thread_Mutex lock;

public:
	char * imageData;
	int imageDataLen;

	static sig_atomic_t get_frame;

private:

	ImageProc();
	int svc();

	~ImageProc();

	void PutData (const std::vector<uchar> & encoded);

public:
	int GetData (char * data);
	int GetNextFrame();




};

typedef ACE_Singleton<ImageProc, ACE_SYNCH_MUTEX> TheImageProc;

#endif /* SRC_IMAGEPROC_H_ */
