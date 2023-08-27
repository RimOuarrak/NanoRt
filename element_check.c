/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimouarrak <rimouarrak@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:39:49 by rimouarrak        #+#    #+#             */
/*   Updated: 2023/08/27 17:44:32 by rimouarrak       ###   ########.fr       */
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
void check_elements(char	**tab)
{
    check_elem_dup(tab);
}
