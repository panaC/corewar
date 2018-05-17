/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:33:14 by pierre            #+#    #+#             */
/*   Updated: 2018/05/17 10:53:12 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

int			game(t_env *e)
{

	t_process		*p;

	while (game_has_process(e))
	{
		while ((p = game_iter_process(e)))
		{
			//execute le process
			//verifier la paralellisation des instructions de chaque joueur
			//pour savoir qui ecrit en memoire avant l'autre si proche de la
			//meme case memoire
			//priorise avec le numero
		}
		++e->cycle_totale;
		++e->cycle;
		//appel fct verification fin de cycle
	}
	return (TRUE);
}
