#!/bin/bash
gcc -c -fPIC *.c
gcc -shared -fPIC *.o -o liball.so
