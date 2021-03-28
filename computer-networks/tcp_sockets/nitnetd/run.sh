#!/bin/sh
gcc nit_mss.c -o ser
gcc nit_client.c -o client
gcc nit_service.c -o s0
gcc nit_service.c -o s2
gcc nit_service.c -o s1
echo "compiled successfully !"