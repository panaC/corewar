/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:57:24 by pierre            #+#    #+#             */
/*   Updated: 2018/05/16 13:15:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "op.h"

/*
** boucle sur nb_player
** pour init tout les players
*/

t_bool		parser(t_env *e)
{
	int		i;

	i = 0;
	while (i < nb_player)
	{
		if (!parser_cor(e, i))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

/*
** return TRUE si le parsing du binaire est ok
** sinon print error message et return FALSE
**
** creer un nouveau player
** appel fct parser_header
** appel fct parser_binaire
*/

t_bool		parser_cor(t_env *e, int numero)
{
	t_player	pl;

	ft_bzero(pl.data, CHAMP_MAX_SIZE);
	if (!parser_cor_header(&pl))
		return (FALSE);
	if (!parser_cor_data(&pl))
	{
		// free name et comment
		return (FALSE);
	}
	//init a new node with a new struct t_process in process chained list
	e->player[numero] = pl;
	return (TRUE);
}

/*
** init name et comment
** check header cf flowchart
*/

t_bool		parser_cor_header(t_player *p)
{

	return (TRUE);
}

t_bool		parser_cor_data(t_player *p)
{

	return (TRUE);
}
