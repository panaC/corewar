/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_winner_in_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 08:45:22 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/21 10:23:57 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphi.h"
#include "corewar.h"

void		print_winner_in_window(t_env *e, t_graphi *info)
{
	int		row;

	row = 14 + (e->nb_player * 6);
	ft_put_arena(info, e, 0);
	wattron(info->info_w, A_BOLD);
	if (e->win_player > 0)
	{
		mvwprintw(info->info_w, row, 2, "And the winner is player : %d", \
				e->win_player);
		wattron(info->info_w, COLOR_PAIR(e->win_player));
		mvwprintw(info->info_w, row, 30, " %s", \
				e->player[e->win_player - 1].head.prog_name);
		wattroff(info->info_w, COLOR_PAIR(e->win_player));
	}
	else
		mvwprintw(info->info_w, row, 2, "No winner");
	mvwprintw(info->info_w, row += 2, 2, "Press any key for end game !");
	wattroff(info->info_w, A_BOLD);
	wrefresh(info->info_w);
	nodelay(info->info_w, FALSE);
	wgetch(info->info_w);
	ft_close_ncurse(info);
}
