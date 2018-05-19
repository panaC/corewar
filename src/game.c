/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:33:14 by pierre            #+#    #+#             */
/*   Updated: 2018/05/19 17:00:15 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

static int			game_has_process(t_env *env)
{
	int				i;

	i = 0;
	while (i < env->nb_player)
	{
		if (env->player[i].process)
			return (1);
		i++;
	}
	return (0);
}

static t_process	*game_iter_process(t_env *env, int i_process, int i_player)
{
}

int					game(t_env *e)
{
	t_process		*p;
	int				index_process;
	int				index_player;

	while (game_has_process(e))
	{
		index_process = 0;
		index_player = 0;
		while ((p = game_iter_process(e, index_process, index_player)))
		{
			//execute le process
			//verifier la paralellisation des instructions de chaque joueur
			//pour savoir qui ecrit en memoire avant l'autre si proche de la
			//meme case memoire
			//priorise avec le numero
		}
		++e->cycle_totale;
		++e->cycle;
		//appel fct verification fin de cycle
	}
	return (TRUE);
}
