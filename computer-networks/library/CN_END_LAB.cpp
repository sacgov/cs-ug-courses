HEADER FILES
--------------------------------------------------------------------------------------------------------------------------------
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

/**
 This function is used to send file descriptor over Unix domain socket
 You can use this function with file descriptor return
 by any one of below functions
 1 .  socketpair();
 2 .  socket(AF_UNIX,...);
 3 .  socket(AF_LOCAL,...);
 @param socket file_descriptor_of_sender
 @param fd_to_send
*/
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

 /**
 This function is used to recv file descriptor over Unix domain socket
 You can use this function with a file descriptor return
 by any one of below functions
 1 .  socketpair();
 2 .  socket(AF_UNIX,...);
 3 .  socket(AF_LOCAL,...);
 @param socket file_descriptor_of_sender
 @return recv_fd
*/

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

void print_boundary(){
	int i;

	printf("\n");

	for(i=0;i<20;i++)
	printf(" ");

	for(i=0;i<17;i++)
	printf("_");

	printf("\n");

	for(i=0;i<20;i++)
	printf(" ");
}
void print_data(int num,int fact,int extra){
	printf("%d",num);

	int count=0;
	int i;
	if(num!=0)
	while(num/fact==0)
	{
		fact/=10;
		count++;
	}

	else
	while(fact!=1)
	{
		fact=fact/10;
		printf(" ");
	}

	for(i=0;i<count;i++)
	printf(" ");


	for(i=0;i<extra;i++)
	printf(" ");

	printf("|");
}
void print_ip(struct sockaddr_in s){
	char *ip_addr;
	int n;

	ip_addr=inet_ntoa(s.sin_addr);
	n=strlen(ip_addr);
	printf("%s",ip_addr);
	int i;
	for(i=0;i<15-n;i++)
	printf(" ");
	printf("|");
}
void print_iphdr(struct iphdr *ip){
	print_boundary();
	printf("|");

	print_data(ip->version,1,0);

	print_data(ip->ihl,10,0);

	print_data(ip->tos,100,0);

	print_data(ntohs(ip->tot_len),10000,1);

	print_boundary();
	printf("|");

	print_data(ip->id,10000,3);

	print_data(ip->frag_off,10000,1);

	print_boundary();
	printf("|");

	print_data(ip->ttl,100,1);

	print_data(ip->protocol,100,0);

	print_data(ip->check,10000,1);

	print_boundary();
	printf("|");

	struct sockaddr_in s;

	s.sin_addr.s_addr=ip->saddr;
	print_ip(s);

	print_boundary();
	printf("|");

	s.sin_addr.s_addr=ip->daddr;
	print_ip(s);

	print_boundary();
	printf("\n\n");
}


void print_udphdr(struct udphdr* udp){
	print_boundary();
	printf("|");

	print_data(ntohs(udp->source),10000,2);

	print_data(ntohs(udp->dest),10000,2);

	print_boundary();
	printf("|");


	print_data(ntohs(udp->len),10000,2);

	print_data(udp->check,10000,2);

	print_boundary();
	printf("\n\n");
}
----------------------------------------------------------------------------------------

        CONNECTION ORIENTED SERVER	( usage -:  "./a.out port_no")
        TCP socket
        1. Creation
        2. Binding
        3. Listen
        4. Accept

---------------------------------------------------------------------------------------------------------------------------------
int main(int argc,char *argv[ ]){
	if(argc!=2)
	printf("\n usage ./a.out port_no");

	int sfd;
	struct sockaddr_in serv_addr,cli_addr;
	socklen_t cli_len;
	int port_no=atoi(argv[1]);
    /**
        Create tcp socket using given parameters
    */
	if((sfd = socket(AF_INET,SOCK_STREAM,0))==-1)
	perror("\n socket ");
	else printf("\n socket created successfully");

	bzero(&serv_addr,sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
    /**
        Bind created socket to an interface
    */
	if(bind(sfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))==-1)
	perror("\n bind : ");
	else printf("\n bind successful ");

    /**
        Listen for incoming connection
    */
	listen(sfd,10);

	int nsfd;
	/**
        Accept connection if any one requested over this port and ip address
	*/
	if((nsfd = accept(sfd , (struct sockaddr *)&cli_addr , &cli_len))==-1)
	perror("\n accept ");
	else printf("\n accept successful");
	...

}
---------------------------------------------------------------------------------
		          CONNECTION ORIENTED CLIENT( usage -:  "./a.out port_no")
		            TCP socket
                    1. Creation
                    2. Connect to server
