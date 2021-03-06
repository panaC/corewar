/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 09:44:58 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 09:45:33 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix			*ft_mtx_identity(t_matrix *m)
{
	m->xx = 1;
	m->xy = 0;
	m->xz = 0;
	m->wx = 0;
	m->yx = 0;
	m->yy = 1;
	m->yz = 0;
	m->wy = 0;
	m->zx = 0;
	m->zy = 0;
	m->zz = 1;
	m->wz = 0;
	m->tx = 0;
	m->ty = 0;
	m->tz = 0;
	m->ww = 1;
	return (m);
}
