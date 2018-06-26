/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:53:33 by pierre            #+#    #+#             */
/*   Updated: 2018/06/26 12:36:32 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <libft.h>
# include "corewar.h"

typedef union		u_uint32
{
	t_uint8			buf[4];
	t_uint32		value;
}					t_u_uint32;

/*
** parser.c
*/
t_bool				parser(t_env *e);
t_bool				parser_cor(t_env *e, int numero);
t_bool				parser_cor_header(t_env *e, t_player *p);
t_bool				parser_cor_header_next(t_env *e, t_player *p);
t_bool				parser_cor_data(t_env *e, t_player *p);

/*
** parser_tools.c
*/
int					parser_read_byte(int byte, int fd, void *buf);
void				parser_init_header(t_header *a);

#endif
