#!/bin/bash
gcc service_coord.c
gcc service_mss.c -o s1
gcc client_mss.c -o client
./a.out

