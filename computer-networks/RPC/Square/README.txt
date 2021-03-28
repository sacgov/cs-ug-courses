=====================================================
Square of a Integer using Remote Procedure Call

System: Linux 64bit, sun RPC library installed
=====================================================

Dependencies: rpcbind
sudo apt-get install rpcbind

problem description:
	client program call procedure (function) of server
	program which return square of given integer argument.


$ rpcgen -aC square.x

it will generate these files

square.h square_client.c square_server.c square_clnt.c square_svc.c
square_xdr.c Makefile.square

Now Edit:
these two files -> square_client.c and square_server.c

copy these into programs.txt as these are sometimes overwritten

COMPILE:
	make -f Makefile.add

RUN: (open each command in a new terminal)
	sudo ./add_server
	sudo ./add_client localhost
	
NOTE: 
	cmd line argument for client is hostname of server program

Clean:
	rm *.o square_server square_client
