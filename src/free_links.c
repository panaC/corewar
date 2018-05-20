/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 03:48:48 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/20 05:15:41 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_delete(t_process *to_del, t_process *begin_list)
{
	while (begin_list && begin_list->next != to_del)
		begin_list = begin_list->next;
	begin_list->next = to_del->next;
	free(to_del);
}

void			ft_delete_process(t_env *env)
{
	int			i;
	t_process	*tmp;

	env->cycle = 0;
	i = 0;
	while (i < env->nb_player)
	{
		tmp = env->player[i].process;
		while (tmp)
		{
			if (tmp->live == 0 && tmp != env->player[i].process)
				ft_delete(tmp, env->player[i].process);
			else if (tmp->live == 0 && tmp == env->player[i].process)
			{
				free(env->player[i].process);
				env->player[i].process = NULL;
			}
			tmp = tmp->next;
		}
		i++;
	}
}
