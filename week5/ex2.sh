#!/usr/bin/env bash

for i in {1..88}
do
	number=$(tail -n 1 "ex2.txt")
	echo "$(($number+1))" >> "ex2.txt"
done
