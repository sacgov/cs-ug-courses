#!/bin/bash
gcc Internet_main_server.c -o ims
gcc internet_client.c -o client
gcc service.c -o s1
gcc service.c -o s2
gcc service.c -o s3
gcc pollserver.c -o pollserver
echo "Compiled Successful"
echo "run clients with args 6666 or 7777 ,8888"
./ims