/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:33:13 by nhakkaou          #+#    #+#             */
/*   Updated: 2018/11/16 21:56:56 by ibouroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strl(int fd, t_point *m)
{
	static int	i;
	int			ret;
	char		*str;
	char		buf[5];

	i = 0;
	str = ft_strnew(0);
	while ((ret = read(fd, buf, 4)))
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	while (str[i])
		i++;
	i++;
	i = i / 21;
	m->x = i;
	m->y = ft_sqrt(m->x * 4);
}

int		ft_sqrt(int nb)
{
	int racine;

	if (nb < 0)
	{
		return (0);
	}
	racine = 1;
	while (racine * racine < nb)
	{
		racine++;
	}
	if (racine * racine == nb)
	{
		return (racine);
	}
	return (racine);
}

int		ft_test(t_form form, t_point t, int size)
{
	if (!((form.p1.x - t.x >= 0 && form.p1.x - t.x < size) &&
	(form.p2.x - t.x >= 0 && form.p2.x - t.x < size) &&
	(form.p3.x - t.x >= 0 && form.p3.x - t.x < size) &&
	(form.p4.x - t.x >= 0 && form.p4.x - t.x < size)))
		return (0);
	if (!((form.p1.y - t.y >= 0 && form.p1.y - t.y < size) &&
	(form.p2.y - t.y >= 0 && form.p2.y - t.y < size) &&
	(form.p3.y - t.y >= 0 && form.p3.y - t.y < size) &&
	(form.p4.y - t.y >= 0 && form.p4.y - t.y < size)))
		return (0);
	return (1);
}
