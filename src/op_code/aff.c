/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:31:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/05/20 07:43:25 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include "op_code.h"
#include "corewar.h"
#include "op.h"

int			op_aff(void *v, t_list *l, t_uint8 *b)
{
	t_process		*p;

	(void)l;
	(void)b;
	p = (t_process*)v;
	ft_printf("AFF: %c\n", p->op.arg[0] % 256);
	return (TRUE);
}
