#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
	int i;
	for(i=0; i<5; i++){
		write(0, "SACHINGOVIND", 10);
		sleep(1);
	}
	return 0;
}
