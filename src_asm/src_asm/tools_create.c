/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:05:29 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/09 18:26:50 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char		create_type(char type, int pos, int arg_type)
{
	int		a;
	int		x;

	a = 1;
	x = 7 - (pos - 1) * 2;
	if (arg_type != 12)
		type |= a << x;
	if (arg_type > 10)
		type |= a << (x - 1);
	return (type);
}
