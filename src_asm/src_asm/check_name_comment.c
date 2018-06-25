/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:06:40 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 17:26:50 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static int	check_lexical_error(char *str, int a)
{
	while (str[a] != '\n' && str[a] != '\0')
	{
		if (str[a] == '.')
		{
			write(1, "Error : Lexical error\n", 22);
			print_line_col(str, a);
			return (-1);
		}
		a++;
	}
	return (0);
}

static int	check_if_cmd_before(int check, char *str, int a)
{
	while (str[a] != '\n' && str[a] != '\0')
	{
		if (str[a] == COMMENT_CHAR || (str[a] == '.'
					&& (check == 1 || check == 2)))
			return (check);
		else if (str[a] == '.')
		{
			write(1, "Error : Lexical error\n", 22);
			print_line_col(str, a);
			return (-1);
		}
		else if (str[a] != 32 && str[a] != 9 && str[a] != '\n'
				&& str[a] != '\0')
			return (error_cmd_before_name(str, a));
		a++;
	}
	return (check);
}

static int	check_format_name_comment(char *str, int a, int type, int len)
{
	int		check_len;

	if (type == 1)
		a = ft_ignore_space_tab(str, a + ft_strlen(NAME_CMD_STRING));
	else if (type == 2)
		a = ft_ignore_space_tab(str, a + ft_strlen(COMMENT_CMD_STRING));
	if (a < len && str[a] != '"')
		return (print_error(str, type, a));
	a = a + ft_strclen(&str[a], '"');
	if (str[a] == '\0')
		return (print_error(str, type, a));
	a++;
	check_len = ft_strclen(&str[a], '"') + 1;
	if ((type == 1 && check_len > PROG_NAME_LENGTH)
			|| (type == 2 && check_len > COMMENT_LENGTH))
		return (error_lenght(type));
	a = a + check_len;
	while (a < len && str[a] != '\n' && str[a] != '#')
	{
		if (str[a] != 32 && str[a] != 9)
			return (print_error_instruction(str, type, a));
		a++;
	}
	return (type);
}

static int	check_if_name_comment(char *str, int a, int name, int comment)
{
	int		check;
	char	*tmp;

	check = 0;
	tmp = cpy_name(&str[a]);
	if (ft_strcmp(NAME_CMD_STRING, tmp) == 0)
		check = check_format_name_comment(str, a, 1, ft_strlen(str));
	else if (ft_strcmp(COMMENT_CMD_STRING, tmp) == 0)
		check = check_format_name_comment(str, a, 2, ft_strlen(str));
	free(tmp);
	if ((check == 1 && name == 1) || (check == 2 && comment == 1))
		return (error_name_comment(check));
	if (check != -1 && (name == 0 || comment == 0))
		check = check_if_cmd_before(check, str, a);
	else if (check != -1)
		check = check_lexical_error(str, a);
	return (check);
}

int			check_name_comment(char *str, int a, int name, int comment)
{
	int		check;

	if (str[a] == '\n')
		a++;
	while (str[a] != '\0' && (str[a] == 32 || str[a] == 9))
		a++;
	if (str[a] != '\0' && str[a] != COMMENT_CHAR && str[a] != '.'
			&& str[a] != '\n' && check_if_good_char(str[a]) != 1)
	{
		write(1, "Error : Lexical error\n", 22);
		print_line_col(str, a);
		return (-1);
	}
	if (str[a] == COMMENT_CHAR || str[a] == '\n' || str[a] == '\0')
		return (0);
	if ((check = check_if_name_comment(str, a, name, comment)) != 0)
	{
		if ((check == 3 || check == 4) && (name == 0 || comment == 0))
			return (error_cmd_before_name(str, a));
		return (check);
	}
	return (0);
}
