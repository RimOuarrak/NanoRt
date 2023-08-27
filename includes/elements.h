/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:38:20 by aminebeihaq       #+#    #+#             */
/*   Updated: 2023/08/27 16:23:00 by rimouarrak       ###   ########.fr       */
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
}	t_sphere;

typedef struct s_plane {
	t_vector	position;
	t_vector	normal;
	t_trgb		color;
}	t_plane;

typedef struct s_cylinder {
	t_vector	position;
	t_vector	normal;
	double		diameter;
	double		height;
	t_trgb		color;
}	t_cylinder;

#endif