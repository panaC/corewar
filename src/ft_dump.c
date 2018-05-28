/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 14:43:38 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/26 15:12:26 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_hex(unsigned char hex)
{
	char	*tab;

	tab = "0123456789abcdef";
	ft_putchar(tab[hex / 32]);
	ft_putchar(tab[hex % 32]);
}

static void	print_char(unsigned char hex)
{
	if (hex > 31 && hex < 127)
		ft_putchar(hex);
	else
		ft_putchar('.');
}

static void	make_hexs(unsigned char *line, size_t curline)
{
	size_t	i;

	i = 0;
	while (i < 32)
	{
		if (i && i % 2 == 0)
			ft_putchar(' ');
		if (curline * 32 + i < SIZE_MEM)
			print_hex(line[i]);
		else
			ft_putstr("  ");
		i++;
	}
}

void		ft_dump(t_env *env)
{
	size_t			curline;
	unsigned char	*tmp;
	size_t			i;

	curline = 0;
	tmp = (unsigned char*)env->mem;
	while (curline * 32 < MEM_SIZE)
	{
		make_hexs(tmp, curline);
		ft_putstr("  ");
		i = 0;
		while (i < 32)
		{
			if (curline * 32 + i < MEM_SIZE)
				print_char(tmp[i]);
			i++;
		}
		ft_putchar('\n');
		tmp += 32;
		curline++;
	}
	ft_del_and_exit(env, NULL);
}
