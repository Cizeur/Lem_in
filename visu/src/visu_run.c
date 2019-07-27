/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:50:19 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/27 21:56:35 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    draw_nodes(t_master *mstr, SDL_Rect node, int flag_node)
{
    SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
    if (flag_node == NODE_START || flag_node == NODE_END)
        SDL_SetRenderDrawColor(mstr->render, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(mstr->render, &node);
    SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawRect(mstr->render, &node);
    node.x -= 1;
    node.y -= 1;
    node.w += 2;
    node.h += 2;
    SDL_RenderDrawRect(mstr->render, &node);
    node.x -= 1;
    node.y -= 1;
    node.w += 2;
    node.h += 2;
    SDL_RenderDrawRect(mstr->render, &node);
}

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
        return (ratio);
    }
    if (exe == 'y')
    {
        if (mstr->max_y == mstr->min_y)
            ratio = 0.5;
        else
            ratio = (float)((double)(mstr->nodes_array[i]->y - mstr->min_y)
            / (double)(mstr->max_y - mstr->min_y));
        return (ratio);
    }
    return ((float)FALSE);
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
        node.x = (S_WIDTH * 0.05) + (ratio(mstr, 'x', i) * S_WIDTH * 0.9);
        node.y = (S_HEIGHT * 0.05) + (ratio(mstr, 'y', i) * S_HEIGHT * 0.9);
        mstr->nodes_array[i]->x_px = node.x;
        mstr->nodes_array[i]->y_px = node.y;
        draw_nodes(mstr, node, mstr->nodes_array[i]->flag);
        i++;
    }
    return (TRUE);
}

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

void   control(t_master *mstr)
{
    if (mstr->event_Quit.type == SDL_QUIT)
        mstr->flag_exit = TRUE;
}

int     vs_run(t_master *mstr)
{
    while (mstr->flag_exit == FALSE)
    {
        while (SDL_PollEvent(&mstr->event_Quit) != 0)
        {
            SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(mstr->render);
            render_texture(mstr, mstr->background, 0, 0);
            render_pipes(mstr);
            render_nodes(mstr);
            SDL_RenderPresent(mstr->render);
        }
        control(mstr);
    }
    return (TRUE);
}
