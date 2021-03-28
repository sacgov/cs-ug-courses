#!/bin/bash
g++ service_coord.c
g++ service_mss.c -o ser
gcc client_mss.c -o client
./a.out

