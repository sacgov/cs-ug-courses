#!/bin/sh
gcc nit_mss.c -o ser
gcc nit_client.c -o client
gcc -pthread nit_service.c  -o s0
gcc -pthread nit_service.c  -o s2
gcc -pthread nit_service.c  -o s1
echo "compiled successfully !"