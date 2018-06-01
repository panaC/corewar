/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_iter_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:07:48 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/01 20:13:08 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"

static int			ft_lenlst(t_process *pro)
{
	int				len;

	len = 0;
	while (pro)
	{
		len++;
		pro = pro->next;
	}
	return (len);
}

static int			ft_get_max_pro(t_env *env)
{
	int				i;
	int				max;
	int				tmp;

	i = 0;
	max = 0;
	while (i < env->nb_player)
	{
		tmp = ft_lenlst(env->player[i].process);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}

t_process			*game_iter_process(t_env *env)
{
	t_process		*tmp;
	int				i;
	static int		i_pro = 0;
	static int		i_play = env->nb_player - 1;

	while (i_play >= 0)
	{
		i = 0;
		tmp = env->player[i_play].process;
		while (i++ < i_pro && tmp)
			tmp = tmp->next;
		i_play--;
		if (*i_play < 0 && *i_pro < ft_get_max_pro(env))
		{
			i_pro++;
			i_play = (env->nb_player - 1);
		}
		if (tmp)
			return (tmp);
	}
	i_pro = 0;
	i_play = env->nb_player - 1;
	return (NULL);
}

int					game_has_process(t_env *env)
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


