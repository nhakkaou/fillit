/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:29:45 by nhakkaou          #+#    #+#             */
/*   Updated: 2018/11/15 21:21:21 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**creat_plan(int size)
{
	char	**plan;
	int		i;
	int		j;

	i = 0;
	plan = malloc(sizeof(char *) * size);
	while (i < size)
	{
		j = 0;
		plan[i] = malloc(sizeof(char) * size);
		while (j < size)
		{
			plan[i][j] = '.';
			j++;
		}
		i++;
	}
	return (plan);
}

char	**add(t_form form, char **plan, t_point t)
{
	plan[form.p1.x - t.x][form.p1.y - t.y] = form.alpha;
	plan[form.p2.x - t.x][form.p2.y - t.y] = form.alpha;
	plan[form.p3.x - t.x][form.p3.y - t.y] = form.alpha;
	plan[form.p4.x - t.x][form.p4.y - t.y] = form.alpha;
	return (plan);
}

t_point	find_place(char **plan, t_form form, t_point v, t_point size)
{
	t_point t;

	t = calc_translation(form.p1, v);
	if (ft_test(form, t, size.y))
	{
		if (plan[form.p1.x - t.x][form.p1.y - t.y] == '.' &&
		plan[form.p2.x - t.x][form.p2.y - t.y] == '.' && plan[form.p3.x - t.x]
		[form.p3.y - t.y] == '.' &&
		plan[form.p4.x - t.x][form.p4.y - t.y] == '.')
		{
			add(form, plan, t);
			return (v);
		}
	}
	if (++v.y == size.y)
	{
		v.y = 0;
		v.x++;
	}
	if (v.x == size.y)
	{
		v.y = size.y;
		return (v);
	}
	return (find_place(plan, form, v, size));
}

char	**remove_from_plan(char **plan, t_form form, t_point coord)
{
	t_point moin;

	moin.y = form.p1.y - coord.y;
	moin.x = form.p1.x - coord.x;
	plan[form.p1.x - moin.x][form.p1.y - moin.y] = '.';
	plan[form.p2.x - moin.x][form.p2.y - moin.y] = '.';
	plan[form.p3.x - moin.x][form.p3.y - moin.y] = '.';
	plan[form.p4.x - moin.x][form.p4.y - moin.y] = '.';
	return (plan);
}

void	affiche_plan(char **plan, int size)
{
	int i;

	i = 0;
	while (i++ < size)
	{
		ft_putstr(plan[i - 1]);
		ft_putchar('\n');
	}
}
