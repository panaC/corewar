/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 02:26:04 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/05 13:27:46 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include <libft.h>

/*
 * A utiliser dans OP_decod si erreur alloc memoire !
static void		ft_del_and_exit(t_env *env)
{
	int			i;
	t_process	*tmp;
	t_process	*del;

	i = 0;
	while (i < env->nb_player)
	{
		tmp = env->player[i].process;
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		i++;
	}
	ft_putstr_fd("malloc fail\n", 2);
	exit(-1);
}
*/

int			op_fork(void *e)
{
	t_process	*p;

	p = ((t_env*)e)->current_process;
	p->pc += (p->op.arg[0] % IDX_MOD);
	process_add_lst(&(((t_env*)e)->player[p->numero - 1].process),
			p, rot_mem_set(&(p->pc)));
	return (FALSE);
}
