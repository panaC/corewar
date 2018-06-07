/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_decod_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:45:01 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/07 19:41:49 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

void		set_int_mem_pc(t_env *e, int s, int pc, t_int val)
{
	int		i;

	i = s - 1;
	while (i <= 4 && i >= 0)
	{
		e->mem[rot_mem_set(&pc)] = val.v[i];
		rot_mem(&pc);
		--i;
	}
}

t_int		get_int_mem_pc(t_env *e, int s, int pc)
{
	t_int	val;
	int		i;

	i = s - 1;
	val.v32 = 0;
	while (i <= 4 && i >= 0)
	{
		val.v[i] = e->mem[rot_mem_set(&pc)];
		rot_mem(&pc);
		--i;
	}
	return (val);
}

t_int		get_int_mem(t_env *e, int s, int *pc)
{
	t_int	val;
	int		i;

	i = s - 1;
	val.v32 = 0;
	while (i < 4 && i >= 0)
	{
		val.v[i] = e->mem[rot_mem_set(pc)];
		rot_mem(pc);
		--i;
	}
	return (val);
}

int			get_decod_arg(t_env *e, int *pc, t_uint8 enc, int n)
{
	t_process	*p;

	p = e->current_process;
	if (p->op.info.nb_arg > n)
	{
		if (enc == T_REG_BIT)
			return ((int)get_int_mem(e, 1, pc).v8);
		else if (enc == T_DIR_BIT)
		{
			if (p->op.info.b_size_dir)
				return ((int)get_int_mem(e, 2, pc).v16);
			else
				return (get_int_mem(e, 4, pc).v32);
		}
		else if (enc == T_IND_BIT)
			return ((int)get_int_mem(e, 2, pc).v16);
		else
			rot_mem(pc);
	}
	return (0);
}

int			op_decod_arg(t_env *e)
{
	int			pc;
	t_process	*p;

	p = e->current_process;
	pc = p->pc;
	rot_mem(&pc);
	if (p->op.info.b_if_encod == FALSE)
	{
		if (p->op.info.b_size_dir)
			p->op.arg[0] = (int)get_int_mem(e, 2, &pc).v16;
		else
			p->op.arg[0] = get_int_mem(e, 4, &pc).v32;
	}
	else
	{
		p->op.encodage.value = (t_uint8)(get_int_mem(e, 1, &pc).v8);
		p->op.arg[0] = get_decod_arg(e, &pc, p->op.encodage.bit.a4, 0);
		p->op.arg[1] = get_decod_arg(e, &pc, p->op.encodage.bit.a3, 1);
		p->op.arg[2] = get_decod_arg(e, &pc, p->op.encodage.bit.a2, 2);
		verbose(e, V_7, "op_decod_arg: pc=%d encodage=%x arg[0]=%d arg[1]=%d arg[2]=%d\n", pc, p->op.encodage.value, p->op.arg[0], p->op.arg[1], p->op.arg[2]);
	}
	return (pc);
}

