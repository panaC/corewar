/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:20:50 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/11 16:42:19 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphi.h"
#include <stdlib.h>

void			ft_close_ncurse(t_graphi *to_free)
{
	if (to_free->core_w)
		delwin(to_free->core_w);
	if (to_free->info_w)
		delwin(to_free->info_w);
	free(to_free);
	endwin();
}

static WINDOW	*ft_new_window(int raw, int col, int start_raw, int start_col)
{
	WINDOW		*to_ret;

	if (!(to_ret = newwin(raw, col, start_raw, start_col)))
	{
		ft_putstr_fd("newwin as fail\n", 2);
		return (NULL);
	}
	box(to_ret, ACS_VLINE, ACS_HLINE);
	wrefresh(to_ret);
	return (to_ret);
}

static t_graphi	*ft_creat_struct(void)
{
	t_graphi	*to_ret;

	if (!(to_ret = (t_graphi*)malloc(sizeof(t_graphi) * 1)))
	{
		ft_putstr_fd("malloc fail \n", 2);
		return (NULL);
	}
	to_ret->core_w = NULL;
	to_ret->info_w = NULL;
	to_ret->col_core = 0;
	to_ret->row_core = 0;
	to_ret->col_info = 0;
	to_ret->row_info = 0;
	to_ret->time = 10000;
	return (to_ret);
}

t_graphi		*ft_init_ncurses(void)
{
	t_graphi	*to_ret;
	int			row;
	int			col;

	if (!(to_ret = ft_creat_struct()))
		return (NULL);
	initscr();
	refresh();
	cbreak();
	noecho();
	getmaxyx(stdscr, row, col);
	to_ret->row_core = (row / 1.15);
	to_ret->col_core = (col / 1.80);
	to_ret->row_info = (row / 1.15);
	to_ret->col_info = (col / 3.50);
	if (!(to_ret->core_w = ft_new_window(to_ret->row_core, to_ret->col_core, 0, 0)) ||
		!(to_ret->info_w = ft_new_window(to_ret->row_info, to_ret->col_info, 0, to_ret->col_core)))
	{
		ft_close_ncurse(to_ret);
		return (NULL);
	}
	nodelay(to_ret->core_w, TRUE);
	curs_set(0);
	return (to_ret);
}
