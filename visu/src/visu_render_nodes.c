/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:13:58 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 19:15:21 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

float   ratio(t_master *mstr, char exe, int i)
{
    float       ratio;

    if (exe == 'x')
    {
        if (mstr->max_x == mstr->min_x)
            ratio = 0.5;
        else
            ratio = (float)((double)(mstr->nodes_array[i]->x - mstr->min_x)
            / (double)(mstr->max_x - mstr->min_x));
    }
    if (exe == 'y')
    {
        if (mstr->max_y == mstr->min_y)
            ratio = 0.5;
        else
            ratio = (float)((double)(mstr->nodes_array[i]->y - mstr->min_y)
            / (double)(mstr->max_y - mstr->min_y));
    }
    return (ratio);
}

int     render_nodes(t_master *mstr)
{
    int         i;
    SDL_Rect    node;

    i = 0;
    node.w = 20;
    node.h = 20;
    while (i < mstr->nb_nodes)
    {
        if (mstr->nodes_array[i]->x_px == FALSE)
        {
            node.x = (S_WIDTH * 0.05) + (ratio(mstr, 'x', i) * S_WIDTH * 0.9);
            mstr->nodes_array[i]->x_px = node.x + 10;
        }
        if (mstr->nodes_array[i]->y_px == FALSE)
        {
            node.y = (S_HEIGHT * 0.05) + (ratio(mstr, 'y', i) * S_HEIGHT * 0.9);
            mstr->nodes_array[i]->y_px = node.y + 10;
        }
        node.x = mstr->nodes_array[i]->x_px;
        node.y = mstr->nodes_array[i]->y_px;
        SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
        if (mstr->nodes_array[i]->flag == NODE_NOTHING)
            if (SDL_RenderFillRect(mstr->render, &node) == FALSE)
                return (ft_exit(mstr, RENDER_VISU));
        i++;
    }
    return (TRUE);
}