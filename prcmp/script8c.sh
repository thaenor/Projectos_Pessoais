#!/bin/bash
	for apelido in $*
	do
		if [ -n $"grep $apelido $(cat /etc/pwd | cut -d ":" -f5)" ]
		then
			echo "$"""
		fi
	done
exit