/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhakkaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:37:44 by nhakkaou          #+#    #+#             */
/*   Updated: 2018/10/10 21:59:16 by nhakkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fraiche;
	int		i;

	if (s != NULL)
	{
		fraiche = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (fraiche == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			fraiche[i] = f(i, s[i]);
			i++;
		}
		fraiche[ft_strlen(s)] = '\0';
		return (fraiche);
	}
	return (0);
}
