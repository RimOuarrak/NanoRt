/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:40:20 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/09/10 19:48:36 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "elements.h"
# include "vector.h"
# include "color.h"

typedef struct s_scene
{
	t_ambient_light	*a_light;
	t_camera		*cameras;
	t_light			*lights;
	t_plane			*planes;
	// t_list	*triangles;
	t_sphere		*spheres;
	// t_list	*squares;
	t_cylinder		*cylinders;
}	t_scene;

char	*get_next_line(int fd);
void	free_split(char **split);
double	str_to_double(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		n_lines(int fd);
int		nospace_strlen(char *str);
char	*rm_space(char *str);
char	**read_file(char *file);
void	check_elem_dup(char **tab);
void	check_elements(char **tab);
int		param_num(char *str);
void	supervisor(char	**tab);

#endif