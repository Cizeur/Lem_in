/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:15:41 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/30 23:21:24 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    render_moves(t_master *mstr)
{
    int         i;
    float       x_step;
    float       y_step;
    int         x;
    int         y;
    t_moves     *current;

    i = 0;
    while (i <= 64)
    {
        current = mstr->moves_array[mstr->current_move];
        render_total_background(mstr);
        while (current != NULL)
        {
            x_step = (float)(mstr->nodes_array[current->node2_index]->x_px
                - mstr->nodes_array[current->node1_index]->x_px) / (float)64;
            y_step = (float)(mstr->nodes_array[current->node2_index]->y_px
                - mstr->nodes_array[current->node1_index]->y_px) / (float)64;
            x = mstr->nodes_array[current->node1_index]->x_px + (i * x_step);
            y = mstr->nodes_array[current->node1_index]->y_px + (i * y_step);
            SDL_SetRenderDrawColor(mstr->render, 0x00, 0xFF, 0x00, 0xFF);
            if (render_texture(mstr, mstr->textures[current->ant_index % 8], x - 20, y - 20)  == FALSE)
                return (FALSE);
            if (control(mstr) == FALSE)
                return (FALSE);
            current = current->next;
        }
        SDL_RenderPresent(mstr->render);
        SDL_Delay(20);
        i++;
    }
    return(TRUE);
}