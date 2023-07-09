#ifndef _FILE_SOURCE_H
#define _FILE_SOURCE_H

#include "stream_source.h"
#include <string>
#include <vector>



struct file_info_t {
	const std::string pathname;
	const int width;
	const int height;
    const std::string pattern;
    const int minIndex;
    const int maxIndex;
};

//static const source_info_t source_info = {"/home/mecasys/extension/movie_clips/sMoky.avi", 320, 240};
static const file_info_t fileInfo = {"/home/ubuntu/MyProjects/samples/jpegs", 1920, 1080, "frame%06d.jpg", 0, 129};

class FileSource : public StreamSource {

public:



private:
	
	bool quit;
	pthread_t tid;


public:
	const int SLEEP_IN_US = 40000;

	struct info_struct {
		bool * quit;
		CStreamer * streamer;
        char *data;
	} info;

	FileSource(CStreamer * streamer,int streamID);
	~FileSource();
	static void * stream_generator(void * arg);
    static void GetNext(char* data, int& len);
    static int get_filesize(std::string filename);
    static void get_data(char * data, int & len, std::string filename);

};

#endif
