#!/bin/sh
gcc -c utils.c -o utils.o
gcc utils.o server.c -o server
gcc utils.o service.c -o service
rm utils.o
echo 'compiled'
echo "./server /tmp/socket target.txt       ./service /tmp/socket"
