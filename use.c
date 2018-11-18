/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rel.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:31:43 by ibouroum          #+#    #+#             */
/*   Updated: 2018/11/18 17:48:13 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error1(void)
{
	ft_putstr("usage:	./fillit source_file\n");
	exit(-1);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}

t_form	i_form(void)
{
	t_form form;

	form.p1.relation = 0;
	form.p2.relation = 0;
	form.p3.relation = 0;
	form.p4.relation = 0;
	return (form);
}

void	lien(t_form *form, int i)
{
	(i == 1) ? form->p1.relation++ : 1 == 1;
	(i == 2) ? form->p2.relation++ : 1 == 1;
	(i == 3) ? form->p3.relation++ : 1 == 1;
	(i == 4) ? form->p4.relation++ : 1 == 1;
}

t_point	calc_translation(t_point n, t_point y)
{
	t_point x;

	x.x = n.x - y.x;
	x.y = n.y - y.y;
	return (x);
}
