/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champs_fds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:18:02 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/26 09:14:59 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <libft.h>
#include <ft_printf.h>

int		ft_check_in_tab_player(int place, t_env *env)
{
	int	i;

	i = 0;
	if (place > (env->nb_player - 1))
	{
		ft_putstr_fd("place is over the number of players\n", 2);
		return (0);
	}
	while (i < env->nb_player)
	{
		if ((int)env->player[i].numero == place)
		{
			ft_putstr_fd("two champ on same place\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_check_champs_before(t_env *env, char *str)
{
	int	i;

	i = 0;
	while (i < env->nb_player)
	{
		if (env->player[i].name && ft_strcmp(env->player[i].name, str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_fd_before(t_env *env, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (env->player[i].fd == env->player[j].fd)
			return (0);
		j++;
	}
	return (1);
}
