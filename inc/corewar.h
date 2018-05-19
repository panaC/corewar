/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 10:01:43 by pierre            #+#    #+#             */
/*   Updated: 2018/05/19 17:01:36 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <libft.h>
# include "op.h"
# define NB_FLAG		3
# define NB_ARG			3
# define NB_OP			17

/*
** decodage op_code :
** typedef sur ptr de fonction
** permet de pointer vers l'execution de l'op code
*/
typedef int (t_f_op)(void *); //prevoir t_player ou struct custom pour fork

/*
** decodage op_code :
** union pour decodage arg binaire
*/
typedef union		u_uint
{
	t_uint8			v8;
	t_uint16		v16;
	t_uint32		v32;
	t_uint8			v[4];
}					t_uint;

/*
** decodage op_code :
** union pour encodage byte
*/
typedef union		u_encodage
{
	struct			s_bit
	{
		t_uint8		a1:2;
		t_uint8		a2:2;
		t_uint8		a3:2;
		t_uint8		a4:2;
	}				bit;
	t_uint8			value;
}					t_encodage;

/*
** game use in t_process :
** union pour gerer taille variable REG_SIZE
** par defaut 4
*/
typedef union		u_reg
{
	t_uint32		v;
	t_uint8			t[REG_SIZE];
}					t_reg;

/*
** decodage op_code :
** info sur op_code cf op.c var globale
*/
typedef struct		s_op
{
	t_string		name;
	t_uint8			nb_arg;
	t_arg_type		flag[NB_FLAG];
	t_uint8			op_code;
	t_uint32		cycle;
	t_string		comment;
	t_bool			b_if_encod;
	t_bool			b_size_dir;
	t_f_op			*ft;
}					t_op;

/*
** decodage op_code :
** structure d'execution op_code
*/
typedef struct		s_instruction
{
	t_uint32		index;
	t_uint8			op_code;
	t_encodage		encodage;
	t_uint32		arg[NB_ARG];
	t_uint32		arg_raw[NB_ARG];
	t_op			info;
}					t_instruc;

/* game :
** structure processus
** un exemplaire pour chaque new fork
** stokage dans la liste chaine du joueur
*/
typedef struct		s_process
{
	t_bool			live;
	t_bool			carry;
	t_uint32		pc;
	t_reg			reg[REG_NUMBER];
	t_instruc		op;
	t_list			*begin_list;
}					t_process;

/*
** game :
** structure de gestion du joueur
*/
typedef struct		s_player
{
	header_t		head;
	t_list			*process;//null
	t_uint8			data[CHAMP_MAX_SIZE];//bzero
	t_uint32		numero;
	int				fd;
	char			*name;
	t_uint32		mem_ref;
}					t_player;

/* corewar :
** structure d'environnement corewar
** arg / parsing / game
*/
typedef struct		s_env
{
	t_player		player[MAX_PLAYERS];
	t_uint8			nb_player;

	t_uint32		cycle_totale;
	t_uint32		cycle;
	t_uint32		nb_live;
	t_uint32		check;

	t_uint8			mem[MEM_SIZE];

	t_string		err_parsing;
	t_bool			verbos;
	t_bool			visu;
}					t_env;

/*
** variable extern op_tab fournis dans op.h
*/
extern t_op			op_tab[17];

//check argv
int					ft_check_argv(int argc, char **argv, t_env *env);
int					ft_if_opt_in_sec(int start, char **argv, int argc);
int					ft_if_after_n_error(int start, char **argv, int argc);
int					ft_check_nb_champ(char **argv, int argc, int start);
int					ft_str_in_str(char *str, char *cmp);
int					ft_init_players(t_env *env, char **argv, int start, int argc);
int					ft_check_in_tab_player(int place, t_env *env);
int					ft_check_champs_before(t_env *env, char *str);
int					ft_check_fd_before(t_env *env, int i);

/*
 * A FAIRE :
 * les parametres necessaire pour la fct op :
 * t_process
 * ptr sur env nb_live
 *
 * a rajouter dans une structure dans op_code.h
 */

/*
** process.c
*/
void				process_init_instruction(t_instruc *ist);
void				process_init_empty(t_process *p, t_list *l, int numero);
void				process_init(t_process *p, t_process *prev, t_uint32 pc);
t_process			*process_create(t_process *prev, t_uint32 pc);
t_process			*process_add_lst(t_list **l, t_process *prev, t_uint32 pc);

/*
** op_decod.c
*/
t_uint32			op_decod(t_process *p, t_uint8 *b, t_uint32 pc);

/*
** game_init.c
*/
t_bool				game_init(t_env *e);
t_bool				game_init_mem(t_env *e);

/*
** game.c
*/
int					game(t_env *e);

#endif
