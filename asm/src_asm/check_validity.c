/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:04:40 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 15:45:30 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int			go_next_parameter(char *str, int a)
{
	if (a < 0)
		return (-1);
	while (str[a] != '\0' && str[a] != '\n' && str[a] != SEPARATOR_CHAR
			&& str[a] != COMMENT_CHAR && (str[a] != 32 || str[a] != 9))
		a++;
	if (str[a] != SEPARATOR_CHAR)
		return (-1);
	a++;
	while (str[a] != '\0' && str[a] != '\n' && (str[a] == 9 || str[a] == 32))
		a++;
	return (a);
}

static int	check_live(char *str, int a, t_file *file)
{
	a = a + 4;
	if (str[a] != 9 && str[a] != 32 && str[a] != '%')
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && (str[a] == 9 || str[a] == 32))
		a++;
	if (str[a] != DIRECT_CHAR || check_direct(str, a, file) <= 0)
		return (error_parameter(str, a, 1, 1));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}

static int	check_ld_lld(char *str, int a, t_file *file, int b)
{
	b = 0;
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32 && str[a] != '%')
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && (str[a] == 9 || str[a] == 32))
		a++;
	if ((b = check_direct(str, a, file)) <= 0
			&& check_indirect(str, a, file) == 0)
		return (error_parameter(str, a, 1, 4 + b));
	if ((a = go_next_parameter(str, a)) == -1)
		return (error_parameter_number(str, a, 1));
	if ((b = check_register(str, a)) <= 0)
		return (error_parameter(str, a, 2, 3 + b));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}

static int	check_fork_lfork_zjmp(char *str, int a, t_file *file)
{
	int		b;

	b = 0;
	while (str[a] != '\0' && check_if_good_char(str[a]) == 1)
		a++;
	if (str[a] != 9 && str[a] != 32 && str[a] != '%')
		return (error_no_space_cmd(str, a));
	while (str[a] != '\0' && str[a] != '\n' && (str[a] == 9 || str[a] == 32))
		a++;
	if ((b = check_direct(str, a, file)) <= 0)
		return (error_parameter(str, a, 1, 1 + b));
	if ((a = go_next_parameter(str, a)) != -1)
		return (error_parameter_number(str, a, 2));
	return (1);
}

int			check_validity(char *str, int a, int check, t_file *file)
{
	if (check == 1)
		return (check_live(str, a, file));
	else if (check == 2 || check == 13)
		return (check_ld_lld(str, a, file, a));
	else if (check == 12 || check == 15 || check == 9)
		return (check_fork_lfork_zjmp(str, a, file));
	else if (check == 6 || check == 7 || check == 8)
		return (check_and_or_xor(str, a, file, a));
	else if (check == 4 || check == 5)
		return (check_sub_add(str, a, a));
	else if (check == 3)
		return (check_st(str, a, file, a));
	else if (check == 11)
		return (check_sti(str, a, file, a));
	else if (check == 10 || check == 14)
		return (check_ldi_lldi(str, a, file, a));
	else if (check == 16)
		return (check_aff(str, a));
	write(1, "Error : unknown instruction\n", 28);
	print_line_col(str, a);
	return (-1);
}
