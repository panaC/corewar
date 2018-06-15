/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:41:20 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 15:45:35 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			check_dr(char *str, int a, t_file *file)
{
	int		b;
	int		c;

	b = check_direct(str, a, file);
	c = check_register(str, a);
	if (b == -110 || c == -110)
		return (-110);
	if (b == 1 || b == 2)
		return (b);
	if (c == 1)
		return (c);
	return (0);
}

int			check_aff(char *str, int a)
{
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32)
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && str[a] != '\n' && (str[a] == 9 || str[a] == 32))
		a++;
	if (check_register(str, a) == 0)
		return (error_parameter(str, a, 1, 3));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}
