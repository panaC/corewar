# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2018/06/26 15:22:54 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DBG=-ggdb -fsanitize=address -fno-omit-frame-pointer -g3
DBG2=-ggdb  -fsanitize=address -fsanitize-memory-track-origins

NAME = corewar
CC = gcc
LIB_PRINTF = ft_printf/libftprintf.a
LIB_PRINTF_PATH = ft_printf/
LIB_PRINTF_HEADER = ft_printf/inc
LIB_PRINTF_LINK = ftprintf
LIB = libft/libft.a
LIB_PATH = libft/
LIB_HEADER = libft/includes
LIB_LINK = ft
SRC_DIR = src/
INC_DIR = inc/
CFLAGS = -Wall -Werror -Wextra -I $(LIB_HEADER) -I $(LIB_PRINTF_HEADER) -I $(INC_DIR)
LIB_FLAGS = -lncurses -L$(LIB_PRINTF_PATH) -l$(LIB_PRINTF_LINK) -L$(LIB_PATH) -l$(LIB_LINK)
			
INC_FILE = corewar.h \
		   op.h \
		   parser.h \
		   op_code.h \
		   graphi.h \

SRC_FILE = op.c \
		   main.c \
		   init.c \
		   game.c \
		   game_iter_process.c \
		   game_rules.c \
		   parser.c \
		   parser_tools.c \
		   process.c \
		   check_sec.c \
		   check_argv.c \
		   check_argv_help.c \
		   check_champs_fds.c \
		   game_init.c \
		   init_player.c \
		   init_ncurses.c \
		   ft_put_arena.c \
		   ft_put_in_core.c \
		   print_info.c \
		   print_winner_in_window.c \
		   del_process.c \
		   verbose.c \
		   ft_dump.c \
		   free_links.c \
		   print_win.c \
		   mem_gui.c \
		   op_decod.c \
		   op_decod_arg.c \
		   op_code/add.c \
		   op_code/sub.c \
		   op_code/sti.c \
		   op_code/st.c \
		   op_code/ld.c \
		   op_code/lld.c \
		   op_code/aff.c \
	       op_code/fork.c \
		   op_code/lfork.c \
		   op_code/zjmp.c \
		   op_code/live.c \
		   op_code/ldi.c \
		   op_code/lldi.c \
		   op_code/and.c \
		   op_code/or.c \
		   op_code/xor.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
INC = $(addprefix $(INC_DIR), $(INC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(LIB_PRINTF) $(NAME)

$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_PRINTF)	:
	make -C $(LIB_PRINTF_PATH)

%.o: %.c $(INC)
	     $(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB_FLAGS)

clean	:
	rm -f $(OBJ)
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PRINTF_PATH) fclean

fclean	: clean
	rm -f $(NAME)

re		: clean all

.PHONY	: all clean re fclean $(LIB) $(LIB_PRINTF)
