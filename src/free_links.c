/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 03:48:48 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/13 13:34:04 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

static void		ft_del_link(t_process **tmp, t_process *bg)
{
	while (bg && bg->next != (*tmp))
		bg = bg->next;
	if (!bg)
		return ;
	bg->next = (*tmp)->next;
	ft_memdel((void**)tmp);
	(*tmp) = bg;
}

void			ft_delete_process(t_env *env)
{
	int			i;
	t_process	*p;

	i = 0;
	while (i < env->nb_player)
	{
		p = env->player[i].process;
		env->player[i].nb_live = 0;
		while (p)
		{
			if (p->live == 0 && p == env->player[i].process)
			{
				env->player[i].process = env->player[i].process->next;
				free(p);
				p = env->player[i].process;
			}
			else
			{
				(p->live == 0) ? ft_del_link(&p, env->player[i].process) : 0;
				p->live = 0;
				p = p->next;
			}
		}
		i++;
	}
}
