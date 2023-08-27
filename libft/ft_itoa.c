/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:38:47 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/21 18:27:47 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cal(int n)
{
	int		l;

	l = 0;
	if (n < 0)
		l = 1;
	while (n)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		l;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = cal(n);
	p = malloc (l + 1);
	if (!p)
		return (0);
	if (n < 0)
	{
		n *= -1;
		p[0] = '-';
	}
	p[l--] = '\0';
	while (n)
	{
		p[l] = (n % 10) + 48;
		n = n / 10;
		l--;
	}
	return (p);
}

// int	main ()
// {
// 	printf("%s", ft_itoa(0));
// }