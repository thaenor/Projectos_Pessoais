#!/bin/bash
	if [ -n "$(grep ^$1 /etc/passwd)" ]
	then
		echo "O utilizador existe no sistema."
		echo "Nome: $(grep ^$1 /etc/passwd | cut -d ":" -f5)"
		echo "Caminho para a área de trabalho: $(grep ^$1 /etc/passwd | cut -d ":" -f6)"
		echo "Tipo de shell utilizado: $(grep ^$1 /etc/passwd | cut -d ":" -f7)"
		
	else
		echo "O uilizador não existe no sistema."
	fi
exit