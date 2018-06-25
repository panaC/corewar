# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchancri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:09:40 by lchancri          #+#    #+#              #
#    Updated: 2018/06/06 21:13:00 by lchancri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	asm

LIB		=	libft/libft.a

FLAG	=	-Wall -Wextra -Werror

#------------------------------------------------------------------------------#
#-----------------------------------C_FILE-------------------------------------#
#------------------------------------------------------------------------------#

C_PATH	=	src_asm

C_FILE	=	asm.c\
			check_cmd.c\
			check_cmd_label.c\
			check_file.c\
			check_label.c\
			check_name_comment.c\
			check_which_cmd.c\
			check_validity.c\
			check_cmd_validity.c\
			check_aff.c\
			check_if_name.c\
			check_direct_indirect_reg.c\
			error_parsing.c\
			error_parsing2.c\
			error_commande.c\
			tools.c\
			file.c\
			update_file.c\
			update_cmd.c\
			create_binary.c\
			write_cmd.c\
			tools_create.c\
			prepare_file.c\

C_SRC	=	$(addprefix $(C_PATH)/, $(C_FILE))

#------------------------------------------------------------------------------#
#-----------------------------------O_FILE-------------------------------------#
#------------------------------------------------------------------------------#

O_PATH	=	obj_asm

O_FILE	=	$(C_FILE:.c=.o)

O_SRC	=	$(addprefix $(O_PATH)/, $(O_FILE))

#------------------------------------------------------------------------------#
#-----------------------------------INCLUDE------------------------------------#
#------------------------------------------------------------------------------#

I_PATH	=	include

I_FILE	=	asm.h\
			op.h\

I_SRC	=	$(addprefix $(I_PATH)/, $(I_FILE))

#------------------------------------------------------------------------------#
#-----------------------------------REGLE--------------------------------------#
#------------------------------------------------------------------------------#

all: $(LIB) $(NAME)

$(LIB):
	@make -C libft

$(NAME): $(O_PATH) $(O_SRC)
	@gcc $(FLAG) -o $(NAME) $(O_SRC) $(LIB)

$(O_PATH):
	@mkdir -p $(O_PATH)

$(addprefix $(O_PATH)/, %.o): $(addprefix $(C_PATH)/, %.c) $(I_PATH)
	gcc $(FLAG) -Iinclude -o $@ -c $<

clean:
	@rm -Rf $(O_SRC)
	@make clean -C libft
	@rm -Rf $(O_PATH) 2>/dev/null || true

fclean: clean
	@make fclean -C libft
	@rm -Rf $(NAME)

re: fclean all

.PHONY: clean fclean re all $(LIB)
