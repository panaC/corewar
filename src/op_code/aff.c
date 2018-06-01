/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 07:31:49 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/01 22:00:26 by pleroux          ###   ########.fr       */
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

	p = ((t_env*)e)->current_process;
	ft_printf("AFF: %c\n", p->op.arg[0] % 256);
	return (TRUE);
}
