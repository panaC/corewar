/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_code.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:23:29 by pierre            #+#    #+#             */
/*   Updated: 2018/06/03 18:16:43 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_CODE_H
# define OP_CODE_H
#include "corewar.h"
#include <libft.h>

int			op_add(void *e);
int			op_aff(void *e);
int			op_fork(void *e);
int			op_lfork(void *e);
int			op_ld(void *e);
int			op_ldi(void *e);
int			op_st(void *e);
int			op_sti(void *e);
int			op_sub(void *e);
int			op_sub(void *e);
int			op_live(void *e);

#endif
