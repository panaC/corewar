/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:37:51 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 18:10:49 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "../include/op.h"

int			check_if_good_char(char c)
{
	int		a;

	a = 0;
	while (LABEL_CHARS[a] != '\0')
	{
		if (c == LABEL_CHARS[a])
			return (1);
		a++;
	}
	return (0);
}

static int	check_instr(char *str, int a)
{
	while (a > 0 && str[a] != 32 && str[a] != 9 && str[a] != '\n')
		a--;
	a++;
	if (check_which_cmd(str, a) == 0)
		return (0);
	return (1);
}

static int	check_if_label_or_cmd(char *str, int a)
{
	int		b;

	b = 0;
	while (a - b > 0 && (str[a - b] == 32 || str[a - b] == 9))
		b++;
	if (b == 0 && str[a] != DIRECT_CHAR && str[a] != SEPARATOR_CHAR)
		return (0);
	if (str[a - b] == DIRECT_CHAR || str[a - b] == SEPARATOR_CHAR
			|| str[a - b] == COMMENT_CHAR || check_instr(str, a - b) == 1)
		return (1);
	return (0);
}

int			check_label(char *str, int a)
{
	int		b;

	b = a;
	while (str[a] != LABEL_CHAR && str[a] != '\n' && str[a] != '\0')
	{
		if (str[a] == '#')
			return (0);
		a++;
	}
	if (str[a] == LABEL_CHAR)
	{
		if (check_if_label_or_cmd(str, a - 1) == 1)
			return (0);
		a = b;
		while (str[a] != LABEL_CHAR)
		{
			if (check_if_good_char(str[a]) == 1)
				a++;
			else
				return (error_label(str, b));
		}
		return (3);
	}
	return (0);
}
