/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:15:41 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 15:28:16 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    render_moves(t_master *mstr)
{
    int         i;
    int         x_step;
    int         y_step;
    SDL_Rect    node;
    t_moves     *current;

    i = 0;
    node.w = 20;
    node.h = 20;
    while (i < 10)
    {
        current = mstr->moves_array[mstr->current_move];
        while (current != NULL)
        {
            render_total_background(mstr);

            x_step = (mstr->nodes_array[current->node2_index]->x_px - mstr->nodes_array[current->node1_index]->x_px) / 10;
            y_step = (mstr->nodes_array[current->node2_index]->y_px - mstr->nodes_array[current->node1_index]->y_px) / 10;

            node.x = mstr->nodes_array[current->node1_index]->x_px + (i * x_step);
            node.y = mstr->nodes_array[current->node1_index]->y_px + (i * y_step);
            
            SDL_SetRenderDrawColor(mstr->render, 0x00, 0xFF, 0x00, 0xFF);
            SDL_RenderFillRect(mstr->render, &node);

            if (control(mstr) == FALSE)
                return (FALSE);
            
            printf("Move = %d[%d] || Ant = %d || Node1 = %d || Node2 = %d\n",
                mstr->current_move, current->current_index,
                current->ant_index, current->node1_index, current->node2_index);
            printf("X = %d[%d] -> %d[%d] || x_step = %d\n",
                mstr->nodes_array[current->node1_index]->x,
                mstr->nodes_array[current->node1_index]->x_px,
                mstr->nodes_array[current->node2_index]->x,
                mstr->nodes_array[current->node2_index]->x_px,
                x_step);
            printf("Y = %d[%d] -> %d[%d] || y_step = %d\n\n",
                mstr->nodes_array[current->node1_index]->y,
                mstr->nodes_array[current->node1_index]->y_px,
                mstr->nodes_array[current->node2_index]->y,
                mstr->nodes_array[current->node2_index]->y_px,
                y_step);
            current = current->next;
        }
        SDL_RenderPresent(mstr->render);
        SDL_Delay(500);
        i++;
    }
    return(TRUE);
}