#include "utils.h"
#include "jpeg_writer.h"
#include "file_source.h"
#include <pthread.h>
#include <unistd.h>

#include <assert.h>


using namespace std;
using namespace mjpeg_maker;


FileSource::FileSource(CStreamer * streamer, int streamID)
	: StreamSource(fileInfo.width, fileInfo.width, streamID, streamer, NULL)
	, quit(false), tid(NULL)
{
	
	info.quit = &quit;
	info.streamer = streamer;
    info.data = new char[fileInfo.width*fileInfo.height*3 + 1024];

	int err = pthread_create(&tid, NULL, &stream_generator, (void *) &info);
	if (err != 0)
	{
		stringstream ss;
		ss << "can't create thread :[" << err << "]";
		THROW(RobotException, ss.str().c_str());
	}

	printf("FileSource created \n");

}

FileSource::~FileSource() {

	printf("In FileSource Destructor \n");
	if (tid != NULL && quit == false) {
		quit = true;
		printf("waiting for thread to finish \n");
		pthread_join(tid, NULL);
		printf("done \n");
	}

    delete[] info.data;

}


void * FileSource::stream_generator(void * arg) {

	info_struct *info = (info_struct *) arg;
    
    

	int count = 0;
    int len = 0;
    int h, w, offset;
	while(*(info->quit) == false) {

        
        GetNext(info->data, len);

        if (len > 0 && info->streamer->streamStarted && *(info->quit) == false) {

            JPEG_Writer::GetInfo(info->data, len, w, h, offset);


            //printf("--------------------------------------image len: %d offset: %d, %d \n", len, offset, 0);

            info->streamer->StreamImage(info->data+offset, len-offset, w, h);
        }

	    usleep(40000);

	}


	*(info->quit) = true;


	return NULL;
}



void FileSource::GetNext(char* data, int& len) {
	char filename[255];
    static int index = fileInfo.minIndex;
    

	sprintf(filename, fileInfo.pattern.c_str(), index);
    string fullpath = fileInfo.pathname + string("/") + filename;

    //cout << "full path: " << fullpath << endl;

	get_data(data, len, fullpath);
	if (len < 0) {
		cout <<  "Error in getting data !!!";
	}

    index = (index + 1) % fileInfo.maxIndex;


}

int FileSource::get_filesize(string filename) {
	streampos begin, end;
	ifstream myfile(filename, ios::binary);
	begin = myfile.tellg();
	myfile.seekg(0, ios::end);
	end = myfile.tellg();
	myfile.close();
	return end - begin;
}

void FileSource::get_data(char * data, int & len, string filename) {


	len = -1;

	ifstream myfile(filename, ios::binary);
	if (myfile.is_open()) {
		int size = get_filesize(filename); // myfile.tellg();
		//assert(size <= ImgData::GetBufferSize());
		myfile.seekg(0, ios::beg);
		myfile.read(data, size);
		len = size;

	}

}
