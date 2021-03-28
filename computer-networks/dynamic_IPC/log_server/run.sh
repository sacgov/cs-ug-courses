#!/bin/bash
gcc log_server.c
rm log
touch log
gcc service_mss.c -o s1
gcc service_mss.c -o s2
gcc service_mss.c -o s3
gcc client_mss.c -o client
gnome-terminal -e "./client cl1"
gnome-terminal -e "./client cl2"
gnome-terminal -e "./client cl3"
./a.out

