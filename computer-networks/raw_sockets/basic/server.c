#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/if_ether.h>
#include <netdb.h>

#define MAX 100
int total = 0;

int main(int argc, char const *argv[]) {
    struct sockaddr_in s_addr, d_addr;
    struct sockaddr_in addr; int rsfd, n, len; char buffer[MAX], buf[MAX];
    rsfd = socket(AF_INET, SOCK_RAW, 146);
    if(rsfd < 0) {
        perror("socket() ");
        exit(1);
    }
    memset((char *)&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = 8001;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(bind(rsfd, (struct sockaddr*)&addr, sizeof addr) < 0) {
        perror("bind() ");
        exit(2);
    }
    struct iphdr * iph; unsigned int iphdrlen;
    while(1) {
        len = sizeof(addr);
        if(recvfrom(rsfd, buffer, MAX, 0, (struct sockaddr *)&addr, &len) < 0) {
            perror("sendto() ");
        }
	printf("Packet Count %d \n\n", ++total);
    iph = (struct iphdr *) buffer;
	memset((char *)&s_addr, 0, sizeof s_addr);
	memset((char *)&d_addr, 0, sizeof d_addr);
	s_addr.sin_addr.s_addr = iph->saddr;
	d_addr.sin_addr.s_addr = iph->daddr;
	iphdrlen = iph->ihl*4;
	printf("------------- IP Header ------------\n");
	printf("|%4d|%4d|%8d|%16d|\n", (unsigned int)iph->version, (unsigned int)iph->ihl, (unsigned int)iph->tos, ntohs(iph->tot_len));
	printf("------------------------------------\n");
	printf("|%16d|R|D|M|%13d|\n", ntohs(iph->id), (unsigned int)iph->frag_off);
	printf("------------------------------------\n");
	printf("|%8d|%8d|%16d|\n", (unsigned int)iph->ttl, (unsigned int)iph->protocol, ntohs(iph->check));
	printf("------------------------------------\n");
	printf("%s\n", inet_ntoa(s_addr.sin_addr));
	printf("------------------------------------\n");
	printf("%s\n", inet_ntoa(d_addr.sin_addr));
	printf("------------------------------------\n");
	strcpy(buf, buffer+iphdrlen);
	printf("\tMessage\n %s\n", buf);
        sleep(2);
    }
    return 0;
}
