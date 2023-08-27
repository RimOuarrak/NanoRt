/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:39:49 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/08/27 19:33:04 by rimouarrak       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.h"

static void elem_dup_error(int cptA, int cptC, int cptL)
{
    if (cptA == 0 || cptC == 0 || cptL == 0)
    {
        printf("Error\nThere is a missing element\n");
        exit (0);
    }
    if (cptA > 1 || cptC > 1 || cptL > 1)
    {
        printf("Error\nElements that start with an uppercase letter can only be declared once in the scene.\n");
        exit (0);
    }
}

void check_elem_dup(char **tab)
{
    int cptA;
    int cptC;
    int cptL;

    cptA = 0;
    cptC = 0;
    cptL = 0;
    while (*tab)
    {
        if (**tab == 'A')
            cptA++;
        else if (**tab == 'C')
            cptC++;
        else if (**tab == 'L')
            cptL++;
        tab++;
    }
    elem_dup_error(cptA, cptC, cptL);
}
static int	make_set(char *str)
{
	int	i;
	int	cpt;
	char	**set;

	i = 0;
	cpt = 0;
	set = malloc((6 + 1)* sizeof(char));
	set[0] = ft_strdup("A");
	set[1] = ft_strdup("C");
	set[2] = ft_strdup("L");
	set[3] = ft_strdup("pl");
	set[4] = ft_strdup("sp");
	set[5] = ft_strdup("cy");
	set[6] = NULL;
	while (set[i])
	{
		if (!ft_strcmp(str, set[i]))
			cpt++;
		i++;
	}
	return (cpt);
}

void	check_imposter(char **tab)
{
	int	i;
	int	j;
	char	**str;

	i = 0;
	while (tab[i])
	{
		str = ft_split(tab[i], ' ');
		make_set(str[0]);
		if (!make_set(str[0]))
		{
			printf("Error\nThere is an unknown element\n");
			exit (0);
		}
		// free_split(str);
		i++;
	}
}
void check_elements(char	**tab)
{
	check_imposter(tab);
    check_elem_dup(tab);
}
