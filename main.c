/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:10:17 by ibouroum          #+#    #+#             */
/*   Updated: 2018/11/16 22:02:58 by ibouroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_form	tab[26];
	char	**plan;
	t_point	m;
	t_point v;

	m = i_point(0);
	plan = NULL;
	(argc != 2) ? ft_error1() : 1 == 1;
	v = i_point(0);
	fd = open(argv[1], O_RDONLY);
	if (check(fd, tab, 0) && argc)
	{
		fd = open(argv[1], O_RDONLY);
		ft_strl(fd, &m);
		plan = creat_plan(m.y);
		while ((solve(plan, tab, m, v)) == 0)
		{
			plan = creat_plan(++m.y);
			v = i_point(0);
		}
	}
	affiche_plan(plan, m.y);
	close(fd);
	return (0);
}

int	solve(char **plan, t_form tab[26], t_point m, t_point v)
{
	t_point noob;

	if (v.z == m.x)
		return (1);
	noob = find_place(plan, tab[v.z], v, m);
	if (noob.x != m.y || noob.y != m.y)
	{
		if (solve(plan, tab, m, i_point(v.z + 1)) == 0)
		{
			remove_from_plan(plan, tab[v.z], noob);
			noob.y++;
			if (noob.y == m.y)
			{
				noob.y = 0;
				noob.x++;
			}
			noob.z = v.z;
			return (solve(plan, tab, m, noob));
		}
	}
	else
		return (0);
	return (1);
}
