/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:59:36 by pierre            #+#    #+#             */
/*   Updated: 2018/05/19 16:28:17 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

t_bool			game_init(t_env *e)
{
	int			i;
	t_process	prev;

	//init prog player dans mem suivant numero de joueur
	game_init_mem(e);
	
	i = 1;
	while (i <= e->nb_player)
	{
		process_init_empty(&prev, e->player[i - 1].process, i);
		if (!process_add_lst(&(e->player[i - 1].process), &prev, 0))
		{
			return (FALSE);
		}
		++i;
	}

	//init constante du jeux mais fait dans init_env
	
	return (TRUE);
}

t_bool			game_init_mem(t_env *e)
{
	t_uint32	size;
	int			i;

	size = MEM_SIZE / e->nb_player;
	i = 0;
	while (i < e->nb_player)
	{
		e->player[i].mem_ref = i * size;
		ft_memcpy(&(e->mem[i * size]), e->player[i].data, e->player[i].head.prog_size);
		++i;
	}
	return (TRUE);
}