//int			op_decod_arg(t_env *e)
//{
//		verbose(e, V_7, "op: GO\n");
//		if (p->op.info.b_if_encod == FALSE)
//		{
//			verbose(e, V_7, "op: pas d'encodage\n");
//			if (p->op.info.b_size_dir)
//			{
//				verbose(e, V_7, "op: DIR 2B\n");
//				//2 octets
//				val.v[1] = b[rot_mem(&pc)];
//				val.v[0] = b[rot_mem(&pc)];
//				p->op.arg[0] = (int)val.v16;
//				verbose(e, V_7, "op: arg[0] %u\n", p->op.arg[0]);
//			}
//			else
//			{
//				verbose(e, V_7, "op: DIR 4B\n");
//				//4 octets
//				val.v[3] = b[rot_mem(&pc)];
//				val.v[2] = b[rot_mem(&pc)];
//				val.v[1] = b[rot_mem(&pc)];
//				val.v[0] = b[rot_mem(&pc)];
//				p->op.arg[0] = val.v32;
//			}
//		}
//		else
//		{
//			verbose(e, V_7, "op: encodage\n");
//			p->op.encodage.value = b[rot_mem(&pc)];
//			//ft_print_memory(&(b[pc]), 1);
//			encod[0] = p->op.encodage.bit.a4;
//			encod[1] = p->op.encodage.bit.a3;
//			encod[2] = p->op.encodage.bit.a2;
//			verbose(e, V_7, "op: p->op.encodage.value %x\n", p->op.encodage.value);
//			while (i < p->op.info.nb_arg)
//			{
//				val.v32 = 0;
//				verbose(e, V_7, "op: boucle arg %d\n", i);
//				if (encod[i] == T_REG_BIT)
//				{
//					verbose(e, V_7, "op: boucle T_REG %d\n", i);
//					val.v8 = b[rot_mem(&pc)];
//					if (val.v8 && val.v8 <= REG_NUMBER)
//					{
//						p->op.arg[i] = p->reg[val.v8 - 1].v;
//						p->op.arg_raw[i] = val.v32;
//						verbose(e, V_7, "arg %d raw %d\n", p->op.arg[i], p->op.arg_raw[i]);
//					}
//					else
//					{
//						//LOU S'EN OCCUPE
//						//rm process cf pdf mark
//					}
//				}
//				else if (encod[i] == T_IND_BIT)
//				{
//					verbose(e, V_7, "op: boucle T_IND %d\n", i);
//					//2 octets
//					val.v[1] = b[rot_mem(&pc)];
//					val.v[0] = b[rot_mem(&pc)];
//					p->op.arg[i] = p->pc + (int)val.v16;
//					p->op.arg[i] = rot_mem_set(&(p->op.arg[i]));
//					p->op.arg_raw[i] = (int)val.v16;
//					verbose(e, V_7, "op: arg %d raw %d\n", p->op.arg[i], p->op.arg_raw[i]);
//				}
//				else if (encod[i] == T_DIR_BIT)
//				{
//					verbose(e, V_7, "op: boucle T_DIR %d\n", i);
//					if (p->op.info.b_size_dir)
//					{
//						//2 octets
//						val.v[1] = b[rot_mem(&pc)];
//						val.v[0] = b[rot_mem(&pc)];
//						p->op.arg[i] = (int)val.v16;
//						p->op.arg_raw[i] = (int)val.v16;
//						verbose(e, V_7, "op: arg %d raw %d\n", p->op.arg[i], p->op.arg_raw[i]);
//					}
//					else
//					{
//						//4 octets
//						val.v[3] = b[rot_mem(&pc)];
//						val.v[2] = b[rot_mem(&pc)];
//						val.v[1] = b[rot_mem(&pc)];
//						val.v[0] = b[rot_mem(&pc)];
//						p->op.arg[i] = val.v32;
//						p->op.arg_raw[i] = val.v32;
//						verbose(e, V_7, "op: arg %d raw %d\n", p->op.arg[i], p->op.arg_raw[i]);
//					}
//				}
//				else
//				{
//					//ft_printf("op: boucle encodage inconnu %d\n", i);
//					//encodage inconnu avance de 1 octets min
//					val.v[0] = b[rot_mem(&pc)];
//					p->op.arg[i] = 0;
//					p->op.arg_raw[i] = 0;
//					verbose(e, V_7, "op: arg %d raw %d\n", p->op.arg[i], p->op.arg_raw[i]);
//				}
//				++i;
//			}
//		}
//		//exec de la fct op
//		//recuperer le tableau ft_tab et executer la bonne fonction
//		//ou le mettre dans op_tab si possible de le modifier
//		//test de la fonction si true == Modification du PC et pas ajout du pc d'op_decod
//		if (p->op.info.ft(e))
//			pc = p->pc;
//		rot_mem(&pc);
//		process_init_instruction(&(p->op));
//}
