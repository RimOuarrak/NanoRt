/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:14:35 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/21 18:07:41 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	exist(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	f;
	size_t	l;
	char	*p;
	size_t	i;

	if (!s1)
		return (0);
	i = 0;
	f = 0;
	l = ft_strlen (s1);
	while (exist (s1[f], set) == 1 && f < l)
			f++;
	while (exist (s1[l - 1], set) == 1 && l > f)
			l--;
	p = (char *)malloc (l - f + 1);
	if (!p)
		return (0);
	while (s1[i] && f < l)
	{
		p[i] = s1[f];
		f++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
