/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 02:26:04 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/24 12:23:35 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

//le header de la fct n'inclue pas env
//cf add.c -> int			op_add(void *v, t_list *l, t_uint8 *b)
void		ft_fork(t_env *env, t_process *p)
{
	t_process	*new;

	if (!new = (t_process*)malloc(sizeof(t_process) * 1))
		ft_del_and_exit(env);
	new->numero = p->numero;
	new->carry = p->carry;
	new->live = p->live;
	//Il faut recuperer le PC en argument de l'op code grace a p->arg
	new->pc = p->pc;
	while (p->next)
		p = p->next;
	p->next = new;
	new->next = NULL;
}
