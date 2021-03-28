#!/bin/sh
gcc group_mss.c -o ser
gcc -pthread group_client.c -o client
gcc group_runner.c -o s0
gcc group_runner.c -o s2
gcc group_runner.c -o s1
echo "compiled successfully !"
echo "Groups are s0 s1 s2"