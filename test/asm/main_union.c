/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_union.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 10:10:18 by pierre            #+#    #+#             */
/*   Updated: 2018/05/16 22:40:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//MAIN DE TEST UNION

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>

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

	t_uint8		buf[4];
	char		name[128];

	int fd = open("test.txt", O_RDONLY);

	read_byte(4, fd, buf);
	read(fd, name, 128);
	printf("%s\n", name)

	return 0;
}
