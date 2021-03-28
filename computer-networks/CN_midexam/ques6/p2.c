#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc, char * argv[]) {
	int fd = open("fifo", O_WRONLY);
	while(1) {
		write(fd, "frm_pro2", 8);
		sleep(2);
	}
	return 0;
}
