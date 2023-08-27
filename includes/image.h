/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:08:22 by aminebeihaq       #+#    #+#             */
/*   Updated: 2023/08/27 17:57:12 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file image.h
 * @brief Header file for image-related functions and structures.
 *
 * This file contains declarations for functions and structures related to
 * managing and manipulating images in graphics rendering.
 */

#ifndef IMAGE_H
# define IMAGE_H

# include "parsing.h"

typedef struct s_window	t_window;

/**
 * @brief Clear the image data in a graphics rendering window.
 *
 * This function sets all the pixel values in the image associated with the
 * given graphics rendering window to zero. The image data is effectively cleared.
 *
 * @param window Pointer to the graphics rendering window (t_window) to clear.
 */
void	clear_mlx_image(t_window *window);

#endif
