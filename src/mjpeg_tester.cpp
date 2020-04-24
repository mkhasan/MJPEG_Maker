/*
 * mjpeg_tester.cpp
 *
 *  Created on: Oct 13, 2019
 *      Author: usrc
 */

#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void WriteIntoFile(char * payload, int length) {

   	static int count = 0;
	static std::ofstream ofile("/tmp/foobar.mjpeg", std::ios::binary);
	const int size = 10000;
	if (count < size) {

		try {
			ofile.write(payload, length);
			count ++;
			if (count >= size) {
				ofile.close();
				printf("closed\n");
			}
		}
		catch (...) {
			printf("error \n");
		}
	}
}

void WriteIntoMultipleFiles(char * payload, int length) {

   	static int count = 0;


	const int size = 100;
	char filename[100];
	if (count < size) {

		try {
			sprintf(filename, "/tmp/foobar%04d.jpg", count);
			ofstream ofile(filename, std::ios::binary);
			ofile.write(payload, length);
			count ++;
			ofile.close();
			if (count >= size) {

				printf("done\n");
			}
		}
		catch (...) {
			printf("error \n");
		}
	}
}
