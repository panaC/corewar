/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleroux <pleroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:35:11 by pleroux           #+#    #+#             */
/*   Updated: 2018/06/20 16:40:57 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>
#include <stdarg.h>
#include "corewar.h"

int				verbose(t_env *e, int code, const char *s, ...)
{
	char		*str;
	va_list		ap;
	int			sl;

	sl = 0;
	if (e->visu == FALSE && code <= e->verbos_lvl)
	{
		ft_printf(((code < 0) ? "ERROR :%d: " : "VERBOSE :%d: "), code);
		va_start(ap, s);
		sl = ft_vasprintf(&str, s, ap);
		va_end(ap);
		if (sl > 0)
		{
			write(1, str, sl);
			ft_strdel(&str);
		}
	}
	return (sl);
}
