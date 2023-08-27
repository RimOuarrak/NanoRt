/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:46:17 by rouarrak          #+#    #+#             */
/*   Updated: 2023/08/27 17:58:24 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_word(const char *s, char c)
{
	int	i;
	int	ctn;

	i = 0;
	ctn = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i + 1] == '\0' || (s[i] == c && s[i + 1] != c))
			ctn++;
		i++;
	}
	return (ctn);
}

static int	nl(int i, const char *s, char c)
{
	int	ctn;

	ctn = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		ctn++;
		i++;
	}
	return (ctn);
}

static char	*eamar(int i, const char *s, char *p, char c)
{
	int	j;
	int	n;

	j = 0;
	n = nl (i, s, c);
	p = malloc (n + 1);
	if (!p)
		return (NULL);
	while (j < n)
	{
		p[j] = s[i];
		j++;
		i++;
	}
	p[j] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (0);
	p = malloc ((n_word(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (i < n_word(s, c))
	{
		while (s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			p[i] = eamar(j, s, p[i], c);
			i++;
		}
		j += nl (j, s, c);
	}
	p[i] = NULL;
	return (p);
}
