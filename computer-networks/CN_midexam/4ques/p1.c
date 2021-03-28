#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>
#include <string.h>

int main() 
{
	FILE * f; struct pollfd pfds[5]; int i, flag; char str[9];
	struct pollfd inp[1];
	inp[0].fd = 0;
	inp[0].events = POLLIN;
	f = popen("./p2", "r");
	pfds[0].fd = fileno(f);
	f = popen("./p3", "r");
	pfds[1].fd = fileno(f);
	f = popen("./p4", "r");
	pfds[2].fd = fileno(f);
	f = popen("./p5", "r");
	pfds[3].fd = fileno(f);
	f = popen("./p6", "w");
	int p6fd = fileno(f);

	for (i = 0; i < 4; ++i) 
	{
		pfds[i].events = POLLIN;
	}
	sleep(3);
	while(1) 
	{
		//printf("polling\n");
		poll(pfds, 4, 5000);
		int flag = 0;
		for (i = 0; i < 4; ++i){
			if (pfds[i].revents & POLLIN) 
			{
				flag =1;
				memset(str, 0, 9);
				read(pfds[i].fd, str, 9);
				write(p6fd,str,9);
				sleep(1);
				pfds[i].fd = -1;
			}
		}
		if(flag)
			continue;
		else
		{
			printf("Polling input \n");
			poll(inp,1,1000);
			if(inp[0].revents & POLLIN)
			{
				memset(str, 0, 9);
				read(0, str, 9);
				printf("%s\n", str);
				sleep(0.5);
			}
		}


	}
	return 0;
}