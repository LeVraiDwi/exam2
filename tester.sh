#!/bin/sh

gcc -D BUFFER_SIZE=$1 get_next_line.c get_next_line.h main.c -o get_next_line
./get_next_line < $2 > test
diff $2 test > diff
cat diff
