#include <stdio.h>

int main() {

	char *p;
	printf("size is %d \n", sizeof(p));

	p = new char[132];

	printf("size is now %d", sizeof(p[]));

	delete p;
	return 0;
}
