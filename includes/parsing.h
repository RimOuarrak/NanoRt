/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:40:20 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/08/27 17:45:05 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H
#include <stdio.h>
#include <fcntl.h>
# include "../libft/libft.h"
#include "../gnl/get_next_line.h"

typedef struct s_info
{
    char    id;
    int     nl;
    
} t_info;

char	*get_next_line(int fd);
int	n_lines(int fd);
int	nospace_strlen(char *str);
char	*rm_space(char *str);
char	**read_file(char *file);
void    check_elem_dup(char **tab);
void check_elements(char	**tab);

#endif