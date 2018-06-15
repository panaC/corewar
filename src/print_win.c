/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:49:15 by pierre            #+#    #+#             */
/*   Updated: 2018/06/09 11:44:12 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <libft.h>
#include <ft_printf.h>

void				select_winner(t_env *e)
{
	int				i;
	t_uint32		last;

	i = 1;
	last = 0;
	e->win_player = i;
	while ((i - 1) < e->nb_player)
	{
		if (last < e->player[i - 1].last_live)
		{
			last = e->player[i - 1].last_live;
			e->win_player = i;
		}
		++i;
	}
}

int					print_win(t_env *e)
{
	if (e->win_player > 0)
	{
		ft_printf("And the winner is : player %d : \"%s\" (%s)\n",
				e->win_player, e->player[e->win_player - 1].head.prog_name,
				e->player[e->win_player - 1].head.comment);
	}
	else
	{
		ft_dump(e);
	}
	return (TRUE);
}
