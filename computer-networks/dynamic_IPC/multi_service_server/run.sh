#!/bin/bash
gcc service_coord.c
gcc service_mss.c -o s1
gcc service_mss.c -o s2
gcc service_mss.c -o s3
gcc client_mss.c -o client
gnome-terminal -e "./client cl1"
gnome-terminal -e "./client cl2"
gnome-terminal -e "./client cl3"
./a.out

