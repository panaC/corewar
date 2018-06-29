/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:37:51 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 10:39:00 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			check_rest_param(char *str)
{
	int		a;

	a = 0;
	while (str[a] != '\n' && str[a] != SEPARATOR_CHAR && str[a] != '\0'
			&& str[a] != COMMENT_CHAR)
	{
		if (str[a] != 32 && str[a] != 9)
			return (0);
		a++;
	}
	return (1);
}

int			check_if_cmd_label(char *str, int a, t_file *file, int label_or_cmd)
{
	if (str[a] == '\n')
		a++;
	while ((str[a] == 32 || str[a] == 9) && str[a] != '\0')
		a++;
	if (str[a] == COMMENT_CHAR || str[a] == '\n' || str[a] == '.')
		return (0);
	if (label_or_cmd == 1)
		return (check_label(str, a));
	else
		return (check_cmd(file, str, a));
}
