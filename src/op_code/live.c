/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 18:04:58 by pierre            #+#    #+#             */
/*   Updated: 2018/06/04 14:07:56 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <libft.h>

int			op_live(t_env *e)
{
	t_process	*p;

	p = ((t_env*)e)->current_process;
	++e->nb_live;
	if ((unsigned int)p->numero == p->op.arg[0])
		p->live = TRUE;
	else
	{
		//Reflechir a rajouter un pool de true pour le numero de l'adversaire
		//si set et lors de la verif garder des processus
		//ou gerer cela dans la regle du jeux avec un tableau
	}
	return (TRUE);
}