/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 10:01:43 by pierre            #+#    #+#             */
/*   Updated: 2018/06/26 15:23:50 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <libft.h>
# include "op.h"
# define NB_FLAG		3
# define NB_ARG			3
# define NB_OP			17
# define T_REG_BIT		1
# define T_DIR_BIT		2
# define T_IND_BIT		3
# define E				-2
# define E_PARSING		-1
# define PRINT			0
# define V_1			1
# define V_2			2
# define V_3			3
# define V_4			4
# define V_5			5
# define V_6			6
# define V_7			7
# define V_8			8

/*
** decodage op_code :
** typedef sur ptr de fonction
** permet de pointer vers l'execution de l'op code
*/
typedef int	(t_f_op)(void *);

/*
** decodage op_code :
** union pour decodage arg binaire
*/
typedef union			u_uint
{
	char				v8;
	short				v16;
	int					v32;
	char				v[4];
}						t_int;

/*
** decodage op_code :
** union pour encodage byte
*/
typedef union			u_encodage
{
	struct				s_bit
	{
		t_uint8			a1:2;
		t_uint8			a2:2;
		t_uint8			a3:2;
		t_uint8			a4:2;
	}					bit;
	t_uint8				value;
}						t_encodage;

/*
** game use in t_process :
** union pour gerer taille variable REG_SIZE
** par defaut 4
*/
typedef union			u_reg
{
	int					v;
	char				t[REG_SIZE];
}						t_reg;

/*
** decodage op_code :
** info sur op_code cf op.c var globale
*/
typedef struct			s_op
{
	t_string			name;
	t_uint8				nb_arg;
	t_arg_type			flag[NB_FLAG];
	t_uint8				op_code;
	t_uint32			cycle;
	t_string			comment;
	t_bool				b_if_encod;
	t_bool				b_size_dir;
	t_f_op				*ft;
}						t_op;

/*
** decodage op_code :
** structure d'execution op_code
*/
typedef struct			s_instruction
{
	t_uint32			index;
	t_uint8				op_code;
	t_encodage			encodage;
	int					arg[NB_ARG];
	t_op				info;
}						t_instruc;

/*
** game :
** structure processus
** un exemplaire pour chaque new fork
** stokage dans la liste chaine du joueur
*/
typedef struct			s_process
{
	t_bool				live;
	t_bool				carry;
	int					pc;
	int					numero;
	t_reg				reg[REG_NUMBER];
	t_instruc			op;
	struct s_process	*next;
}						t_process;

/*
** game :
** structure de gestion du joueur
*/
typedef struct			s_player
{
	t_header			head;
	t_process			*process;
	char				data[CHAMP_MAX_SIZE];
	int					numero;
	int					fd;
	char				*name;
	t_uint32			mem_ref;
	unsigned long		last_live;
	int					nb_live;
}						t_player;

/*
** corewar :
** structure d'environnement corewar
** arg / parsing / game
*/
typedef struct			s_env
{
	t_bool				verbos;
	int					verbos_lvl;
	t_bool				visu;
	t_bool				dump;
	int					nb_cycle_dump;
	t_player			player[MAX_PLAYERS];
	int					nb_player;
	int					win_player;
	int					cycle_to_die;
	int					cycle_totale;
	int					cycle;
	t_uint32			nb_live;
	t_uint32			check;
	char				mem[MEM_SIZE];
	char				mem_gui[MEM_SIZE];
	t_string			err_parsing;
	t_process			*current_process;
}						t_env;

extern t_op				g_op_tab[17];

/*
** init.c
*/
void					ft_init_struct(t_env *e);
void					init_header(t_header *a);

/*
** game_iter_process.c
*/
t_process				*game_iter_process(t_env *env);
int						game_has_process(t_env *env);

/*
** argv
*/
char					*ft_put_help(void);
int						ft_if_all_digit(char *str);
int						ft_check_argv(int argc, char **argv, t_env *env);
int						ft_if_opt_in_sec(int start, char **argv, int argc);
int						ft_if_after_n_error(int start, char **argv, int argc);
int						ft_check_nb_champ(char **argv, int argc, int start);
int						ft_str_in_str(char *str, char *cmp);
int						ft_init_players(t_env *env, char **argv, int start,\
		int argc);
int						ft_check_in_tab_player(int place, t_env *env);
int						ft_check_champs_before(t_env *env, char *str);
int						ft_check_fd_before(t_env *env, int i);

/*
** process.c
*/
void					ft_delete_process(t_env *env);
void					process_init_instruction(t_instruc *ist);
void					process_init_empty(t_process *p, int numero);
void					process_init(t_process *p, t_process *prev,\
		t_uint32 pc);
t_process				*process_create(t_process *prev, t_uint32 pc);
t_process				*process_add_lst(t_process **bg, t_process *prev,
		t_uint32 pc);
void					del_process(t_env *env);

/*
** op_decod.c
*/
int						op_decod(t_env *e);
int						rot_mem(int *pc);
int						rot_mem_set(int *pc);

/*
** op_decod_arg.c
*/
int						op_decod_arg(t_env *e);
int						get_decod_arg(t_env *e, int *pc, t_uint8 enc, int n);
t_int					get_int_mem(t_env *e, int s, int *pc);
t_int					get_int_mem_pc(t_env *e, int s, int pc);
void					set_int_mem_pc(t_env *e, int s, int pc, t_int val);

/*
** game_init.c
*/
t_bool					game_init(t_env *e);
t_bool					game_init_mem(t_env *e);

/*
** game.c
*/
int						game(t_env *e);
t_bool					game_not_end(t_env *e);

/*
** game_rules.c
*/
t_bool					game_rules(t_env *e);

/*
** verbose.c
*/
int						verbose(t_env *e, int code, const char *s, ...);

/*
** ft_dump.c
*/
void					ft_dump(t_env *env);

/*
** print_win.c
*/
void					select_winner(t_env *e);
int						print_win(t_env *e);

/*
** mem_gui.c
*/
void					set_int_gui_pc(t_env *e, int s, int pc, int num);

#endif
