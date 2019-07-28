/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:14:23 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 12:17:52 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    render_pipes(t_master *mstr)
{
    int         i;

    i = 0;
    while (i < mstr->nb_pipes)
    {
        SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
        thickLineRGBA(mstr->render,
            mstr->nodes_array[mstr->pipes_array[i]->node1_index]->x_px + 10,
            mstr->nodes_array[mstr->pipes_array[i]->node1_index]->y_px + 10,
            mstr->nodes_array[mstr->pipes_array[i]->node2_index]->x_px + 10,
            mstr->nodes_array[mstr->pipes_array[i]->node2_index]->y_px + 10,
            2, 0xFF, 0xFF, 0xFF, 0xFF);
        i++;
    }
    return (TRUE);
}