---------------------------------------------------------------------------------------------------------------------------------
int main(){
	if(argc!=2)
	printf("\n usage ./a.out port_no");

	int sfd;
	struct sockaddr_in serv_addr;
	int port_no=atoi(argv[1]);

	bzero(&serv_addr,sizeof(serv_addr));
    /**
        Create tcp socket using given parameters
    */
	if((sfd = socket(AF_INET , SOCK_STREAM , 0))==-1)
	perror("\n socket");
	else printf("\n socket created successfully\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
    /**
        Connect tcp socket using given parameters
    */
	if(connect(sfd , (struct sockaddr *)&serv_addr , sizeof(serv_addr))==-1)
	perror("\n connect : ");
	else printf("\nconnect succesful");
    ...
}
---------------------------------------------------------------------------------
    CONNECTION LESS SERVER	( usage -:  "./a.out port_no")
            UDP socket
            1. Creation
            2. Binding
---------------------------------------------------------------------------------------------------------------------------------
int main(){
	if(argc!=2)
	printf("\n usage ./a.out port_no");

	int sfd;
	struct sockaddr_in serv_addr,cli_addr;
	socklen_t cli_len;
	int port_no=atoi(argv[1]);

	if((sfd = socket(AF_INET,SOCK_DGRAM,0))==-1)
	perror("\n socket ");
	else printf("\n socket created successfully");

	bzero(&serv_addr,sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))==-1)
	perror("\n bind : ");
	else printf("\n bind successful ");
	...
}
-------------------------------------------------------------------------------------
		          CONNECTION LESS CLIENT	( usage -:  "./a.out port_no")
                    UDP socket
                    1. Creation
---------------------------------------------------------------------------------------------------------------------------------
int main(){
    if(argc!=2)
	printf("\n usage ./a.out port_no");

	int sfd;
	struct sockaddr_in serv_addr;
	int port_no=atoi(argv[1]);

	bzero(&serv_addr,sizeof(serv_addr));

	if((sfd = socket(AF_INET , SOCK_STREAM , 0))==-1)
	perror("\n socket");
	else printf("\n socket created successfully\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port_no);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	...
}
------------------------------------------------------------------------
        UNIX domain SOCKET CONNECTION ORIENTED SERVER	( usage -:  "./a.out")
        1. Creation
        2. Binding
        3. Listen
        4. Accept
---------------------------------------------------------------------------------------------------------------------------------
#define ADDRESS  "mysocket"
int main(){
	int  usfd;
	struct sockaddr_un userv_addr,ucli_addr;
  	int userv_len,ucli_len;

	usfd = socket(AF_UNIX , SOCK_STREAM , 0);
	perror("socket");

  	bzero(&userv_addr,sizeof(userv_addr));

  	userv_addr.sun_family = AF_UNIX;
	strcpy(userv_addr.sun_path, ADDRESS);
	unlink(ADDRESS);
	userv_len = sizeof(userv_addr);

	if(bind(usfd, (struct sockaddr *)&userv_addr, userv_len)==-1)
	perror("server: bind");

	listen(usfd, 5);

	ucli_len=sizeof(ucli_addr);

	int nusfd;
	nusfd=accept(usfd, (struct sockaddr *)&ucli_addr, &ucli_len);
	...
}
---------------------------------------------------------------------------------
    UNIX domain SOCKET CONNECTION ORIENTED CLIENT	( usage -:  "./a.out")
        1. Creation
        2. Connect
---------------------------------------------------------------------------------------------------------------------------------
#define ADDRESS     "mysocket"
int main(){
    int usfd;
    struct sockaddr_un serv_addr;
    int serv_len,cli_len;

    usfd = socket(AF_UNIX, SOCK_STREAM, 0);

    if(usfd==-1)
    perror("\nsocket  ");

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, ADDRESS);

    serv_len = sizeof(serv_addr);

    if(connect(usfd,(struct sockaddr *)&serv_addr,serv_len)==-1)
    perror("\n connect ");

    else printf("\nconnect succesful");
    ...
}
-----------------------------------------------------------------------------------------
    RAW SOCKET SENDER  including only ip header you can include tcp and udp header as well	( usage -:  "./a.out" in super mode)
