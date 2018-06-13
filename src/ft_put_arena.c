/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 15:08:21 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/13 14:43:32 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "graphi.h"
#include <unistd.h>

static int			ft_count_pro(t_env *env)
{
	int				i;
	t_process		*tmp;
	int				to_ret;

	i = 0;
	to_ret = 0;
	while (i < env->nb_player)
	{
		tmp = env->player[i].process;
		while (tmp)
		{
			to_ret++;
			tmp = tmp->next;
		}
		i++;
	}
	return (to_ret);
}

static void			ft_put_in_info(WINDOW *info, t_env *env, int play)
{
	int				i;
	int				new_row;

	i = 0;
	new_row = 0;
	wattron(info, A_BOLD);
	if (play == 0)
		mvwprintw(info, new_row += 2, 2, "STATUS : PAUSE");
	else
		mvwprintw(info, new_row += 2, 2, "STATUS : PLAY ");
	mvwprintw(info, new_row += 2, 2, "Cycles: %d", env->cycle_totale);
	mvwprintw(info, new_row += 2, 2, "Process: %d", ft_count_pro(env));
	while (i < env->nb_player)
	{
		mvwprintw(info, new_row += 2, 2, "PLAYER -%d: %s",(i + 1), env->player[i].name);
		mvwprintw(info, new_row += 2, 2, "Last live:\t%d",env->player[i].last_live);
		mvwprintw(info, new_row += 2, 2, "Live in current periode: %d", env->player[i].nb_live);
		i++;
	}
	mvwprintw(info, new_row += 2, 2, "Cycle_to_die : %d", env->cycle_to_die);
	mvwprintw(info, new_row += 2, 2, "Cycle_delta : %d", CYCLE_DELTA);
	mvwprintw(info, new_row += 2, 2, "Nb_live : %d", NBR_LIVE);
	mvwprintw(info, new_row += 2, 2, "Max_checks: %d", MAX_CHECKS);
	wattroff(info, A_BOLD);
}

static void			ft_modif_time(int c, int *time)
{
	if (c == 'r')
	{
		if ((*time / 10) > 10)
			*time /= 10;
	}
	else
	{
		if ((*time * 10) < 1000000)
			*time *= 10;
	}
}

void				ft_put_arena(t_graphi *info, t_env *e)
{
	int				c;
	static int		play;

	ft_put_in_info(info->info_w, e, play);
	ft_put_in_core(info, e);
	wrefresh(info->info_w);
	wrefresh(info->core_w);
	keypad(info->core_w, TRUE);
	while (!play)
	{
		c = wgetch(info->core_w);
		if (c == 's')
			return ;
		play = (c == 32) ? 1 : 0;
		(c == 'r' || c == 'q') ? ft_modif_time(c, &info->time) : 0;
	}
	c = wgetch(info->core_w);
	if (c == 's' || c == 32)
		play = 0;
	(c == 'r' || c == 'q') ? ft_modif_time(c, &info->time) : 0;
	usleep(info->time);
}
