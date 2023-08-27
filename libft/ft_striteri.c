/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:16:52 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/16 16:06:37 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	while (i < l)
	{
		f(i, s++);
		i++;
	}
}
