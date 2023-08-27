/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:10:09 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/16 15:12:23 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;
	int		l;

	if (!s)
		return (0);
	i = 0;
	l = ft_strlen(s);
	p = malloc (l + 1);
	if (!p)
		return (0);
	while (i < l)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
