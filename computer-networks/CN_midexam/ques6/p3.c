/*
 * Helper Process P3
 * connected to server with popen
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFSIZE 1024



int main(int argc, char * argv[]) {
	while(1) {
		printf("p3_hello");
		sleep(3);
	}
	return 0;
}
