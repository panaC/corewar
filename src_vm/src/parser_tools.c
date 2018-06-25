/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 19:03:05 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/08 11:45:32 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
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
