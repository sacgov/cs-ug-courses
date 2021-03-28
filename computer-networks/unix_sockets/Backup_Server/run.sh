#!/bin/sh
# remove previous sockpaths
rm /tmp/sockpath
gcc -c utils.c -o utils.o
rm -rf tmp/sockpath*
gcc utils.o server.c -o server -lpthread
gcc utils.o backup.c -o backup -lpthread
gcc utils.o client.c -o client
rm utils.o
echo './server ./backup ./client port_no'
gnome-terminal & disown
gnome-terminal & disown
gnome-terminal & disown
gnome-terminal & disown
