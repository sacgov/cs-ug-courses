#!/bin/bash
gcc server.c
gcc -pthread client.c -o c1
gnome-terminal -e "./c1 sophia"
gnome-terminal -e "./c1 sachin"
gnome-terminal -e "./c1 pranavi"
./a.out
