#!/bin/sh
# remove prvious sockpaths
rm /tmp/sockpath*
gcc -c utils.c -o utils.o
gcc utils.o server.c -o server -lpthread
gcc utils.o service1.c -o service1 -lpthread
gcc utils.o service2.c -o service2 -lpthread
gcc utils.o service3.c -o service3 -lpthread
gcc utils.o client.c -o client
rm utils.o
echo './server ./client 8001 ./client 8002 ./client 8003'
echo 'compiled'
