/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:38:57 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/09/04 00:52:15 by rimouarrak       ###   ########.fr       */
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

void	fill_c(char	*str, t_scene *scene)
{
	char	**tab;
	char	**pos;
	char	**ort;
	
	tab = ft_split(str, ' ');
	pos = ft_split(tab[1], ',');
	scene->cameras->position.x = ft_atoi(pos[0]);
	scene->cameras->position.y = ft_atoi(pos[1]);
	scene->cameras->position.z = ft_atoi(pos[2]);
	ort = ft_split(tab[2], ',');
	scene->cameras->orientation.x = ft_atoi(ort[0]);
	scene->cameras->orientation.y = ft_atoi(ort[1]);
	scene->cameras->orientation.z = ft_atoi(ort[2]);
	scene->cameras->fov = ft_atoi(tab[3]);
	//FREE SPLITS
}

void	fill_l(char	*str, t_scene *scene)
{
	char	**tab;
	char	**pos;
	char	**rgb;
	
	tab = ft_split(str, ' ');
	pos = ft_split(tab[1], ',');
	scene->lights->position.x = ft_atoi(pos[0]);
	scene->lights->position.y = ft_atoi(pos[1]);
	scene->lights->position.z = ft_atoi(pos[2]);
	scene->lights->ratio = str_to_double(tab[2]);
	rgb = ft_split(tab[3], ',');
	scene->lights->color.r = ft_atoi(rgb[0]);
	scene->lights->color.g = ft_atoi(rgb[1]);
	scene->lights->color.b = ft_atoi(rgb[2]);

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
				fill_c(tab[i], scene);
		else if (!ft_strncmp(tab[i], "L", 1))
				fill_l(tab[i], scene);
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