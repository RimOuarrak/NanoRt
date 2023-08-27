/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:28:21 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/07 23:28:22 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t size)
{
	size_t	ctn;
	size_t	i;

	i = 0;
	ctn = 0;
	while (src[ctn])
		ctn++;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			if (src[i] != '\0')
			{
				dest[i] = src[i];
				i++;
			}
		}
		dest[i] = '\0';
	}
	return (ctn);
}
