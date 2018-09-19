#!/usr/bin/env bash

for i in {1..888}
do
        if ln ex2 ex2.lock; then
		number=$(tail -n "ex2.txt")
		echo "$(($number+1))" >> "ex2.txt"
		rm ex2.lock;
	fi
done
