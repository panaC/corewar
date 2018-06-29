/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:57:24 by pierre            #+#    #+#             */
/*   Updated: 2018/06/28 12:53:51 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ft_printf.h>
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
	verbose(e, V_7, "Start Parsing %d players\n", e->nb_player);
	while (i <= e->nb_player)
	{
		if (!parser_cor(e, i))
		{
			verbose(e, E_PARSING, "Parsing %s n°%d: %s\n",
					e->player[i - 1].name, i, e->err_parsing);
			ft_strdel(&(e->err_parsing));
			return (FALSE);
		}
		verbose(e, V_6, "parsing %s n°%d -> OK\n", e->player[i - 1].name, i);
		++i;
	}
	verbose(e, V_7, "End Parsing\n");
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
	if (!parser_cor_header(e, &(e->player[numero - 1])))
		return (FALSE);
	if (!parser_cor_data(e, &(e->player[numero - 1])))
		return (FALSE);
	return (TRUE);
}

t_bool		parser_cor_header(t_env *e, t_player *p)
{
	t_u_uint32		buf;

	if (parser_read_byte(4, p->fd, buf.buf) == 1)
	{
		if (buf.value == COREWAR_EXEC_MAGIC)
		{
			if (read(p->fd, p->head.prog_name,
						PROG_NAME_LENGTH) == PROG_NAME_LENGTH)
				return (parser_cor_header_next(e, p));
			else
				ft_sprintf(&e->err_parsing, "header name too short");
		}
		else
			ft_sprintf(&e->err_parsing, "wrong COREWAR_EXEC_MAGIC :%0.8x:",
					buf.value);
	}
	else
		ft_sprintf(&e->err_parsing, "header magic too short");
	return (FALSE);
}

t_bool		parser_cor_header_next(t_env *e, t_player *p)
{
	t_u_uint32		buf;

	if (parser_read_byte(4, p->fd, buf.buf) == 1 &&
			parser_read_byte(4, p->fd, buf.buf) == 1)
	{
		p->head.prog_size = buf.value;
		if (read(p->fd, p->head.comment,
					COMMENT_LENGTH) == COMMENT_LENGTH &&
				parser_read_byte(4, p->fd, buf.buf) == 1)
			return (TRUE);
		else
			ft_sprintf(&e->err_parsing, "header comment too short");
	}
	else
		ft_sprintf(&e->err_parsing, "header code size too short");
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
				lseek(p->fd, 0, SEEK_SET);
				return (TRUE);
			}
		}
	}
	ft_sprintf(&e->err_parsing, "invalid header size %u", p->head.prog_size);
	return (FALSE);
}
