/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:48:33 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/15 05:00:17 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	*s;

	i = 0;
	if (n <= 0)
		return (0);
	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n - 1 && f[i] == s[i])
		i++;
	return (f[i] - s[i]);
}
