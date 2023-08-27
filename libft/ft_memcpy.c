/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:19:39 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/15 00:04:09 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	if (dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
	//if (!dst)
	//	return (0);