------------------------------------------------------------------------------------------------------------------------------------------
#define DEST "127.0.0.1"
#define SOURCE "127.0.0.1"

int main(void)
{

	int sfd;
	struct sockaddr_in daddr,saddr;
	char packet[50];

	/* point the iphdr to the beginning of the packet */
	struct iphdr *ip = (struct iphdr *)packet;

	if ((sfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
		perror("error:");
		exit(EXIT_FAILURE);
	}

	int one=1;
	const int *val=&one;
	setsockopt(sfd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one));
	perror("setsockopt ");

	daddr.sin_family = AF_INET;
	daddr.sin_port = 0; /* not needed in SOCK_RAW */
	inet_pton(AF_INET, DEST, (struct in_addr *)&daddr.sin_addr.s_addr);
	memset(daddr.sin_zero, 0, sizeof(daddr.sin_zero));

	saddr.sin_family = AF_INET;
	saddr.sin_port = 0; /* not needed in SOCK_RAW */
	inet_pton(AF_INET, SOURCE, (struct in_addr *)&saddr.sin_addr.s_addr);
	memset(saddr.sin_zero, 0, sizeof(saddr.sin_zero));


	ip->ihl = 5;
	ip->version = 4;
	ip->tos = 0;
	ip->tot_len = htons(40);	/* 16 byte value */
	ip->frag_off = 0;		/* no fragment */
	ip->ttl = 64;			/* default value */
	ip->protocol = IPPROTO_RAW;	/* protocol at L4 */
	ip->check = 0;			/* not needed in iphdr */
	ip->saddr = daddr.sin_addr.s_addr;
	ip->daddr = daddr.sin_addr.s_addr;

	while(1)
	{
		scanf("%s",packet+sizeof(struct iphdr));
		sendto(sfd, (char *)packet, sizeof(packet), 0, (struct sockaddr *)&daddr, (socklen_t)sizeof(daddr));
	}
}

----------------------------------------------------------------------------------

           RAW SOCKET RECIEVER
         ( usage -:  "./a.out" in super mode)
