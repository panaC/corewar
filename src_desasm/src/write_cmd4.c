/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:10:33 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/11 13:20:10 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

int			write_aff(t_file *file, int fd)
{
	int		size;

	write(fd, "aff ", 4);
	file = file->next;
	size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}
