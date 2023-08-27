/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:59:13 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/18 18:29:17 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	ctn;
	int	size;

	i = 0;
	ctn = -1;
	size = ft_strlen(s);
	if (!s)
		return (0);
	while (i <= size)
	{
		if (s[i] == (const char)c)
			ctn = i;
		i++;
	}
	if (ctn >= 0)
		return ((char *)&s[ctn]);
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char *src = "abbbbbbbb";
// 	char *d1 = strrchr(src, 'z');
// 	char *d2 = ft_strrchr(src, 'z');
// 	printf("%s\n", d1);
// 	printf("%s\n", d2);
// }
// #include <stdio.h>

// int main()
// {
// 	printf("dyali:%s\n", ft_strrchr("teste",'e'));
// 	printf("dyalhom:%s\n", strrchr("teste",'e'));
// }