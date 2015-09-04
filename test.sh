#! /bin/bash

echo hello cubieez!  Running C program now.....

#seems this is required every reboot... :(
modprobe gpio-sunxi

#running the c program...
./test

