/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:53:08 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/19 09:27:40 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphi.h"
#include "corewar.h"

static void			init_xy(int *x, int *y)
{
	(*x)++;
	if (*x >= 197)
	{
		*x = 5;
		(*y)++;
	}
}

static int			ft_reverse_or_not(t_env *env, int x, int y)
{
	int				i;
	t_process		*tmp;

	i = 0;
	while (i < env->nb_player)
	{
		tmp = env->player[i].process;
		while (tmp)
		{
			if (((tmp->pc % 64) * 3) + 5 == x  && (tmp->pc / 64) + 1 == y)
				return (1);
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

static void			print_hex(t_graphi *info, int *x, int *y, unsigned char hex, t_env *env)
{
	char	*tab;
	int		tmp;
	int		num;

	tab = "0123456789abcdef";
	tmp = 0;
	num = 0;
	if (ft_reverse_or_not(env, *x, *y))
	{
		tmp = 1;
		wattron(info->core_w, A_REVERSE);
	}
	if (env->mem_gui[(((*y) - 1) * 64) + (((*x - 5) / 3))] != 0)
	{
		num = ((*y - 1) * 64) + ((*x - 5) / 3);
		wattron(info->core_w, COLOR_PAIR(env->mem_gui[num]));
	}
	mvwaddch(info->core_w, *y, *x, tab[hex / 16]);
	init_xy(x, y);
	mvwaddch(info->core_w, *y, *x, tab[hex % 16]);
	init_xy(x, y);
	if (tmp == 1)
		wattroff(info->core_w, A_REVERSE);
	if (num)
		wattroff(info->core_w, COLOR_PAIR(env->mem_gui[num]));
	mvwaddch(info->core_w, *y, *x, ' ');
	init_xy(x, y);
}

void				ft_put_in_core(t_graphi *info, t_env *e)
{
	unsigned char	*tmp;
	int				x;
	int				y;
	int				line;
	int				i;

	tmp = (unsigned char*)e->mem;
	x = 5;
	y = 1;
	line = 0;
	while (line * 64 < MEM_SIZE)
	{
		i = 0;
		while (i < 64)
		{
			if (line * 64 + i < MEM_SIZE)
				print_hex(info, &x, &y, tmp[i], e);
			i++;
		}
		wrefresh(info->core_w);
		tmp += 64;
		line++;
	}
}
