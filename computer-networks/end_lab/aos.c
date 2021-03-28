#include <time.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/un.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/if_ether.h> 
#include <net/ethernet.h>
#include <netinet/ether.h> 
#include <netinet/udp.h>
#include <poll.h>

#define MAX 100

int send_fd(int socket, int fd_to_send){
  struct msghdr socket_message;
  struct iovec io_vector[1];
  struct cmsghdr *control_message = NULL;
  char message_buffer[1];
  /* storage space needed for an ancillary element with a paylod of length is CMSG_SPACE(sizeof(length)) */
  char ancillary_element_buffer[CMSG_SPACE(sizeof(int))];
  int available_ancillary_element_buffer_space;

  /* at least one vector of one byte must be sent */
  message_buffer[0] = 'F';
  io_vector[0].iov_base = message_buffer;
  io_vector[0].iov_len = 1;

  /* initialize socket message */
  memset(&socket_message, 0, sizeof(struct msghdr));
  socket_message.msg_iov = io_vector;
  socket_message.msg_iovlen = 1;

  /* provide space for the ancillary data */
  available_ancillary_element_buffer_space = CMSG_SPACE(sizeof(int));
  memset(ancillary_element_buffer, 0, available_ancillary_element_buffer_space);
  socket_message.msg_control = ancillary_element_buffer;
  socket_message.msg_controllen = available_ancillary_element_buffer_space;

  /* initialize a single ancillary data element for fd passing */
  control_message = CMSG_FIRSTHDR(&socket_message);
  control_message->cmsg_level = SOL_SOCKET;
  control_message->cmsg_type = SCM_RIGHTS;
  control_message->cmsg_len = CMSG_LEN(sizeof(int));
  *((int *) CMSG_DATA(control_message)) = fd_to_send;

  return sendmsg(socket, &socket_message, 0);
 }
int recv_fd(int socket){
  int sent_fd, available_ancillary_element_buffer_space;
  struct msghdr socket_message;
  struct iovec io_vector[1];
  struct cmsghdr *control_message = NULL;
  char message_buffer[1];
  char ancillary_element_buffer[CMSG_SPACE(sizeof(int))];

  /* start clean */
  memset(&socket_message, 0, sizeof(struct msghdr));
  memset(ancillary_element_buffer, 0, CMSG_SPACE(sizeof(int)));

  /* setup a place to fill in message contents */
  io_vector[0].iov_base = message_buffer;
  io_vector[0].iov_len = 1;
  socket_message.msg_iov = io_vector;
  socket_message.msg_iovlen = 1;

  /* provide space for the ancillary data */
  socket_message.msg_control = ancillary_element_buffer;
  socket_message.msg_controllen = CMSG_SPACE(sizeof(int));

  if(recvmsg(socket, &socket_message, MSG_CMSG_CLOEXEC) < 0)
   return -1;

  if(message_buffer[0] != 'F')
  {
   /* this did not originate from the above function */
   return -1;
  }

  if((socket_message.msg_flags & MSG_CTRUNC) == MSG_CTRUNC)
  {
   /* we did not provide enough space for the ancillary element array */
   return -1;
  }

  /* iterate ancillary elements */
   for(control_message = CMSG_FIRSTHDR(&socket_message);
       control_message != NULL;
       control_message = CMSG_NXTHDR(&socket_message, control_message))
  {
   if( (control_message->cmsg_level == SOL_SOCKET) &&
       (control_message->cmsg_type == SCM_RIGHTS) )
   {
    sent_fd = *((int *) CMSG_DATA(control_message));
    return sent_fd;
   }
  }

  return -1;
 }

