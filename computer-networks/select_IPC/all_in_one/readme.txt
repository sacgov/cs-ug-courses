Date : 04 February 2016 (Thursday)
all in one server
it has a fifo from fifo.c "all" 
user can input messages to it
popens pp.c
it sleeps for 5 seconds before sending its o/p
creates a pipe with child itself writes the data to server
sigsend send the signal to server according to its arg 1 which is pid of server 
open it like ./sigs pid as first argument
the output is redirected to p5.c if sigrcv flag is set to 1
which then ouputs the data in its terminal
run clean.sh to clean
