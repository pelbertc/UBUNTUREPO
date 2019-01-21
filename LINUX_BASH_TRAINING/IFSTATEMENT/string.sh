#!/bin/bash

STR1="hello buddy"
STR2="Hello buddy"

#compare the 2 string

if [[ $STR1 = $STR2 ]]; then
#if [ "$STR1" = "$STR2" ]; then
	echo equal
else
	echo no equal
fi
