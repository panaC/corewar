/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:37:51 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/01 21:14:56 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "../include/op.h"

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
