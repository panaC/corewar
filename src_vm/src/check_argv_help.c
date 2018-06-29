/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:20:57 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/26 15:26:12 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_put_help(void)
{
	return ("" \
	"./corewar [-v 0-8 -s] [-dump nbr_cycles] [[-n number] champ1.cor] ...\n" \
	"\n" \
	"The Corewar ASM Championship Arena VM\n" \
	"\n" \
	" Option :\n" \
	"	-v : 1 to 8 verbose level\n" \
	"	-s : GUI option with ncurses\n" \
	"	-dump : print the memory at nbr_cycles then exit\n" \
	"	-h : print this help then exit\n" \
	"\n" \
	" For each champions -n number allow the place modification\n" \
	"\n");
}
