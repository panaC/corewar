/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:07:18 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 10:47:17 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <unistd.h>
# include <fcntl.h>
# include "../libft/include/libft.h"
# include "op.h"

typedef struct		s_cmd
{
	int				a;
	int				op_code;
	int				arg1_type;
	int				arg1_size;
	int				arg1_value;
	int				arg2_type;
	int				arg2_size;
	int				arg2_value;
	int				arg3_type;
	int				arg3_size;
	int				arg3_value;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_label
{
	int				a;
	int				place;
	char			*name;
	t_cmd			*cmd;
	struct s_label	*next;
}					t_label;

typedef struct		s_file
{
	char			*name;
	int				length;
	char			*comment;
	t_label			*label;
}					t_file;

int					check_rest_param(char *str);
int					label_place(t_label *label, int which_label, int cmd_place);
int					size_cmd(t_cmd *cmd);
int					is_int(char *str, int signe, char c);
int					go_next_parameter(char *str, int a);
int					print_error(char *str, int type, int a);
int					print_error_instruction(char *str, int type, int a);
int					error_no_space_cmd(char *str, int a);
int					error_parameter(char *str, int a, int parameter, int error);
int					error_label(char *str, int a);
int					error_parameter_number(char *str, int a, int enough_or_not);
int					error_lenght(int type);
int					error_cmd_before_name(char *str, int a);
int					error_name_comment(int check);
int					check_if_good_char(char c);
int					check_name_comment(char *str, int a, int name, int comment);
int					check_which_cmd(char *str, int a);
int					check_if_cmd_label(char *str, int a, t_file *file, int b);
int					check_label(char *str, int a);
int					check_cmd(t_file *file, char *str, int a);
int					check_validity(char *str, int a, int check, t_file *file);
int					check_direct(char *str, int a, t_file *file);
int					check_indirect(char *str, int a, t_file *file);
int					check_register(char *str, int a);
int					check_and_or_xor(char *str, int a, t_file *file, int b);
int					check_st(char *str, int a, t_file *file, int b);
int					check_aff(char *str, int a);
int					check_sub_add(char *str, int a, int b);
int					check_ldi_lldi(char *str, int a, t_file *file, int b);
int					check_dr(char *str, int a, t_file *file);
int					check_sti(char *str, int a, t_file *file, int b);
int					check_if_name(char *str, int a);
char				*cpy_name(char *str);
char				*error_binary(void);
char				create_type(char type, int pos, int arg_type);
void				print_line_col(char *str, int a);
void				create_binary(t_file *file, char *name);
void				write_file(t_file *file, int fd);
t_file				*prepare_file(t_file *file, int a, int size, int prog_size);
t_file				*check_file(char *str, int a, int check, t_file *file);
t_file				*init_file(void);
t_file				*update_file(t_file *file, char *str, int a, int check);
t_file				*free_file(t_file *file);
t_label				*init_label(char *str, int a);
t_cmd				*init_cmd(char *str, int a, int check, t_label *file);
#endif
