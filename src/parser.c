/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:57:24 by pierre            #+#    #+#             */
/*   Updated: 2018/05/18 16:41:46 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include <stdio.h>

#include "corewar.h"
#include "op.h"
#include "parser.h"
/*
** boucle sur nb_player
** pour init tout les players
*/

t_bool		parser(t_env *e)
{
	int		i;

	i = 1;
	while (i <= e->nb_player)
	{
		if (!parser_cor(e, i))
		{
			ft_printf("Error %s n°%d: %s\n", e->player[i - 1].name, i, e->err_parsing);
			return (FALSE);
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
	/*
	e->pl.numero = numero;
	e->pl.process = NULL;
	parser_init_header(&(pl.head));
	ft_bzero(pl.data, CHAMP_MAX_SIZE);
	*/
	if (!parser_cor_header(e, &(e->player[numero - 1])))
		return (FALSE);
	if (!parser_cor_data(e, &(e->player[numero - 1])))
		return (FALSE);
	return (TRUE);
}

/*
** init name et comment
** check header cf flowchart
*/

t_bool		parser_cor_header(t_env *e, t_player *p)
{
	t_u_uint32		buf;

	if (parser_read_byte(4, p->fd, buf.buf) == 1)
	{
		if (buf.value == COREWAR_EXEC_MAGIC)
		{
			if (read(p->fd, p->head.prog_name,
						PROG_NAME_LENGTH) == PROG_NAME_LENGTH)
			{
				if (parser_read_byte(4, p->fd, buf.buf) == 1 &&
						parser_read_byte(4, p->fd, buf.buf) == 1)
				{
					p->head.prog_size = buf.value;
					if (read(p->fd, p->head.comment, COMMENT_LENGTH) == COMMENT_LENGTH
							&& parser_read_byte(4, p->fd, buf.buf) == 1)
					{
						return (TRUE);
					}
					else
					{
						ft_sprintf(&e->err_parsing, "header comment too short");
					}
				}
				else
				{
					ft_sprintf(&e->err_parsing, "header code size too short");
				}
			}
			else
			{
				ft_sprintf(&e->err_parsing, "header name too short");
			}
		}
		else
		{
			ft_sprintf(&e->err_parsing, "wrong COREWAR_EXEC_MAGIC");
		}
	}
	else
	{
		ft_sprintf(&e->err_parsing, "header magic too short");
	}
	return (FALSE);
}

t_bool		parser_cor_data(t_env *e, t_player *p)
{
	t_uint8		tmp;

	if (p->head.prog_size > 1 && p->head.prog_size <= CHAMP_MAX_SIZE)
	{
		if (read(p->fd, p->data, p->head.prog_size) == p->head.prog_size)
		{
			if (read(p->fd, &tmp, 1) == 0)
			{
				lseek(p->fd , 0 , SEEK_SET);
				return (TRUE);
			}
			else
			{
				ft_sprintf(&e->err_parsing, "invalid header size %u 3", p->head.prog_size);
			}
		}
		else
		{
			ft_sprintf(&e->err_parsing, "invalid header size %u 2", p->head.prog_size);
		}
	}
	else
	{
		ft_sprintf(&e->err_parsing, "invalid header size %u 1", p->head.prog_size);
	}
	return (FALSE);
}
