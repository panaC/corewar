/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_which_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:37:51 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/04 15:14:14 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include "../include/op.h"

static int	push_a(char *str, int a)
{
	while (check_if_good_char(str[a]) == 1)
		a++;
	return (a);
}

static int	check_which3(char *tmp, int tmp_len, int ret)
{
	if (tmp_len == 4 || tmp_len == 5)
	{
		if (ft_strcmp(tmp, "live") == 0)
			ret = 1;
		else if (ft_strcmp(tmp, "zjmp") == 0)
			ret = 9;
		else if (ft_strcmp(tmp, "lldi") == 0)
			ret = 14;
		else if (ft_strcmp(tmp, "fork") == 0)
			ret = 12;
		else if (ft_strcmp(tmp, "lfork") == 0)
			ret = 15;
	}
	return (ret);
}

static int	check_which2(char *tmp, int tmp_len, int ret)
{
	if (tmp_len == 3)
	{
		if (ft_strcmp(tmp, "ldi") == 0)
			ret = 10;
		else if (ft_strcmp(tmp, "lld") == 0)
			ret = 13;
		else if (ft_strcmp(tmp, "sti") == 0)
			ret = 11;
		else if (ft_strcmp(tmp, "sub") == 0)
			ret = 5;
		else if (ft_strcmp(tmp, "add") == 0)
			ret = 4;
		else if (ft_strcmp(tmp, "and") == 0)
			ret = 6;
		else if (ft_strcmp(tmp, "xor") == 0)
			ret = 8;
		else if (ft_strcmp(tmp, "aff") == 0)
			ret = 16;
	}
	else
		ret = check_which3(tmp, tmp_len, 0);
	return (ret);
}

int			check_which_cmd(char *str, int a)
{
	int		tmp_len;
	int		ret;
	int		b_tmp;
	char	*tmp;

	ret = 0;
	b_tmp = a;
	a = push_a(str, a);
	tmp_len = a - b_tmp;
	if (!(tmp = (char*)malloc(sizeof(char) * (tmp_len + 1))))
		return (0);
	tmp = ft_strncpy(tmp, &str[b_tmp], tmp_len);
	if (tmp_len == 2)
	{
		if (ft_strcmp(tmp, "ld") == 0)
			ret = 2;
		else if (ft_strcmp(tmp, "st") == 0)
			ret = 3;
		else if (ft_strcmp(tmp, "or") == 0)
			ret = 7;
	}
	else
		ret = (check_which2(tmp, tmp_len, 0));
	free(tmp);
	return (ret);
}
