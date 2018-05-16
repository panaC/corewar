/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:57:24 by pierre            #+#    #+#             */
/*   Updated: 2018/05/16 20:34:20 by pleroux          ###   ########.fr       */
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

	i = 1;
	while (i <= nb_player)
	{
		if (!parser_cor(e, i))
		{
			ft_printf("Error %s n°%d: %s\n", e->file[i - 1], i, e->err_parsing);
			return (TRUE);
		}
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
	t_process	prev;

	pl.numero = numero;
	pl.process = NULL;
	init_header(&(pl->head));
	ft_bzero(pl.data, CHAMP_MAX_SIZE);
	if (!parser_cor_header(e, &pl))
		return (FALSE);
	if (!parser_cor_data(e, &pl))
	{
		ft_strdel(&(pl->comment));
		ft_strdel(&(pl->name));
		return (FALSE);
	}
	process_init_empty(&prev);
	if (!process_add_lst(pl.process, &prev, 0))
	{
		ft_strdel(&(pl->comment));
		ft_strdel(&(pl->name));
		return (FALSE);
	}
	e->player[numero] = pl;
	return (TRUE);
}

/*
** init name et comment
** check header cf flowchart
*/

t_bool		parser_cor_header(t_env *e, t_player *p)
{
	t_u_uint32		buf;

	if (parser_read_byte(4, e->fd[p->numero - 1], buf.buf) == 4)
	{
		if (buf.value == COREWAR_EXEC_MAGIC)
		{
			if (read(e->fd[p->numero - 1], p->head.prog_name,
						PROG_NAME_LENGTH) == PROG_NAME_LENGTH)
			{
				if (parser_read_byte(4, e->fd[p->numero - 1], buf.buf) == 4 &&
						parser_read_byte(4, e->fd[p->numero - 1], buf.buf) == 4)
				{
					p->head.prog_size = buf.value;
					if (read(e->fd[p->numero - 1], p->head.comment,
								COMMENT_LENGTH) == COMMENT_LENGTH &&
							parser_read_byte(4, e->fd[p->numero - 1],
								buf.buf) == 4)
					{
						return (TRUE);
					}
					else
					{
						ft_sprintf(e->err_parsing, "header comment too short");
					}
				}
				else
				{
					ft_sprintf(e->err_parsing, "header code size too short");
				}
			}
			else
			{
				ft_sprintf(e->err_parsing, "header name too short");
		}
		else
		{
			ft_sprintf(e->err_parsing, "wrong COREWAR_EXEC_MAGIC");
		}
	}
	else
	{
		ft_sprintf(e->err_parsing, "header magic too short");
	}
	return (FALSE);
}

t_bool		parser_cor_data(t_env *e, t_player *p)
{
	t_uint8		tmp;

	if (p->head.prog_size > 1 && p->head.prog_size <= CHAMP_MAX_SIZE)
	{
		if (read(e->fd[p->numero - 1], p->data, p->head.prog_size)
				== p->head.prog_size)
		{
			if (read(e->fd[p->numero - 1], &tmp, 1) == 0)
			{
				return (TRUE);
			}
			else
			{
				ft_sprintf(e->err_parsing, "invalid header size %u", p->head.prog_size);
			}
		}
		else
		{
			ft_sprintf(e->err_parsing, "invalid header size %u", p->head.prog_size);
		}
	}
	else
	{
		ft_sprintf(e->err_parsing, "invalid header size %u", p->head.prog_size);
	}
	return (TRUE);
}
