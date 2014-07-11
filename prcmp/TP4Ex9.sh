#!/bin/bash

while (1)
	echo "Escolha a operacao (V,U,C,M,D,E,S)"
	read r

	case $r in
		"V" | "v" ) 
			echo "Que ficheiro quer ver?" ;
			read fich ;
			ufich = $fich ;
			if test $fich -f
			then
				more $fich ;
			else
				echo "Tem que ser um ficheiro!";
			fi ;;
		"U" | "u" )
				if test $ufich -f
				then
					echo " Ultimo ficheiro acedido: $ufich" ;
				else
					echo "Ainda nao foi acedido nenhum ficheiro!" ;
				fi ;;
		"C" | "c" ) 
				echo "Qual o ficheiro a copiar?" ;
				read cfich ;
				echo "Qual o directorio que pretende colar o ficheiro?" ;
				read direc ;
				if test $cfich -f
				then
					if test $direc -d
					then
						cp $cfich $direc ;
					else
						echo "$direc nao e directorio!" ;
					fi
				else
					echo "$cfich nao e ficheiro!" ;
				fi ;;
		"M" | "m" ) echo "Directorio corrente: $(pwd)" ;;
		"E" | "e" )
				maior=0 ;
				for var in $(ls)
				do
					if test var -f
					then
						if [ $(wc -l $var) -gt $maior ]
						then
							maior = $(wc -l $var) ;
							nmaior = $var ;
						fi
				done
					echo "O ficheiro com mais linhas e $nmaior" ;
					more $nmaior ;;
		"S" | "s" ) exit ;;
			* ) echo "digite uma letra correta!" ;;
		esac
	done
exit  
