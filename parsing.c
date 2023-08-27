/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:38:57 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/08/27 23:10:36 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

int main(int ac, char **av)
{
	char	*line;
	char	**file_tab;
	int	fd;
	int	l;
	int	i;

	if (ac == 2)
	{	
		// fd = open(av[1], O_RDONLY, 0777);
		// l = n_lines(fd);
		// close (fd);
		// printf("%s\n", rm_space(cc));
		file_tab = read_file(av[1]);
		if (!file_tab)
		{
			printf("Error\nThe .rt file is empty\n");
			return (0);
		}
		i = 0;
		supervisor(file_tab);
		// while (file_tab[i])
		// {
		// 	printf("%s", file_tab[i]);
		// 	i++;
		// }
		// system("leaks nanort");
		// fd = open(av[1], O_RDONLY, 0777);
		// line = get_next_line(fd);
		// i = 0;
		// while (line)
		// {
			
		// 	printf("%s", line);
		// 	free(line);
		// 	line = get_next_line(fd);
		// }
	}
    return(0);
}