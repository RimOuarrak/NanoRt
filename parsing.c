/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:38:57 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/09/02 04:03:19 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

void	fill_a(char	*str, t_scene *scene)
{
	char	**tab;
	char	**rgb;
	
	tab = ft_split(str, ' ');
	scene->a_light->ratio = str_to_double(tab[1]);
	rgb = ft_split(tab[2], ',');
	scene->a_light->color.r = ft_atoi(rgb[0]);
	scene->a_light->color.g = ft_atoi(rgb[1]);
	scene->a_light->color.b = ft_atoi(rgb[2]);
	//FREE SPLITS
}

void	fill_elm(char	**tab, t_scene *scene)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], "A", 1))
				fill_a(tab[i], scene);
		else if (!ft_strncmp(tab[i], "C", 1))
				printf("%s", tab[i]);
		else if (!ft_strncmp(tab[i], "L", 1))
				printf("%s", tab[i]);
		else if (!ft_strncmp(tab[i], "pl", 2))
				printf("%s", tab[i]);
		else if (!ft_strncmp(tab[i], "sp", 2))
				printf("%s", tab[i]);
		else if (!ft_strncmp(tab[i], "cy", 2))
				printf("%s", tab[i]);
		// free_split(str);
		i++;
	}
}
void	init_struct(t_scene *scene)
{
	scene->a_light = ft_calloc(1, sizeof(t_ambient_light));
	scene->cameras = ft_calloc(1, sizeof(t_camera));
	scene->lights = ft_calloc(1, sizeof(t_light));
	scene->planes = ft_calloc(1, sizeof(t_plane));
	scene->spheres = ft_calloc(1, sizeof(t_sphere));
	scene->cylinders = ft_calloc(1, sizeof(t_cylinder));
}

int main(int ac, char **av)
{
	char	**file_tab;
	t_scene	*scene;

	if (ac == 2)
	{	
		file_tab = read_file(av[1]);
		if (!file_tab)
		{
			printf("Error\nThe .rt file is empty\n");
			return (0);
		}
		supervisor(file_tab);
		scene = ft_calloc(1 ,sizeof(t_scene));
		init_struct(scene);
		fill_elm(file_tab, scene);
	}
    return(0);
}