/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:38:57 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/09/10 19:46:36 by rimouarrak       ###   ########.fr       */
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
	free_split(tab);
	free_split(rgb);
}

void	fill_c(char	*str, t_scene *scene)
{
	char	**tab;
	char	**pos;
	char	**ort;

	tab = ft_split(str, ' ');
	pos = ft_split(tab[1], ',');
	scene->cameras->position.x = str_to_double(pos[0]);
	scene->cameras->position.y = str_to_double(pos[1]);
	scene->cameras->position.z = str_to_double(pos[2]);
	ort = ft_split(tab[2], ',');
	scene->cameras->orientation.x = str_to_double(ort[0]);
	scene->cameras->orientation.y = str_to_double(ort[1]);
	scene->cameras->orientation.z = str_to_double(ort[2]);
	scene->cameras->fov = ft_atoi(tab[3]);
	free_split(tab);
	free_split(pos);
	free_split(ort);
}

void	fill_l(char	*str, t_scene *scene)
{
	char	**tab;
	char	**pos;
	char	**rgb;

	tab = ft_split(str, ' ');
	pos = ft_split(tab[1], ',');
	scene->lights->position.x = str_to_double(pos[0]);
	scene->lights->position.y = str_to_double(pos[1]);
	scene->lights->position.z = str_to_double(pos[2]);
	scene->lights->ratio = str_to_double(tab[2]);
	rgb = ft_split(tab[3], ',');
	scene->lights->color.r = ft_atoi(rgb[0]);
	scene->lights->color.g = ft_atoi(rgb[1]);
	scene->lights->color.b = ft_atoi(rgb[2]);
	free_split(tab);
	free_split(rgb);
	free_split(pos);
}

void	fill_pl(char	*str, t_scene *scene)
{
	t_plane	*plane;

	plane = pl_new(str);
	if (!scene->planes->flag)
	{
		scene->planes = plane;
		// scene->planes->flag = 1;
	}
	else
		pl_add_back(&scene->planes, plane);
}

void	fill_sp(char	*str, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = sp_new(str);
	if (!scene->spheres->flag)
	{
		scene->spheres = sphere;
		// scene->t_spheres->flag = 1;
	}
	else
		sp_add_back(&scene->spheres, sphere);
}

void	fill_cy(char	*str, t_scene *scene)
{
	t_cylinder	*cylinder;

	cylinder = cy_new(str);
	if (!scene->cylinders->flag)
	{
		scene->cylinders = cylinder;
		// scene->t_cylinders->flag = 1;
	}
	else
		cy_add_back(&scene->cylinders, cylinder);
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
			fill_pl(tab[i], scene);
		else if (!ft_strncmp(tab[i], "sp", 2))
			fill_sp(tab[i], scene);
		else if (!ft_strncmp(tab[i], "cy", 2))
			fill_cy(tab[i], scene);
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

int	main(int ac, char **av)
{
	char	**file_tab;
	t_scene	*scene;

	if (ac == 2)
	{
		file_tab = read_file(av[1]);
		if (!file_tab)
		{
			printf("Error\nThe .rt file is empty or unexisting\n");
			return (0);
		}
		supervisor(file_tab);
		scene = ft_calloc(1, sizeof(t_scene));
		init_struct(scene);
		fill_elm(file_tab, scene);
		system("leaks nanort");
		// printf("res ,, %f\n", scene->cylinders->diameter);
		// printf("res ,, %f\n", scene->cylinders->next->diameter);
		// printf("res ,, %p\n", scene->spheres->next->next);
		// printf("next ,, %d\n", scene->planes->next->color.r);
		// printf("%p\n", scene->planes->next->next);
	}
	return (0);
}
