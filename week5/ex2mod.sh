#!/usr/bin/env bash

for i in {1..88}
do
        if ln ex2.txt ex2.txt.lock; then
		number=$(tail -1 "ex2.txt")
		echo "$(($number+1))" >> "ex2.txt"
		rm ex2.txt.lock;
	fi
done
