#!/bin/sh
# remove prvious sockpaths
rm /tmp/sockpath*
gcc -c utils.c -o utils.o
gcc utils.o tcserver.c -o tcserver -lpthread
gcc -g utils.o cmultiplex.c -o cmx -lpthread
gcc utils.o smultiplex.c -o smx -lpthread
gcc utils.o emultiplex.c -o emx -lpthread
gcc utils.o client.c -o client -lpthread
rm utils.o
echo './tcserver ./cmx ./smx ./emx ./client 8001 ./client 8002 ./client 8003'
echo 'compiled'
