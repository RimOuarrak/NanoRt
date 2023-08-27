/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 02:40:46 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/17 01:10:33 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// int main ()
// {
// 		char *big = "abcdef";
// 	char *little = "abcdefghijklmnop";
// 	printf ("%d\n", strncmp (big,little,6));
// 	printf ("%d\n", ft_strncmp (big,little,6));
// }