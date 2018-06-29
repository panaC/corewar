/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:20:17 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/26 14:39:43 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ft_str_in_str(char *str, char *cmp)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (str[i])
	{
		j = 0;
		tmp = i;
		while (str[tmp] && cmp[j] && str[tmp] == cmp[j])
		{
			tmp++;
			j++;
		}
		if (cmp[j] == '\0' && str[tmp] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int			ft_if_all_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int			ft_if_opt_in_sec(int start, char **argv, int argc)
{
	while (start < argc)
	{
		if (argv[start][0] == '-' && ft_strcmp("-n", argv[start]) != 0)
		{
			ft_putstr_fd("wrong place for option\n", 2);
			return (0);
		}
		else if (ft_if_all_digit(argv[start]) == 1 && start >= 1 &&
				ft_strcmp("-n", argv[start - 1]) != 0)
		{
			ft_putstr_fd("wrong syntax for place champ\n", 2);
			return (0);
		}
		start++;
	}
	return (1);
}

int			ft_if_after_n_error(int start, char **argv, int argc)
{
	while (start < argc)
	{
		if (argv[start][0] == '-' && ft_strcmp(argv[start], "-n") == 0)
		{
			if ((argv[start + 1] && ft_if_all_digit(argv[start + 1]) == 0) ||
				!argv[start + 1])
			{
				ft_putstr_fd("no place after -n\n", 2);
				return (0);
			}
			else if (!argv[start + 2] ||
					ft_str_in_str(argv[start + 2], ".cor") == 0)
			{
				ft_putstr_fd("no champ after place\n", 2);
				return (0);
			}
		}
		start++;
	}
	return (1);
}

int			ft_check_nb_champ(char **argv, int argc, int start)
{
	int		nb_champs;

	nb_champs = 0;
	while (start < argc)
	{
		if (argv[start][0] != '-' && ft_str_in_str(argv[start], ".cor") == 1)
			nb_champs++;
		else if (argv[start][0] != '-' && ft_if_all_digit(argv[start]) == 0)
		{
			ft_putstr_fd("wrong format for champ\n", 2);
			return (0);
		}
		start++;
	}
	if (nb_champs > MAX_PLAYERS)
	{
		ft_putstr_fd("Too much champs\n", 2);
		return (0);
	}
	if (nb_champs == 0)
		ft_putstr_fd("no champs\n", 2);
	return (nb_champs);
}
