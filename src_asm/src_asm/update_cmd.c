/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:21:18 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 18:14:20 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

static int	which_label(t_label *label, char *tmp)
{
	int		a;
	t_label	*tmp2;

	a = 0;
	tmp2 = label;
	while (label)
	{
		if (label->name && ft_strcmp(tmp, label->name) == 0)
		{
			label = tmp2;
			return (a);
		}
		label = label->next;
		a++;
	}
	label = tmp2;
	return (a);
}

static int	arg_value(char *str, int a, t_label *label)
{
	int		b;
	char	*tmp;

	if (a == -1)
		return (0);
	if (str[a] == '%')
		a++;
	if (str[a] != 'r' && str[a] != ':')
		return (ft_atoi(&str[a]));
	if (str[a] == 'r')
		return (ft_atoi(&str[a + 1]));
	a++;
	b = 0;
	while (str[a + b] != '\0' && check_if_good_char(str[a + b]) == 1)
		b++;
	if (!(tmp = (char*)malloc(sizeof(char) * (b + 1))))
		return (0);
	tmp = ft_strncpy(tmp, &str[a], b);
	b = which_label(label, tmp);
	free(tmp);
	return (b);
}

static int	arg_type(char *str, int a)
{
	int		b;

	if (a == -1)
		return (0);
	if (str[a] != '%')
		b = 10;
	else
	{
		b = 0;
		a++;
	}
	if (str[a] == ':')
		b = b + 1;
	else if (str[a] == 'r')
		b = b + 2;
	else if (str[a] == '+' || str[a] == '-' || (str[a] >= 48 && str[a] <= 57))
		b = b + 3;
	else
		b = 0;
	return (b);
}

t_cmd		*init_cmd(char *str, int a, int check, t_label *label)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);
	cmd->a = a;
	cmd->op_code = check;
	while (str[a] == 32 || str[a] == 9)
		a++;
	while (str[a] != 32 && str[a] != 9 && str[a] != '%')
		a++;
	while (str[a] == 32 || str[a] == 9)
		a++;
	cmd->arg1_type = arg_type(str, a);
	cmd->arg1_value = arg_value(str, a, label);
	a = go_next_parameter(str, a);
	cmd->arg2_type = arg_type(str, a);
	cmd->arg2_value = arg_value(str, a, label);
	a = go_next_parameter(str, a);
	cmd->arg3_type = arg_type(str, a);
	cmd->arg3_value = arg_value(str, a, label);
	cmd->next = NULL;
	return (cmd);
}
