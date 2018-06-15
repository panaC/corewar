/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:02:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/06/09 18:35:05 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "parser.h"
#include "op.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_env	env;

	ft_init_struct(&env);
	if (ft_check_argv(argc, argv, &env))
	{
		if (parser(&env))
		{
			game_init(&env);
			game(&env);
			print_win(&env);
		}
		else
			verbose(&env, E, "PARSER -> QUIT\n");
	}
	else
		verbose(&env, E, "ARG -> QUIT\n");
}
