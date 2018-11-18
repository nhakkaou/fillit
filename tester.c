/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 12:53:30 by nhakkaou          #+#    #+#             */
/*   Updated: 2018/11/14 23:35:59 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_form	i1_form(void)
{
	t_form form;

	form.p1.relation = 0;
	form.p2.relation = 0;
	form.p3.relation = 0;
	form.p4.relation = 0;
	return (form);
}

t_point			i_point(int z)
{
	t_point point;

	point.x = 0;
	point.y = 0;
	point.relation = 0;
	point.z = z;
	return (point);
}

t_form			create_form(char valid_str[20])
{
	t_form		form;
	t_point		counter;
	int			k;
	static int	alpha = 64;

	counter = i_point(0);
	form = i1_form();
	k = 0;
	form.alpha = (char)++alpha;
	while (counter.x < 20)
	{
		if (valid_str[counter.x] != '\n' && valid_str[counter.x] == '#')
		{
			(k == 0) ? form.p1.y = counter.y % 4 : 1 == 1;
			(k == 0) ? form.p1.x = counter.y / 4 : 1 == 1;
			(k == 1) ? form.p2.y = counter.y % 4 : 1 == 1;
			(k == 1) ? form.p2.x = counter.y / 4 : 1 == 1;
			(k == 2) ? form.p3.y = counter.y % 4 : 1 == 1;
			(k == 2) ? form.p3.x = counter.y / 4 : 1 == 1;
			(k == 3) ? form.p4.y = counter.y % 4 : 1 == 1;
			(k++ == 3) ? form.p4.x = counter.y / 4 : 1 == 1;
		}
		(valid_str[counter.x++] != '\n') ? counter.y++ : 1 == 1;
	}
	return (form);
}
