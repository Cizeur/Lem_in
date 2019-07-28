/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:15:41 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 16:44:29 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    render_moves(t_master *mstr)
{
    int         i;
    float       x_step;
    float       y_step;
    SDL_Rect    node;
    t_moves     *current;

    i = 0;
    node.w = 20;
    node.h = 20;
    while (i <= 100)
    {
        current = mstr->moves_array[mstr->current_move];
        render_total_background(mstr);
        while (current != NULL)
        {
            x_step = (float)(mstr->nodes_array[current->node2_index]->x_px
                - mstr->nodes_array[current->node1_index]->x_px) / (float)100;
            y_step = (float)(mstr->nodes_array[current->node2_index]->y_px
                - mstr->nodes_array[current->node1_index]->y_px) / (float)100;
            node.x = mstr->nodes_array[current->node1_index]->x_px + (i * x_step);
            node.y = mstr->nodes_array[current->node1_index]->y_px + (i * y_step);
            SDL_SetRenderDrawColor(mstr->render, 0x00, 0xFF, 0x00, 0xFF);
            SDL_RenderFillRect(mstr->render, &node);
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