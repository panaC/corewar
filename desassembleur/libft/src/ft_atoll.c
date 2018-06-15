/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:20:40 by lchancri          #+#    #+#             */
/*   Updated: 2018/05/21 19:34:49 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

long long	ft_atoll(const char *str)
{
	long long	a;
	long long	b;
	int			c;

	a = 0;
	b = 0;
	c = -1;
	while ((str[a] == '\t' || str[a] == '\n' || str[a] == '\r' || str[a] == '\v'
				|| str[a] == '\f' || str[a] == 32) && str[a] != '\0')
		a++;
	if (str[a] == 45)
		c = 1;
	else if (str[a] == 43)
		c = 0;
	if (c != -1)
		a++;
	while (str[a] >= 48 && str[a] <= 57)
	{
		b = b * 10 + (str[a] - 48);
		a++;
	}
	if (c == 1)
		return (-b);
	return (b);
}
