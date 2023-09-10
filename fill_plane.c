/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 01:19:20 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/09/09 16:18:42 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

t_plane	*pl_last(t_plane *lst)
{
	t_plane	*l;

	if (!lst)
		return (NULL);
	l = lst;
	while (l -> next != NULL)
	{
		l = l -> next;
	}
	return (l);
}

t_plane	*pl_new(char	*str)
{
	t_plane	*l;
	char	**tab;
	char	**pos;
	char	**rgb;
	char	**ort;

	l = malloc (sizeof(t_plane));
	if (!l)
		return (NULL);
	tab = ft_split(str, ' ');
	pos = ft_split(tab[1], ',');
	l->position.x = str_to_double(pos[0]);
	l->position.y = str_to_double(pos[1]);
	l->position.z = str_to_double(pos[2]);
	ort = ft_split(tab[2], ',');
	l->normal.x = str_to_double(ort[0]);
	l->normal.y = str_to_double(ort[1]);
	l->normal.z = str_to_double(ort[2]);
	rgb = ft_split(tab[3], ',');
	l->color.r = ft_atoi(rgb[0]);
	l->color.g = ft_atoi(rgb[1]);
	l->color.b = ft_atoi(rgb[2]);
	l -> next = NULL;
	free_split(tab);
	free_split(ort);
	free_split(rgb);
	free_split(pos);
	return (l);
}

void	pl_add_back(t_plane **lst, t_plane *new)
{
	t_plane	*l;

	if (!*lst)
		*lst = new;
	else
	{

		l = pl_last(*lst);
		l -> next = new;
	}
}