int main()
{
	int i;
	int  usfd[3];
	struct sockaddr_un userv_addr[3],ucli_addr[3];
  	int userv_len,ucli_len;
  	int nusfd[3];
  	char * uadress;
  	for(i = 0 ;i<3;i++)
	{
		if(i==0)
		{
			uadress= "mysocket1";
		}
		if(i==1)
		{
			uadress= "mysocket2";
		}
		if(i==2)
		{
			uadress= "mysocket3";
		}
		usfd[i] = socket(AF_UNIX , SOCK_STREAM , 0);
		perror("socket");
		bzero(&userv_addr[i],sizeof(userv_addr[i]));
		userv_addr[i].sun_family = AF_UNIX;
		strcpy(userv_addr[i].sun_path, uadress);
		unlink(uadress);
		userv_len = sizeof(userv_addr[i]);

		if(bind(usfd[i], (struct sockaddr *)&userv_addr[i], userv_len)==-1)
			perror("server: bind");

		listen(usfd[i], 5);

		ucli_len=sizeof(ucli_addr[i]);

		nusfd[i]=accept(usfd[i], (struct sockaddr *)&ucli_addr[i], &ucli_len);
		printf("server %d is connected \n",i);
		//break;
	}
  	
	struct sockaddr_in server_addr[3];
	//client address
	struct sockaddr_storage client_addr;
	//length of client
	socklen_t client_len = sizeof(client_addr);

	client_len = sizeof(client_addr);
	char buffer[1024];
	//Creates a socket....
	//define sfd and ports for three sfds and nsfd for client
	int sfd[3] , port[3] , max = 0 , nsfd ;
	struct pollfd pfd[4];
	for(i=0;i<3;i++)
	{
			//af_inet and sockstream of pv4 domain
		sfd[i] = socket(AF_INET , SOCK_STREAM , 0);
	}
		//assigning arbitrary ports to three services whose object files are creted already
	port[0] = 8001;
	port[1] = 8002;
	port[2] = 8003;
	for(i=0;i<3;i++)
	{
		server_addr[i].sin_addr.s_addr = INADDR_ANY;
		server_addr[i].sin_port = htons(port[i]); //to get network byte order
		server_addr[i].sin_family = AF_INET;
		memset(server_addr[i].sin_zero,'\0',sizeof(server_addr[i].sin_zero));
		bind(sfd[i] ,(struct sockaddr *) &server_addr[i] , sizeof(server_addr[i]));
		listen(sfd[i] , 5); //max listen on 5
		pfd[i].fd = sfd[i];
		pfd[i].events = POLLIN; 
	}



	//raw socket part
	struct sockaddr_in rs_addr, rd_addr;
	struct sockaddr_in raddr; int rrsfd, rlen; char rbuffer2[100];
    rrsfd = socket(AF_INET, SOCK_RAW, 146);
    if(rrsfd < 0) {
        perror("socket() ");
        exit(1);
    }
    memset((char *)&raddr, 0, sizeof raddr);
    raddr.sin_family = AF_INET;
    raddr.sin_port = 9001;
    raddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(rrsfd, (struct sockaddr*)&raddr, sizeof raddr) < 0) {
        perror("bind() ");
        exit(2);
    }
    struct iphdr * iph;

    pfd[3].fd = rrsfd;
    pfd[3].events = POLLIN;

	pollhere:
	poll(pfd,4,0);
	if(pfd[3].revents & POLLIN)
	{
		printf("Raw sock request\n");
		int j = 0;
		for(j=0;j<2;j++){
		rlen = sizeof(raddr);
        if(recvfrom(rrsfd, rbuffer2, MAX, 0, (struct sockaddr *)&raddr, &rlen) < 0) {
            perror("sendto() ");
        }
	printf("Packet Count %d \n", j);
    iph = (struct iphdr *) rbuffer2;
	memset((char *)&rs_addr, 0, sizeof rs_addr);
	memset((char *)&rd_addr, 0, sizeof rd_addr);
	rs_addr.sin_addr.s_addr = iph->saddr;
	rd_addr.sin_addr.s_addr = iph->daddr;
	int iphdrlen = iph->ihl*4;
	printf("------------- IP Header ------------\n");
	printf("|%4d|%4d|%8d|%16d|\n", (unsigned int)iph->version, (unsigned int)iph->ihl, (unsigned int)iph->tos, ntohs(iph->tot_len));
	printf("------------------------------------\n");
	printf("|%16d|R|D|M|%13d|\n", ntohs(iph->id), (unsigned int)iph->frag_off);
	printf("------------------------------------\n");
	printf("|%8d|%8d|%16d|\n", (unsigned int)iph->ttl, (unsigned int)iph->protocol, ntohs(iph->check));
	printf("------------------------------------\n");
	printf("%s\n", inet_ntoa(rs_addr.sin_addr));
	printf("------------------------------------\n");
	printf("%s\n", inet_ntoa(rd_addr.sin_addr));
	printf("------------------------------------\n");
	char buf[200];
	strcpy(buf, rbuffer2+iphdrlen);
	printf("\tMessage\n %s\n", buf);
        sleep(2);
	}}
	for(i=0;i<3;i++)
	{
		if(pfd[i].revents & POLLIN)
		{
			int nsfd = accept(sfd[i] , (struct sockaddr *)&client_addr , &client_len);
			printf("CONNECTION ESTABLISHED at %d\n",port[i]);
			send_fd(nusfd[i],nsfd);
		}
	}
	goto pollhere;
}