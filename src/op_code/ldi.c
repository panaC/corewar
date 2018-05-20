/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:23:51 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/20 07:29:39 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_ldi(void *v, t_list *l, t_uint8 *b)
{
	t_process		*p;
	t_reg			value;
	int				i;

	(void)l;
	i = REG_SIZE;
	p = (t_process*)v;
	return (TRUE);
}
