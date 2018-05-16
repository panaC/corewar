/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_union.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 10:10:18 by pierre            #+#    #+#             */
/*   Updated: 2018/05/15 11:46:56 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//MAIN DE TEST UNION

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>
#include "corewar.h"

int		read_byte(int byte, int fd, void *buf)
{
	int		i;
	int		ret;

	ret = -1;
	if (byte > 0 && byte <= 8)
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

int		main(void)
{
	t_data	a;

	a.byte.op_code = 0;
	a.byte.data = 0;

	int fd = open("test.txt", O_RDONLY);

	read_byte(1, fd, a.data);
	read_byte(2, fd, a.data + 1);
	printf("%x %x\n", a.byte.op_code, a.byte.data);
	if (a.byte.data == 0x1234)
		printf("OK\n");
	return 0;
}
