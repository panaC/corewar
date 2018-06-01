/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:33:14 by pierre            #+#    #+#             */
/*   Updated: 2018/05/24 12:29:00 by pierre           ###   ########.fr       */
/*   Updated: 2018/05/19 17:27:55 by pleroux          ###   ########.fr       */
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
/*
static int			ft_check_pro(t_env *env, int i_play, int i_process)
{
	t_process		*tmp;

	tmp = env->player[i_play].process;
	while (i_process > 0 && tmp)
	{
		i_process--;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	return (0);
}

static t_process	*game_iter_process(t_env *env)
{
	static int		i_play;
	static int		i_proces;
	int				tmp;
	t_process		*tmp_lst;

	if (i_play > (env->nb_player - 1))
	{
		i_play = 0;
		i_proces++;
	}
	while (i_play < (env->nb_player - 1) && ft_check_pro(env, i_play, i_proces))
		i_play++;
	tmp = i_proces;
	tmp_lst = env->player[i_play].process;
	//printf("name = %s\n", env->player[i_play].name);
	while (tmp > 0 && tmp_lst)
	{
		tmp--;
		tmp_lst = tmp_lst->next;
	}
	i_play++;
	return (tmp_lst);
}*/

static t_process	*game_iter_process(t_env *env, int *i_play, int i_pro)
{
	t_process		*tmp;
	int				i;

	while (*i_play < env->nb_player)
	{
		i = 0;
		tmp = env->player[*i_play].process;
		while (i < i_pro && tmp)
		{
			i++;
			tmp = tmp->next;
		}
		(*i_play)++;
		if (tmp)
			return (tmp);
	}
	return (NULL);
}

int					game(t_env *e)
{
	t_process		*p;
	int				i_process;
	int				i_player;

/*	int		i;
	t_process	*tmp;

	printf("DEBUT>>>>>>>>>>\n\n");
	i = 0;
	while (i < e->nb_player)
	{
		tmp = e->player[i].process;
		while (tmp)
		{
			printf("live = %d, carry = %d, pc = %d %s\n\n\n",tmp->live, tmp->carry, tmp->pc, tmp->name);
			tmp = tmp->next;
		}
		printf("player %d\n", i);
		i++;
	}
	printf("FIN>>>>>>>>>>\n\n");
*/
	while (game_has_process(e))
	{
		i_process = 0;
		i_player = 0;
		while ((p = game_iter_process(e, &i_player, i_process)))
		{
			//execute le process
			//si celui si n'est pas dans une periode de cycle
			//sinon
			//verifier la paralellisation des instructions de chaque joueur
			//pour savoir qui ecrit en memoire avant l'autre si proche de la
			//meme case memoire
			//priorise avec le numero
			printf("%d live = %d, carry = %d, pc = %d %s\n\n\n",e->cycle_totale, p->live, p->carry, p->pc, p->name);
			if (i_player >= e->nb_player)
			{
				i_process++;
				i_player = 0;
			}
		}
		++e->cycle_totale;
		++e->cycle;
		if (e->cycle >= CYCLE_TO_DIE)
			ft_delete_process(e);
		//appel fct verification fin de cycle
	}
	return (TRUE);
}
