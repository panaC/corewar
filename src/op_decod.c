/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_decod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:20:39 by pierre            #+#    #+#             */
/*   Updated: 2018/05/19 15:51:23 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

static t_uint32	rot_mem(t_uint32 *pc)
{
	if (*pc == MEM_SIZE)
		*pc = 0;
	return (*pc);
}

t_uint32		op_decod(t_process *p, t_uint8 *b, t_uint32 pc, t_list **l)
{

// attention memoire circulaire tester en permanence valeur de
// pc pour savoir si on attend la valeur max pour remise a 0
//
// d'apres la vm officiel saut pc par rapport a l'octet
// suivant nb_arg op code saut de minimum de nb arg * 1 octet e
// apres suivant octet d'encodage

	t_uint		val;
	t_uint8		encod[3];
	t_uint8		i;

	val.v32 = 0;
	i = 0;
	if ((!p || !b) && b[pc] && b[pc] > REG_NUMBER)
		return (rot_mem(&pc));
	if (p->op.info.op_code == 0)
	{
		p->op.op_code = b[pc];
		p->op.info = op_tab[b[pc] - 1];
	}
	if (p->op.info.cycle == 0)
	{
		if (p->op.b_if_encod == FALSE)
		{
			if (p->op.b_size_dir)
			{
				//2 octets
				val.v[0] = b[rot_mem(&(++pc))];
				val.v[1] = b[rot_mem(&(++pc))];
				p->op.arg[0] = val.v32;
			}
			else
			{
				//4 octets
				val.v[0] = b[rot_mem(&(++pc))];
				val.v[1] = b[rot_mem(&(++pc))];
				val.v[2] = b[rot_mem(&(++pc))];
				val.v[3] = b[rot_mem(&(++pc))];
				p->op.arg[0] = val.v32;
			}
		}
		else
		{
			val.v32 = 0;
			p->op.encodage = b[rot_mem(&(++pc))];
			encod[0] = p->op.encodage.a1;
			encod[1] = p->op.encodage.a2;
			encod[2] = p->op.encodage.a3;
			while (i < p->op.nb_arg)
			{
				if (encod[i] == T_REG)
				{
					val.v8 = b[rot_mem(&(++pc))];
					if (val.v8 && val.v8 <= REG_NUMBER)
					{
						p->op.arg[i] = p->reg[val.v8].v;
						p->op.arg_raw[i] = val.v32;
					}
					else
					{
						//rm process cf pdf mark
					}
				}
				else if (encod[i] == T_IND)
				{
					//2 octets
					val.v[0] = b[rot_mem(&(++pc))];
					val.v[1] = b[rot_mem(&(++pc))];
					p->op.arg[i] = p->pc + val.v32;
					p->op.arg[i] = rot_mem(&(p->op.arg[0]));
					p->op.arg_raw[i] = val.v32;
				}
				else if (encod[i] == T_DIR)
				{
					if (p->op.b_size_dir)
					{
						//2 octets
						val.v[0] = b[rot_mem(&(++pc))];
						val.v[1] = b[rot_mem(&(++pc))];
						p->op.arg[i] = val.v32;
						p->op.arg_raw[i] = val.v32;
					}
					else
					{
						//4 octets
						val.v[0] = b[rot_mem(&(++pc))];
						val.v[1] = b[rot_mem(&(++pc))];
						val.v[2] = b[rot_mem(&(++pc))];
						val.v[3] = b[rot_mem(&(++pc))];
						p->op.arg[i] = val.v32;
						p->op.arg_raw[i] = val.v32;
					}
				}
				else
				{
					//encodage inconnu avance de 1 octets min
					val.v[0] = b[rot_mem(&(++pc))];
					p->op.arg[i] = 0;
					p->op.arg_raw[i] = 0;
				}
				++i;
			}
		}

		//exec de la fct op
		//recuperer le tableau ft_tab et executer la bonne fonction
		//ou le mettre dans op_tab si possible de le modifier
		p->op.ft(p, l);
		//reset op
		process_init_instruction(&(p->op));
	}
	else
	{
		//decremente cycle pour atteindre fin de cycle
		--(p->op.info.cycle);
	}
	return (rot_mem(&pc));
}
