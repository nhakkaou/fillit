/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:45:40 by ibouroum          #+#    #+#             */
/*   Updated: 2018/11/16 22:06:09 by ibouroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	test1(char *str)
{
	int	i;
	int	j;
	int c;

	j = 0;
	i = 0;
	c = 0;
	while (i < 20)
	{
		while (str[i] != '\n' && i < 20)
			i++;
		if (i != j + 4)
			ft_error();
		if (str[i] == '\n')
			c++;
		j = i + 1;
		i++;
	}
	if (c > 5)
		ft_error();
	return (1);
}

static int	test2(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			j++;
		i++;
	}
	if (j != 4)
		ft_error();
	return (1);
}

static int	test3(char valid_str[20], t_form form)
{
	t_point i;

	i.x = 0;
	i.y = 1;
	while (valid_str[i.x] != '\0')
	{
		if (valid_str[i.x] == '#')
		{
			if (i.y <= 4)
			{
				(valid_str[i.x + 1] == '#') ? lien(&form, i.y) : 1 == 1;
				(valid_str[i.x - 1] == '#') ? lien(&form, i.y) : 1 == 1;
				(valid_str[i.x + 5] == '#') ? lien(&form, i.y) : 1 == 1;
				(valid_str[i.x - 5] == '#') ? lien(&form, i.y) : 1 == 1;
			}
			i.y++;
		}
		i.x++;
	}
	if ((form.p1.relation >= 2 || form.p2.relation >= 2 || form.p3.relation >= 2
	|| form.p4.relation >= 2) && (form.p1.relation >= 1 && form.p2.relation >= 1
	&& form.p3.relation >= 1 && form.p4.relation >= 1))
		return (1);
	ft_error();
	return (0);
}

char		*test4(int fd)
{
	char	*str;
	char	buf[5];
	int		ret;
	int		i;

	i = 0;
	str = ft_strnew(0);
	(fd < 0) ? ft_error() : 1 == 1;
	while ((ret = read(fd, buf, 4)))
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (*str == '\0')
		ft_error();
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			ft_error();
		i++;
	}
	return (str);
}

int			check(int fd, t_form t[26], int j)
{
	static char	*str;
	char		valid[20];
	t_form		form;

	form = i_form();
	str = test4(fd);
	if (str[ft_strlen(str) - 1] == '\n' && str[ft_strlen(str) - 2] == '\n')
		ft_error();
	while (*str)
	{
		if (str[0] == '\n')
			ft_error();
		test1(str);
		test2(str);
		ft_strncpy(valid, str, 20);
		test3(valid, form);
		str = ft_strdup(str + 21);
		t[j++] = create_form(valid);
		if (j > 26)
			ft_error();
	}
	return (1);
}
