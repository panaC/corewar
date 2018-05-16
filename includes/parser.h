/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 11:53:33 by pierre            #+#    #+#             */
/*   Updated: 2018/05/16 13:17:15 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <libft.h>
# include "corewar.h"

t_bool		parser(t_env *e);
t_bool		parser_cor(t_env *e, int numero);
t_bool		parser_cor_header(t_player *p);
t_bool		parser_cor_data(t_player *p);

#endif
