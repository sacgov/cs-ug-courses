

Sniffer catches both incoming and outgoing packets for
incoming packet only repalce ETH_P_ALL to ETH_P_IP.

Problem Statment:
	Create your own custom network protocol using raw sockets
	with IP Header Include and write a client-server program 
	which agrees on same protocol number (in this case 146). 
	client sends message to server and server displays IP Header and 
	msg in a nice format. Packet sniffer can catch any type of protocol,
	e.g your current client-server program, your web browser packet, mails etc.

	In this program sents packet custom created packets. i.e, client can modify
	IP headers and can change any value except ip->id and ip->checksum.
	
Compile:
./build

Run: (each command in a new terminal )
sudo ./server
sudo ./sniff
sudo ./client

NOTE:
	Here server binded is not binded on any port bcoz its not needed.
