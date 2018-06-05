/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_decod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 19:20:39 by pierre            #+#    #+#             */
/*   Updated: 2018/06/05 13:31:37 by pleroux          ###   ########.fr       */
/*   Updated: 2018/05/20 02:25:04 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"
#include <ft_printf.h>

t_uint32		rot_mem(t_uint32 *pc)
{
	*pc = *pc + 1;
	if (*pc >= MEM_SIZE)
		*pc = *pc % MEM_SIZE;
	return (*pc);
}

t_uint32		rot_mem_set(t_uint32 *pc)
{
	if (*pc >= MEM_SIZE)
		*pc = *pc % MEM_SIZE;
	return (*pc);
}

t_uint32		op_decod(t_env *e)
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
	t_process	*p;
	t_uint8		*b;
	t_uint32	pc;

	verbose(e, V_7, "Start Op_decode\n");
	p = e->current_process;
	b = e->mem;
	pc = p->pc;
	val.v32 = 0;
	i = 0;
	if (!p || !b || b[pc] == 0 || b[pc] > REG_NUMBER)
	{
		verbose(e, V_7, "op: pas d'instruction\n");
		return (rot_mem(&pc));
	}
	if (p->op.info.op_code == 0)
	{
		p->op.op_code = b[pc];
		p->op.info = op_tab[b[pc] - 1];
		verbose(e, V_7, "op: op_code %x\n", b[pc]);
	}
	if (p->op.info.cycle == 1)
	{
		verbose(e, V_7, "op: GO\n");
		if (p->op.info.b_if_encod == FALSE)
		{
			verbose(e, V_7, "op: pas d'encodage\n");
			if (p->op.info.b_size_dir)
			{
				verbose(e, V_7, "op: DIR 2B\n");
				//2 octets
				val.v[1] = b[rot_mem(&pc)];
				val.v[0] = b[rot_mem(&pc)];
				p->op.arg[0] = val.v32;
				verbose(e, V_7, "op: arg[0] %u\n", p->op.arg[0]);
			}
			else
			{
				verbose(e, V_7, "op: DIR 4B\n");
				//4 octets
				val.v[3] = b[rot_mem(&pc)];
				val.v[2] = b[rot_mem(&pc)];
				val.v[1] = b[rot_mem(&pc)];
				val.v[0] = b[rot_mem(&pc)];
				p->op.arg[0] = val.v32;
			}
		}
		else
		{
			verbose(e, V_7, "op: encodage\n");
			p->op.encodage.value = b[rot_mem(&pc)];
			//ft_print_memory(&(b[pc]), 1);
			encod[0] = p->op.encodage.bit.a4;
			encod[1] = p->op.encodage.bit.a3;
			encod[2] = p->op.encodage.bit.a2;
			verbose(e, V_7, "op: p->op.encodage.value %x\n", p->op.encodage.value);
			while (i < p->op.info.nb_arg)
			{
				val.v32 = 0;
				verbose(e, V_7, "op: boucle arg %d\n", i);
				if (encod[i] == T_REG_BIT)
				{
					verbose(e, V_7, "op: boucle T_REG %d\n", i);
					val.v8 = b[rot_mem(&pc)];
					if (val.v8 && val.v8 <= REG_NUMBER)
					{
						p->op.arg[i] = p->reg[val.v8 - 1].v;
						p->op.arg_raw[i] = val.v32;
						verbose(e, V_7, "arg %u raw %u\n", p->op.arg[i], p->op.arg_raw[i]);
					}
					else
					{
						//LOU S'EN OCCUPE
						//rm process cf pdf mark
					}
				}
				else if (encod[i] == T_IND_BIT)
				{
					verbose(e, V_7, "op: boucle T_IND %d\n", i);
					//2 octets
					val.v[1] = b[rot_mem(&pc)];
					val.v[0] = b[rot_mem(&pc)];
					p->op.arg[i] = p->pc + val.v32;
					p->op.arg[i] = rot_mem_set(&(p->op.arg[i]));
					p->op.arg_raw[i] = val.v32;
					verbose(e, V_7, "op: arg %u raw %u\n", p->op.arg[i], p->op.arg_raw[i]);
				}
				else if (encod[i] == T_DIR_BIT)
				{
					verbose(e, V_7, "op: boucle T_DIR %d\n", i);
					if (p->op.info.b_size_dir)
					{
						//2 octets
						val.v[1] = b[rot_mem(&pc)];
						val.v[0] = b[rot_mem(&pc)];
						p->op.arg[i] = rot_mem_set(&(val.v32));
						p->op.arg_raw[i] = val.v32;
						verbose(e, V_7, "op: arg %u raw %u\n", p->op.arg[i], p->op.arg_raw[i]);
					}
					else
					{
						//4 octets
						val.v[3] = b[rot_mem(&pc)];
						val.v[2] = b[rot_mem(&pc)];
						val.v[1] = b[rot_mem(&pc)];
						val.v[0] = b[rot_mem(&pc)];
						p->op.arg[i] = rot_mem_set(&(val.v32));
						p->op.arg_raw[i] = val.v32;
						verbose(e, V_7, "op: arg %u raw %u\n", p->op.arg[i], p->op.arg_raw[i]);
					}
				}
				else
				{
					//ft_printf("op: boucle encodage inconnu %d\n", i);
					//encodage inconnu avance de 1 octets min
					val.v[0] = b[rot_mem(&pc)];
					p->op.arg[i] = 0;
					p->op.arg_raw[i] = 0;
					verbose(e, V_7, "op: arg %u raw %u\n", p->op.arg[i], p->op.arg_raw[i]);
				}
				++i;
			}
		}
		//exec de la fct op
		//recuperer le tableau ft_tab et executer la bonne fonction
		//ou le mettre dans op_tab si possible de le modifier
		//test de la fonction si true == Modification du PC et pas ajout du pc d'op_decod
		if (p->op.info.ft(e))
			pc = p->pc;
		process_init_instruction(&(p->op));
		rot_mem(&pc);
	}
	else
	{
		//decremente cycle pour atteindre fin de cycle
		--(p->op.info.cycle);
	}
	verbose(e, V_7, "End Op_decode\n");
	return (pc);
}
