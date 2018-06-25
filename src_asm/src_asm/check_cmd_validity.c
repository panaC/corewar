/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:38:21 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 17:03:23 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			check_sti(char *str, int a, t_file *file, int b)
{
	b = 0;
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32)
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && (str[a] == 32 || str[a] == 9))
		a++;
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 1, 3 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if ((b = check_dr(str, a, file)) <= 0 && check_indirect(str, a, file) == 0)
		return (error_parameter(str, a, 2, 7 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if ((b = check_dr(str, a, file)) <= 0)
		return (error_parameter(str, a, 3, 5 + b));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}

int			check_ldi_lldi(char *str, int a, t_file *file, int b)
{
	b = 0;
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32 && str[a] != '%')
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && (str[a] == 32 || str[a] == 9))
		a++;
	if ((b = check_dr(str, a, file)) <= 0 && check_indirect(str, a, file) == 0)
		return (error_parameter(str, a, 1, 7 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if ((b = check_dr(str, a, file)) <= 0)
		return (error_parameter(str, a, 2, 5 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 3, 3 + b));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}

int			check_sub_add(char *str, int a, int b)
{
	b = 0;
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32)
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && (str[a] == 32 || str[a] == 9))
		a++;
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 1, 3 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 2, 3 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 3, 3 + b));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}

int			check_st(char *str, int a, t_file *file, int b)
{
	b = 0;
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32)
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && (str[a] == 32 || str[a] == 9))
		a++;
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 1, 3 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if (check_indirect(str, a, file) == 0 && (b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 2, 6 + b));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}

int			check_and_or_xor(char *str, int a, t_file *file, int b)
{
	b = 0;
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32 && str[a] != '%')
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && (str[a] == 32 || str[a] == 9))
		a++;
	if ((b = check_dr(str, a, file)) <= 0 && check_indirect(str, a, file) == 0)
		return (error_parameter(str, a, 1, 7 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if (check_indirect(str, a, file) == 0 && (b = check_dr(str, a, file)) <= 0)
		return (error_parameter(str, a, 2, 7 + b));
	if ((b = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	a = b;
	b = 0;
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 3, 3 + b));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}
