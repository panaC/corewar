#! /bin/zsh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 16:49:26 by pierre            #+#    #+#              #
#    Updated: 2018/06/12 16:49:34 by pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


echo "##################"
echo "Test ASM"
echo "##################"
echo ""

find ressources -name "*.s" -type f -print | while read FILE;
do
	echo $FILE" :"
	echo "OFFICIEL : "
	./ressources/asm $FILE
	hexdump -C "${FILE/%.s/.cor}" > "${FILE/%.s/.odiff}"
	rm -rf "${FILE/%.s/.cor}"
	echo "RENDU : "
	./asm/asm $FILE
	hexdump -C "${FILE/%.s/.cor}" > "${FILE/%.s/.rdiff}"
	echo "DIFF : "
	diff "${FILE/%.s/.odiff}" "${FILE/%.s/.rdiff}"
	rm -rf "${FILE/%.s/.odiff}" "${FILE/%.s/.rdiff}"
done

read
echo ""
echo "##################"
echo "Test corewar"
echo "##################"
echo "Corewar one player"
echo ""

find ressources -name "*.cor" -type f -print | while read FILE;
do
	echo $FILE" :"
	echo "OFFICIEL : "
	./ressources/corewar $FILE
	echo "RENDU : "
	./corewar $FILE
done

echo ""
echo "Corewar 2 players"
echo ""

find ressources -name "*.cor" -type f -print | while read FILE;
do
	find ressources -name "*.cor" -type f -print | while read FILE_2;
	do
		echo $FILE" & "$FILE_2" :"
		echo "OFFICIEL : "
		./ressources/corewar $FILE $FILE_2
		echo "RENDU : "
		./corewar $FILE $FILE_2
	done
done

echo ""
echo "Corewar 3 players"
echo ""

find ressources -name "*.cor" -type f -print | while read FILE;
do
	find ressources -name "*.cor" -type f -print | while read FILE_2;
	do
		find ressources -name "*.cor" -type f -print | while read FILE_3;
		do
			echo $FILE" :"
		echo $FILE" & "$FILE_2" & "$FILE_3: :
			echo "OFFICIEL : "
			./ressources/corewar $FILE $FILE_2 $FILE_3
			echo "RENDU : "
			./corewar $FILE $FILE_2 $FILE_3
		done	
	done
done

echo ""
echo "Corewar 4 players"
echo ""

find ressources -name "*.cor" -type f -print | while read FILE;
do
	find ressources -name "*.cor" -type f -print | while read FILE_2;
	do
		echo $FILE" & "$FILE_2" :"
		echo "OFFICIEL : "
		./ressources/corewar $FILE $FILE_2 $FILE $FILE_2
		echo "RENDU : "
		./corewar $FILE $FILE_2 $FILE $FILE_2
	done
done
