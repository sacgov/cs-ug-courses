#!/bin/bash
g++ server.c 
g++ fifo.c -o fifos
g++ p5.c -o p5
g++ popen.c -o pp
gcc sigsend.c -o sigs
gnome-terminal -e "./fifos"
gnome-terminal -e "./p5"
./a.out
