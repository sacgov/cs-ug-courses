#!/bin/bash
rm log
touch log
gcc log_server.c
gcc service_mss.c -o s1
gcc client_mss.c -o client
./a.out

