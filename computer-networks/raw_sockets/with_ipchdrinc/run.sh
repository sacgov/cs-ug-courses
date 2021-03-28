#!/bin/sh

gcc moniter.c -o moniter
gcc client.c -o client
gcc server.c -o server

echo 'compiled successfully'
