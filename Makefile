# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/25 16:42:34 by pierre            #+#    #+#              #
#    Updated: 2018/06/25 17:02:28 by pierre           ###   ########.fr        #
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
	ln -s $(ASM)$(ASM_NAME) $(ASM_NAME)

$(DESASM)	:
	make -C $(DESASM)
	ln -s $(DESASM)$(DESASM_NAME) $(DESASM_NAME)

$(VM)		:
	make -C $(VM)
	ln -s $(VM)$(VM_NAME) $(VM_NAME)

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
