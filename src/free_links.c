/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 03:48:48 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/04 10:33:26 by pierre           ###   ########.fr       */
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
	t_process	*tmp;

	i = 0;
	while (i < env->nb_player)
	{
		tmp = env->player[i].process;
		while (tmp)
		{
			if (tmp->live == 0 && tmp == env->player[i].process)
			{
				env->player[i].process = env->player[i].process->next;
				free(tmp);
				tmp = env->player[i].process;
			}
			else
			{
				if (tmp->live == 0)
					ft_del_link(&tmp, env->player[i].process);
				tmp->live = 0;
				tmp = tmp->next;
			}
		}
		i++;
	}
}
