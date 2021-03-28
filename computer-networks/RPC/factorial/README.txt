=====================================================
Factorial using Remote Procedure Call
=====================================================

Dependencies: rpcbind
sudo apt-get install rpcbind

problem description:
	client program call procedure (function) of server
	which return the factorial of the number
GENERATE FILES:
	rpcgen -aC fact.x

COMPILE:
	make -f Makefile.fact
	
RUN: (open each command in a new terminal)
	sudo ./fact_server
	sudo ./fact_client localhost

NOTE:
	sace programs in programs.txt as server and client maybe overwritten on changes to fact.x on running rpcgen 
	
