/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 12:32:12 by pierre            #+#    #+#             */
/*   Updated: 2017/12/20 12:32:41 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}