/*
 * Main Server
 * controls each process
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/select.h>
#include <signal.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define eerror(msg) {printf("%s\n", msg); exit(1);}

int Q[128], front = 0, last=0, nclient=0;
int S[128], top=-1;
int fds[3];

void child_handler() {
	printf("child exited\n");
	int fd = S[top--];
	Q[last++] = fd;
}

void handler() {
	printf("caught signal\n");
	int fd = Q[front++];
	S[++top] = fd;
	// printf("%d\n", fd);
	if(fork() == 0) {
		dup2(fd, 1);
		dup2(fd, 0);
		execl("echoS", "echoS", NULL);
	}
}

void helper() {
	int fd[2];
	fds[0] = 0;
	pipe(fd);
	if(fork() == 0) {
		close(fd[0]);
		while(1) {
			write(fd[1], "pipe_hello", 10);
			sleep(2);
		}
	}
	close(fd[1]);
	fds[1] = fd[0];
	fds[2] = open("fifo", O_RDWR);
	if(fds[2] == -1) eerror("fifo open() error");
}

int main(int argc, char * argv[]) {
	signal(SIGCHLD, child_handler);
	signal(SIGUSR1, handler);
	int port;
	if(argc < 2) 
		eerror("Usage: ./server <port>");
	port = atoi(argv[1]);
	struct sockaddr_in s_addr, c_addr; int cli_len, sfd, nsfd; char buf[BUFSIZE];
	if((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) eerror("socket() error");
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons((u_short)atoi(argv[1]));
	s_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(bind(sfd, (struct sockaddr *) &s_addr, sizeof(s_addr)) < 0) eerror("bind() error");
	if(listen(sfd, 5) < 0) eerror("listen() error");

	helper();
	printf("server started !\n");
	fd_set rfds; int i, j, max;
	while(1) {
		FD_ZERO(&rfds);
		FD_SET(sfd, &rfds);
		max = sfd;
		for(i=0; i<3; i++) {
			FD_SET(fds[i], &rfds);
			if(fds[i] > max)
				max = fds[i];
		}
		if(select(max+1, &rfds, NULL, NULL, NULL) < 0){
			sleep(0.5);
			continue;
		}
		if(FD_ISSET(sfd, &rfds)) {
			cli_len = sizeof(c_addr);
			if((nsfd = accept(sfd, (struct sockaddr *)&c_addr, &cli_len)) < 0)
				eerror("accept() error");
			Q[last++] = nsfd;
		}
		for (i = 0; i < 3; ++i) {
			if(FD_ISSET(fds[i], &rfds)) {
				memset(buf, 0, BUFSIZE);
				read(fds[i], buf, BUFSIZE);
				// printf("%s\n", buf);
				for(j=front ; j<last; j++) {
					write(Q[j], buf, BUFSIZE);
				}
			}
		}
	}
	return 0;
}
