run run.sh first to complete the setup
then log_server starts running
three server oject files s1 s2 s3 are created
server instances have to created before hand to know sevice names and cannot be dynamic
client writed its names though famous fifo
server polls it and created the fifos and stores the names of the clients 
it polls for requests from server
it then exec the services created before and sends fifo and message to be processed as input args in exec
run extra clients as in run.sh