# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 16:42:34 by pierre            #+#    #+#              #
#    Updated: 2018/06/26 17:01:40 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM= src_asm/
DESASM= src_desasm/
VM= src_vm/

ASM_NAME= asm
DESASM_NAME= desasm
VM_NAME= corewar

all			: $(ASM) $(DESASM) $(VM)

$(ASM)		:
	make -C $(ASM)
	ln -s -f $(ASM)$(ASM_NAME) $(ASM_NAME)

$(DESASM)	:
	make -C $(DESASM)
	ln -s -f $(DESASM)$(DESASM_NAME) $(DESASM_NAME)

$(VM)		:
	make -C $(VM)
	ln -s -f $(VM)$(VM_NAME) $(VM_NAME)

clean		:
	make -C $(ASM) clean
	make -C $(DESASM) clean
	make -C $(VM) clean

fclean		:
	make -C $(ASM) fclean
	make -C $(DESASM) fclean
	make -C $(VM) fclean
	rm -f $(ASM_NAME)
	rm -f $(DESASM_NAME)
	rm -f $(VM_NAME)

re			: fclean all

.PHONY		: all clean fclean re $(ASM) $(DESASM) $(VM)
