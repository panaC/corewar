/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:23:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/01 22:01:25 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_ldi(void *e)
{
	t_process		*p;
	t_reg			value;
	int				i;

	i = REG_SIZE;
	p = ((t_env*)e)->current_process;
	return (TRUE);
}
