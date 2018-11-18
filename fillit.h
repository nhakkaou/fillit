/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:55:20 by nhakkaou          #+#    #+#             */
/*   Updated: 2018/11/16 22:06:34 by ibouroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int relation;
}				t_point;
typedef struct	s_form
{
	t_point p1;
	t_point	p2;
	t_point p3;
	t_point p4;
	char	alpha;
}				t_form;

void			ft_error1(void);
void			ft_error(void);
t_form			i_form(void);
void			lien(t_form *form, int i);
void			affiche_plan(char **plan, int size);
char			**remove_from_plan(char **plan, t_form form, t_point coord);
int				solve(char **plan, t_form tab[26], t_point m, t_point v);
t_point			i_point(int z);
int				check(int fd, t_form tab[26], int j);
void			change_position(t_form *form);
t_form			create_form(char valid_str[20]);
t_point			find_place(char **plan, t_form form, t_point v, t_point size);
void			ft_strl(int fd, t_point *m);
int				ft_sqrt(int nb);
char			**creat_plan(int size);
char			**add(t_form form, char **plan, t_point t);
int				ft_test(t_form form, t_point t, int size);
t_point			calc_translation(t_point n, t_point y);

#endif
