/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:03:05 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/16 23:04:47 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "corewar.h"
#include "parser.h"

int			parser_read_byte(int byte, int fd, void *buf)
{
	int		i;
	int		ret;

	ret = -1;
	if (byte > 0 && byte <= 4)
	{
		i = byte - 1;
		while (i >= 0)
		{
			ret = read(fd, buf + i, 1);
			--i;
		}
	}
	return (ret);
}

void		parser_init_header(header_t *a)
{
	a->magic = 0;
	a->prog_size = 0;
	ft_bzero(a->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(a->comment, COMMENT_LENGTH + 1);
}
