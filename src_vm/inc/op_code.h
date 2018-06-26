/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_code.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:23:29 by pierre            #+#    #+#             */
/*   Updated: 2018/06/26 12:32:03 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_CODE_H
# define OP_CODE_H
# include "corewar.h"
# include <libft.h>

int			op_add(void *e);
int			op_aff(void *e);
int			op_fork(void *e);
int			op_lfork(void *e);
int			op_ld(void *e);
int			op_lld(void *e);
int			op_ldi(void *e);
int			op_lldi(void *e);
int			op_st(void *e);
int			op_sti(void *e);
int			op_sub(void *e);
int			op_sub(void *e);
int			op_live(void *e);
int			op_zjmp(void *e);
int			op_and(void *e);
int			op_or(void *e);
int			op_xor(void *e);

#endif
