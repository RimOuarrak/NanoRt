/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:54:48 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:08 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sghir(unsigned long long n1, unsigned long long n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;
	size_t			m;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup (""));
	else
		m = sghir(ft_strlen(s) - start, len);
	str = malloc(m + 1);
	if (!str)
		return (NULL);
	while (s[start + i] && i < m)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
