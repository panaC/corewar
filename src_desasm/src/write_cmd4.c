/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cmd4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:10:33 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/28 12:59:05 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

int			write_aff(t_file *file, int fd)
{
	int		size;

	size = 0;
	write(fd, "aff ", 4);
	if (file)
		file = file->next;
	if (file)
		size = write_enc(file, fd, 4, 0);
	write(fd, "\n", 1);
	return (size + 1);
}
