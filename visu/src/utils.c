/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:30:00 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/27 20:51:02 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     ft_str_cmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1[i] == '\0' && s2[i] == '\0')
        return (TRUE);
    return (FALSE);
}

int     ft_get_index_node(t_master *mstr, char *name)
{
    int     i;

    i = 0;
    while (i < mstr->nb_nodes)
    {
        if (ft_str_cmp(mstr->nodes_array[i]->name, name) == TRUE)
            return (i);
        i++;
    }
    return (ft_exit(INVALID_NAME));
}