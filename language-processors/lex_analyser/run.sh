#!/bin/bash 
flex flex_basic1.l
gcc lex.yy.c -ll
./a.out basic1.txt
