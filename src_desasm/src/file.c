/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:58:12 by lchancri          #+#    #+#             */
/*   Updated: 2018/10/16 14:41:47 by pleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/desasm.h"

t_file		*stock_file(char c, int place)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->place = place;
	file->c = c;
	file->next = NULL;
	return (file);
}
