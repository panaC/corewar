/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:31:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/20 16:43:03 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_aff(void *e)
{
	t_process		*p;
	int				pc;

	p = ((t_env*)e)->current_process;
	pc = op_decod_arg((t_env*)e);
	if (!((t_env*)e)->visu)
		verbose((t_env*)e, 1, "AFF: %c\n", p->op.arg[0] % 256);
	p->pc = pc;
	return (TRUE);
}