---------------------------------------------------------------------------------------------------------------------------------
int main(void)
{
	int sfd;
	struct sockaddr_in saddr;
	char packet[50];
	struct iphdr *ip = (struct iphdr *)packet;

	if ((sfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0)
	{
		perror("error:");
		exit(EXIT_FAILURE);
	}

	memset(packet, 0, sizeof(packet));
	int fromlen = sizeof(saddr);

	while(1)
	{
		recvfrom(sfd, (char *)&packet, sizeof(packet), 0,(struct sockaddr *)&saddr, &fromlen);
		printf("%s\n",packet+sizeof(struct iphdr));
	}
}

----------------------------------------------------------------------------

    Pcap library helper function(s)
    To compile use  -lpcap
    e.g. gcc sniff.c -o sniff -lpcap
---------------------------------------------------------------------------------------------------------------------------------
/**
    This function is called by pcap_loop(...) function
    Whenever a packet is captured by pcap session  then it calls callback function
*/
void my_callback(u_char *args,const struct pcap_pkthdr* pkthdr,const u_char*packet){
    struct ether_header *eptr;  /* net/ethernet.h */

    /* lets start with the ether header... */
    eptr = (struct ether_header *) packet;

    fprintf(stdout,"ethernet header source: %s\n"
            ,ether_ntoa((const struct ether_addr *)&eptr->ether_shost));
    fprintf(stdout," destination: %s\n "
            ,ether_ntoa((const struct ether_addr *)&eptr->ether_dhost));

    /* check to see if we have an ip packet */
    if (ntohs (eptr->ether_type) == ETHERTYPE_IP)
    {
        fprintf(stdout,"(IP)\n");
        struct iphdr *ip = (struct iphdr *)(packet+sizeof(struct ether_header));
	printf("\nip header is  - \n");
	print_iphdr(ip); 		//print your ip header here
					//---------------------------


	if(ip->protocol==IPPROTO_UDP)
	{
		struct udphdr *udp = (struct udphdr *)(packet+sizeof(struct ether_header)+sizeof(struct iphdr));
		printf("\nudp header is - \n");
		print_udphdr(udp);	// print your udp header here
					//-----------------------------
	}


	if(ip->protocol==IPPROTO_TCP)
	{
		struct tcphdr *tcp = (struct tcphdr *)(packet+sizeof(struct ether_header)+sizeof(struct iphdr));
		printf("\ntcp header is - \n");
		//print_tcphdr(tcp);	// print your tcp header here
					//-----------------------------
	}

    }else  if (ntohs (eptr->ether_type) == ETHERTYPE_ARP)
    {
        fprintf(stdout,"(ARP)\n");
    }else  if (ntohs (eptr->ether_type) == ETHERTYPE_REVARP)
    {
        fprintf(stdout,"(RARP)\n");
    }else {
        fprintf(stdout,"(?)");
      //  exit(1);
    }

}

/**
    libpcap main program
    It takes one argument
    1.  Number of packets
*/
int main(int argc,char **argv){
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* descr;
    bpf_u_int32 maskp;          /* subnet mask               */
    bpf_u_int32 netp;           /* ip                        */
    u_char* args = NULL;

    /* Options must be passed in as a string because I am lazy */
    if(argc < 2){
        fprintf(stdout,"Usage: %s numpackets \"options\"\n",argv[0]);
        return 0;
    }

    /* grab a device to peak into... */
    dev = pcap_lookupdev(errbuf);
    if(dev == NULL)
    { printf("%s\n",errbuf); exit(1); }

    /* ask pcap for the network address and mask of the device */
    pcap_lookupnet(dev,&netp,&maskp,errbuf);

    /* open device for reading. NOTE: defaulting to
     * promiscuous mode*/
    descr = pcap_open_live(dev,BUFSIZ,1,-1,errbuf);
    if(descr == NULL)
    { printf("pcap_open_live(): %s\n",errbuf); exit(1); }

    /* ... and loop */

    pcap_loop(descr,atoi(argv[1]),my_callback,args);

    fprintf(stdout,"\nfinished\n");
    return 0;
}
/***
    This program is same  as above but it includes filter like arp , tcp packet e.t.c
*/
int main(){
        char dev[]="eth0";/**Device name on which packet will be sniffed*/
        char errbuf[PCAP_ERRBUF_SIZE];/**Error buffer*/
        struct bpf_program  fp;/**compiled program*/
        char filter[]="arp dst net 172.30.100.195"; /**Filter expression*/
        bpf_u_int32  mask;/**our netmask*/
        bpf_u_int32 net;/**our IP address*/
        int optimize=0;/** FIlter expressions has to be optimized or not ?*/
        const u_char *packet;
        int NoofPacket = -1 ;/** -1 signifies there is no limit */
        pcap_t* phandle; /**Pcap session handler*/

        if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
             fprintf(stderr, "Can't get netmask for device %s\n", dev);
             net = 0;
             mask = 0;
             return 1;
        }
		int on = 1;/**promiscuous mode*/
		phandle = pcap_open_live(dev, BUFSIZ,on,-1, errbuf);
        if (phandle == NULL) {
             fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
             return(2);
        }
        printf("Device : %s opened for sniffing\n",dev);

        if (pcap_compile(phandle, &fp, filter,optimize, net) == -1) {
             fprintf(stderr, "Couldn't parse filter %s: %s\n", filter, pcap_geterr(phandle));
             return(3);
        }
        printf("Program compiled with filter : %s\n",filter);


        if (pcap_setfilter(phandle, &fp) == -1) {
             fprintf(stderr, "Couldn't install filter %s: %s\n", filter, pcap_geterr(phandle));
             return(4);
        }
        printf("Program installed with filter : %s\n",filter);

        if ( pcap_loop(phandle,NoofPacket,my_callback,NULL)==-1){
            fprintf(stderr, "pcap loop failed : %s\n",pcap_geterr(phandle));
             return(4);
        }
		return(0);
}
---------------------------------------------------------------------------
        Create shareMemory with given key and size
        1. If key is not specfied then it will ask OS
        2. It uses key to create shareMemory
        @param size : size of shareMemory
        @param key  : shareMemory identifier
---------------------------------------------------------------------------
void* shareMemory(size_t size ,int key = -1){
    int shmid;
    if(key==-1){
      shmid = shmget(IPC_PRIVATE,size,IPC_CREAT|0666);
    }
    else{
        shmid = shmget(key,size,IPC_CREAT|0666);
    }
    if(shmid < 0){
    	err_quit("shareMemory()");
    }
    return shmat(shmid,(void *)0,  0);
}
