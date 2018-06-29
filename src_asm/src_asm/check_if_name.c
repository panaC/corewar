/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 21:10:22 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 15:05:03 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		check_if_name(char *str, int a)
{
	if (str[a] == '\n')
		a++;
	while (str[a] != '\n' && str[a] != '\0' && str[a] != COMMENT_CHAR
			&& (str[a] == 32 || str[a] == 9))
		a++;
	if (str[a] == '.')
		return (1);
	return (0);
}
