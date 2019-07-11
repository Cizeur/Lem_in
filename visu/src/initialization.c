/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:26:31 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/11 18:29:08 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void     inizialization(t_master *mstr)
{
    int     i;

    i = 0;
    mstr->start_index = -1;
    mstr->end_index = -1;
    mstr->nb_nodes = 0;
    mstr->nb_pipes = 0;
    if (!(mstr->nodes_array = (t_nodes**)ft_memalloc(sizeof(t_nodes*) * mstr->nb_nodes)))
        ft_exit(ERROR_MALLOC);
    if (!(mstr->pipes_array = (t_pipes**)ft_memalloc(sizeof(t_pipes*) * mstr->nb_pipes)))
        ft_exit(ERROR_MALLOC);
    while (i < mstr->nb_nodes)
    {
        if (!(mstr->nodes_array[i] = (t_nodes*)ft_memalloc(sizeof(t_nodes))))
            ft_exit(ERROR_MALLOC);
        if (!(mstr->nodes_array[i]->pipes = (int*)ft_memalloc(sizeof(int) * mstr->nb_nodes)))
            ft_exit(ERROR_MALLOC);
        i++;
    }
    i = 0;
    while (i < mstr->nb_pipes)
    {
        if (!(mstr->pipes_array[i] = (t_pipes*)ft_memalloc(sizeof(t_nodes*))))
            ft_exit(ERROR_MALLOC);
        
        i++;
    }
    /*
    ***     Here we'll nedd to alloc for the movements
    */
}