/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:49:47 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/21 10:58:02 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "graphi.h"

void	print_info(WINDOW *info, int *new_row, int *printed)
{
	*printed = 1;
	mvwprintw(info, (*new_row) += 2, 2, "Cycle_delta : %d", CYCLE_DELTA);
	mvwprintw(info, (*new_row) += 2, 2, "Nb_live : %d", NBR_LIVE);
	mvwprintw(info, (*new_row) += 2, 2, "Max_checks: %d", MAX_CHECKS);
}

void	print_player(t_player player, int printed, int *row, WINDOW *info)
{
	if (printed == 0)
	{
		mvwprintw(info, (*row) += 2, 2, "PLAYER -%d: ", (player.numero + 1));
		wattron(info, COLOR_PAIR((player.numero + 1)));
		mvwprintw(info, *row, 13, "%s", player.head.prog_name);
		wattroff(info, COLOR_PAIR((player.numero + 1)));
	}
	else
		(*row) += 2;
	mvwprintw(info, (*row) += 2, 2, "Last live:\t%d\t", player.last_live);
	mvwprintw(info, (*row) += 2, 2, "Live in current periode:\t%d\t", \
			player.nb_live);
}
