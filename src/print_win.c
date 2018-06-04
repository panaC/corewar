/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 17:49:15 by pierre            #+#    #+#             */
/*   Updated: 2018/06/03 18:01:58 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <libft.h>
#include <ft_printf.h>

int			print_win(t_env *e)
{
	if (e->win_player > 0)
	{
		ft_printf("And the winner is : player %d : \"%s\" (%s)\n",
				e->win_player, e->player[e->win_player].head.prog_name,
				e->player[e->win_player].head.comment);
	}
	else
	{
		ft_dump(e);
	}
	return (TRUE);
}
