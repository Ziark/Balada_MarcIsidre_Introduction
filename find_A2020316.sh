#Defining a bash script
#!/bin/bash

#compiling the .c runing the Makefile
make all

#Executing result with different arguments
./find_A2020316 "aa" "aaaaaa"
./find_A2020316 "ab" "abcabc"
./find_A2020316 "cc" "aaaaaa"
./find_A2020316 "c" "aaaaac"
./find_A2020316 "." "aaaa.a"
./find_A2020316 "ab" "aababa"
./find_A2020316 "" "aaaaaa"
./find_A2020316 "xyz" "xyzxyz"
