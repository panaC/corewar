/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:53:08 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/21 10:55:44 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphi.h"
#include "corewar.h"

static void			init_xy(int *dim)
{
	dim[0]++;
	if (dim[0] >= 197)
	{
		dim[0] = 5;
		dim[1]++;
	}
}

static int			ft_reverse_or_not(t_env *env, int *dim)
{
	int				i;
	t_process		*tmp;

	i = 0;
	while (i < env->nb_player)
	{
		tmp = env->player[i].process;
		while (tmp)
		{
			if (((tmp->pc % 64) * 3) + 5 == dim[0] &&
					(tmp->pc / 64) + 1 == dim[1])
				return (1);
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

static void			activ_color(int *num, WINDOW *core_w, char *mem_gui, \
		int *dim)
{
	if (mem_gui)
	{
		*num = ((dim[1] - 1) * 64) + ((dim[0] - 5) / 3);
		wattron(core_w, COLOR_PAIR(mem_gui[*num]));
	}
	else
	{
		*num = 1;
		wattron(core_w, A_REVERSE);
	}
}

static void			print_hex(t_graphi *info, int *dim, unsigned char hex,\
		t_env *env)
{
	char	*tab;
	int		tmp;
	int		num;

	tab = "0123456789abcdef";
	tmp = 0;
	num = 0;
	if (ft_reverse_or_not(env, dim))
		activ_color(&tmp, info->core_w, NULL, NULL);
	if (env->mem_gui[((dim[1] - 1) * 64) + (((dim[0] - 5) / 3))] != 0)
		activ_color(&num, info->core_w, env->mem_gui, dim);
	mvwaddch(info->core_w, dim[1], dim[0], tab[hex / 16]);
	init_xy(dim);
	mvwaddch(info->core_w, dim[1], dim[0], tab[hex % 16]);
	init_xy(dim);
	if (tmp == 1)
		wattroff(info->core_w, A_REVERSE);
	if (num)
		wattroff(info->core_w, COLOR_PAIR(env->mem_gui[num]));
	mvwaddch(info->core_w, dim[1], dim[0], ' ');
	init_xy(dim);
}

void				ft_put_in_core(t_graphi *info, t_env *e)
{
	unsigned char	*tmp;
	int				dim[2];
	int				line;
	int				i;

	tmp = (unsigned char*)e->mem;
	dim[0] = 5;
	dim[1] = 1;
	line = 0;
	while (line * 64 < MEM_SIZE)
	{
		i = 0;
		while (i < 64)
		{
			if (line * 64 + i < MEM_SIZE)
				print_hex(info, dim, tmp[i], e);
			i++;
		}
		tmp += 64;
		line++;
	}
}
