#!/bin/sh

gcc moniter.c -o moniter
gcc raw_client.c -o client
gcc raw_server.c -o server

echo '**************Compiled Successfully*********************'
