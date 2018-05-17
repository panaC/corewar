/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 10:01:43 by pierre            #+#    #+#             */
/*   Updated: 2018/05/15 15:41:20 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <libft.h>

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

typedef enum		e_flag_encodage;
{
					T_REG = 1;
					T_DIR = 2;
					T_IND = 4;
}					t_fl_e;

typedef struct		s_op
{
	t_string		name;
	t_uint8			nb_arg;
	t_fl_e			flag[3];
	t_uint8			op_code;
	t_uint8			cycle;
	t_string		comment;
	t_bool			b_if_encod;
	t_bool			b_size_dir;
}					t_op;

typedef struct		s_instruction
{
	t_uint32		index;
	t_uint8			op_code;
	t_encodage		encodage;
	t_uint32		arg[3];
	t_op			info;
}					t_instruc;


#endif
