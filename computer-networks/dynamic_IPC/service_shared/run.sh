#!/bin/bash
g++ service_coord.c
g++ service_mss.c -o service
gcc client_mss.c -o client
gnome-terminal -e "./service s0 0"
gnome-terminal -e "./service s1 1"
gnome-terminal -e "./service s2 2"
./a.out

