/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_gui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:15:15 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/13 13:20:27 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"

void		set_int_gui_pc(t_env *e, int s, int pc, t_int val)
{
	int		i;

	i = s - 1;
	while (i <= 4 && i >= 0)
	{
		e->mem_gui[rot_mem_set(&pc)] = val.v[i];
		rot_mem(&pc);
		--i;
	}
}
