/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchancri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 19:36:20 by lchancri          #+#    #+#             */
/*   Updated: 2018/06/13 20:18:13 by lchancri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESASM_H
# define DESASM_H
# include <unistd.h>
# include <fcntl.h>
# include "../libft/include/libft.h"
# include "op.h"

typedef struct		s_file
{
	int				place;
	char			c;
	struct s_file	*next;
}					t_file;

int					create_num(t_file *file, int type, int fd, int size);
int					write_live(t_file *file, int fd);
int					write_ld(t_file *file, int fd);
int					write_st(t_file *file, int fd);
int					write_add(t_file *file, int fd);
int					write_sub(t_file *file, int fd);
int					write_and(t_file *file, int fd);
int					write_or(t_file *file, int fd);
int					write_xor(t_file *file, int fd);
int					write_zjmp(t_file *file, int fd);
int					write_ldi(t_file *file, int fd);
int					write_sti(t_file *file, int fd);
int					write_fork(t_file *file, int fd);
int					write_lld(t_file *file, int fd);
int					write_lldi(t_file *file, int fd);
int					write_lfork(t_file *file, int fd);
int					write_aff(t_file *file, int fd);
int					write_enc(t_file *file, int fd, int dir, int size);
t_file				*stock_file(char c, int place);
void				create_file(t_file *file, char *name);
#endif
