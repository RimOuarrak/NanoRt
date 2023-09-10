/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 03:31:28 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/09/09 16:19:07 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

t_sphere	*sp_last(t_sphere *lst)
{
	t_sphere	*l;

	if (!lst)
		return (NULL);
	l = lst;
	while (l -> next != NULL)
	{
		l = l -> next;
	}
	return (l);
}

t_sphere	*sp_new(char	*str)
{
	t_sphere	*l;
	char	**tab;
	char	**pos;
	char	**rgb;

	l = malloc (sizeof(t_sphere));
	if (!l)
		return (NULL);
	tab = ft_split(str, ' ');
	pos = ft_split(tab[1], ',');
	l->position.x = str_to_double(pos[0]);
	l->position.y = str_to_double(pos[1]);
	l->position.z = str_to_double(pos[2]);
    l->diameter = str_to_double(tab[2]);
	rgb = ft_split(tab[3], ',');
	l->color.r = ft_atoi(rgb[0]);
	l->color.g = ft_atoi(rgb[1]);
	l->color.b = ft_atoi(rgb[2]);
	l -> next = NULL;
	free_split(tab);
	free_split(rgb);
	free_split(pos);
	return (l);
}

void	sp_add_back(t_sphere **lst, t_sphere *new)
{
	t_sphere	*l;

	if (!*lst)
		*lst = new;
	else
	{

		l = sp_last(*lst);
		l -> next = new;
	}
}