/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:26:31 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/22 16:07:01 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     inizialization(t_master *mstr)
{
    int     i;

    i = 0;
    mstr->start_index = -1;
    mstr->end_index = -1;
    mstr->current_node = 0;
    mstr->current_pipe = 0;
    mstr->max_x = -2147483648;
    mstr->min_x = 2147483647;
    mstr->max_y = -2147483648;
    mstr->min_y = 2147483647;
    if (!(mstr->nodes_array = (t_nodes**)ft_memalloc(sizeof(t_nodes*) * mstr->nb_nodes)))
        return (ft_exit(ERROR_MALLOC));
    if (!(mstr->pipes_array = (t_pipes**)ft_memalloc(sizeof(t_pipes*) * mstr->nb_pipes)))
        return (ft_exit(ERROR_MALLOC));
    while (i < mstr->nb_nodes)
    {
        if (!(mstr->nodes_array[i] = (t_nodes*)ft_memalloc(sizeof(t_nodes))))
            return (ft_exit(ERROR_MALLOC));
        if (!(mstr->nodes_array[i]->pipes = (int*)ft_memalloc(sizeof(int) * mstr->nb_nodes)))
            return (ft_exit(ERROR_MALLOC));
        mstr->nodes_array[i]->nb_pipes = 0;
        mstr->nodes_array[i]->flag = NODE_NOTHING;
        i++;
    }
    i = 0;
    while (i < mstr->nb_pipes)
    {
        if (!(mstr->pipes_array[i] = (t_pipes*)ft_memalloc(sizeof(t_pipes))))
            return (ft_exit(ERROR_MALLOC));
        mstr->pipes_array[i]->active = PIPE_ACTIVE;
        i++;
    }
    // i = 0;
    // while (i < mstr->nb_movements)
    // {
    //     if (!(mstr->pipes_array[i] = (t_pipes*)ft_memalloc(sizeof(t_pipes))))
    //         ft_exit(ERROR_MALLOC);
    // }
    return (TRUE);
}