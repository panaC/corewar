/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:59:36 by pierre            #+#    #+#             */
/*   Updated: 2018/06/25 11:14:40 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

t_bool			game_init(t_env *e)
{
	int			i;
	t_process	prev;
	int			pc;
	int			tmp;

	verbose(e, V_7, "Start Game_init\n");
	game_init_mem(e);
	i = 1;
	pc = 0;
	tmp = MEM_SIZE / e->nb_player;
	while (i <= e->nb_player)
	{
		verbose(e, V_8, "Init process %d\n", i);
		process_init_empty(&prev, i);
		if (!process_add_lst(&(e->player[i - 1].process), &prev, pc))
			return (FALSE);
		pc += tmp;
		++i;
	}
	verbose(e, V_7, "End Game_init\n");
	return (TRUE);
}

t_bool			game_init_mem(t_env *e)
{
	t_uint32	size;
	int			i;

	verbose(e, V_8, "Start Game_init_mem\n");
	size = MEM_SIZE / e->nb_player;
	i = 0;
	while (i < e->nb_player)
	{
		e->player[i].mem_ref = i * size;
		ft_memcpy(&(e->mem[i * size]), e->player[i].data,
				e->player[i].head.prog_size);
		ft_memset(&(e->mem_gui[i * size]), i + 1, e->player[i].head.prog_size);
		++i;
	}
	return (TRUE);
}
