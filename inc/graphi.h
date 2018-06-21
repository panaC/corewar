/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphi.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:39:29 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/21 09:20:12 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GRAPHI_H
#define __GRAPHI_H

#include <ncurses.h>
#include "corewar.h"
#include "libft.h"

typedef struct	s_graphi
{
	WINDOW		*core_w;
	int			col_core;
	int			row_core;
	WINDOW		*info_w;
	int			col_info;
	int			row_info;
	int			time;
}				t_graphi;
t_graphi		*ft_init_ncurses(void);
void			ft_close_ncurse(t_graphi *to_free);
void			ft_put_arena(t_graphi *info, t_env *e, int buff);
void			ft_put_in_core(t_graphi *info, t_env *e);
void			print_info(WINDOW *info, int *new_row, int *printed);
void			print_player(t_player player, int printed, int *row,\
		WINDOW *info);
void			print_winner_in_window(t_env *e, t_graphi *info);
#endif
