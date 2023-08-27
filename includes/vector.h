/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:56:07 by aminebeihaq       #+#    #+#             */
/*   Updated: 2023/08/27 16:24:32 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "parsing.h"

typedef struct s_pixel
{
	int	x;
	int	y;
}	t_pixel;

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

// float		dot_product(t_vector vector1, t_vector vector2);

// t_vector	cross_product(t_vector vector1, t_vector vector2);

// t_vector	normalize_vector(t_vector vector);

// t_vector	vector_addition(t_vector vector1, t_vector vector2);

// t_vector	vector_subtraction(t_vector vector1, t_vector vector2);

// t_vector	vector_division(t_vector vector, float scalar);

// float		vector_magnitude(t_vector vector);

#endif