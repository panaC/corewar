/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_iter_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:07:48 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/26 16:18:24 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"

static int			game_iter_process_check(t_env *e, t_process **tab,
		int *curs_num)
{
	int				i;

	if (!((i = 0)) && *curs_num == -2)
	{
		while (i < MAX_PLAYERS)
		{
			if (i < e->nb_player)
				tab[i] = e->player[i].process;
			else
				tab[i] = NULL;
			++i;
		}
		*curs_num = MAX_PLAYERS - 1;
	}
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (tab[i] != NULL)
			break ;
		++i;
	}
	return (i);
}

t_process			*game_iter_process(t_env *e)
{
	static t_process	*tab[MAX_PLAYERS];
	static int			curs_num = -2;
	int					i;
	t_process			*ret;

	i = game_iter_process_check(e, tab, &curs_num);
	if (!((ret = NULL)) && i == MAX_PLAYERS)
		curs_num = -2;
	else
	{
		while (TRUE)
		{
			if (curs_num == -1)
				curs_num = e->nb_player - 1;
			if (tab[curs_num] != NULL)
			{
				ret = tab[curs_num];
				tab[curs_num] = tab[curs_num]->next;
				--curs_num;
				break ;
			}
			--curs_num;
		}
	}
	return (ret);
}

int					game_has_process(t_env *env)
{
	int				i;

	verbose(env, V_7, "Start game_has_process\n");
	i = 0;
	while (i < env->nb_player)
	{
		if (env->player[i].process)
		{
			verbose(env, V_7, "End game_has_process\n");
			return (1);
		}
		i++;
	}
	verbose(env, V_7, "End game_has_process\n");
	return (0);
}
