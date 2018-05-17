/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:53:08 by pierre            #+#    #+#             */
/*   Updated: 2018/05/16 22:42:11 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include "parser.h"
#include <libft.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <libft.h>

int		main(void)
{
	t_env		e;
	char *file = "../asm/test.txt";

	int fd = open(file, O_RDONLY);
	printf("fd %d\n", fd);

	e.nb_player = 1;
	e.fd[0] = fd;
	e.err_parsing = NULL;
	e.file[0] = file;

	int val = parser(&e);

	printf("val %d\n", val);
	return (0);
}
