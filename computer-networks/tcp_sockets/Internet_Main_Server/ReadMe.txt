Internet Main Server implementation

run run.sh first to create all prerequisites
the main program implements execs a pollserver which polls on all the transaction
it has three servers 6666 7777 8888 ports ans running s1 s2 s3
child connects to one of these giving port no as an argument
then server execs the service and provides service through a child
run clen.sh to clean