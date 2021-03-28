#!/bin/bash
gcc udpserver.c
gcc udpclient.c -o c1
gnome-terminal -e "./c1"
./a.out

