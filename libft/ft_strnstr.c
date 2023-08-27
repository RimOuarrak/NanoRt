/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:08:20 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/18 00:02:43 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0' && len == 0)
		return ((char *)haystack);
	else if (!len)
		return (NULL);
	else if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
	i++;
	}
	return (NULL);
}

// #include<string.h>
// #include<stdio.h>
// int main()
// {
// 	char	*i1 = strnstr("empty", "", 8);
// 	char	*i2 = ft_strnstr("empty", "", 8);

// 	printf("strnstr -----> %s\n" , i1);
// 	printf("ft_strnstr -----> %s\n" , i2);
// }
