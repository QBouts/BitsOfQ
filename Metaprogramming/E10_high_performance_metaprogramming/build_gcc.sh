#!/bin/bash

file=$1;
compilations=$2;

for ((i=0; i<=$compilations; i++))
do
	g++ -O2 -std=c++20 $file
done
