#!/bin/sh
man fgets > t1.txt
touch t2.txt
gcc FTPclient.c -o cli
gcc FTPserver.c -o ser -lpthread
echo "run ./cli 9500 t1.txt t2.txt"
gnome-terminal&disown
./ser
