/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:38:20 by aminebeihaq       #+#    #+#             */
/*   Updated: 2023/09/04 03:39:57 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "parsing.h"
# include "vector.h"
# include "color.h"

typedef struct s_ambient_light {
	double	ratio;
	t_trgb	color;
}	t_ambient_light;

typedef struct s_camera {
	t_vector		position;
	t_vector		orientation;
	unsigned int	fov;
}	t_camera;

typedef struct s_light {
	t_vector	position;
	double		ratio;
	t_trgb		color;
}	t_light;

typedef struct s_sphere {
	t_vector	position;
	double		diameter;
	t_trgb		color;
	int			flag;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane {
	t_vector	position;
	t_vector	normal;
	t_trgb		color;
	int			flag;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder {
	t_vector	position;
	t_vector	normal;
	double		diameter;
	double		height;
	t_trgb		color;
	struct s_cylinder	*next;
}	t_cylinder;

// i think i will remove this later
void    check_a(char *str);
t_plane	*pl_last(t_plane *lst);
t_plane	*pl_new(char	*str);
void	pl_add_back(t_plane **lst, t_plane *new);
t_sphere	*sp_last(t_sphere *lst);
t_sphere	*sp_new(char	*str);
void	sp_add_back(t_sphere **lst, t_sphere *new);

#endif