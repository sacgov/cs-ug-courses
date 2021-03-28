#!/bin/bash
gcc Echo_Server.c -o s
gcc Echo_Client.c -o c
gnome-terminal -e "./c"
./s