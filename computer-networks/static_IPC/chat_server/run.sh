#!/bin/bash
gcc server.c
gcc -pthread c1.c -o c1
gcc -pthread c2.c -o c2
./a.out