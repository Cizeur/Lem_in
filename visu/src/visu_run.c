/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:50:19 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 16:37:09 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int   control(t_master *mstr)
{
    while (SDL_PollEvent(&mstr->event_Quit) != 0)
    {
        if (mstr->event_Quit.type == SDL_QUIT)
            return (vs_close(mstr));
    }
    return (TRUE);
}

int    render_total_background(t_master *mstr)
{
    SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(mstr->render);
    render_texture(mstr, mstr->background, 0, 0);
    render_texture(mstr, mstr->start,
    mstr->nodes_array[mstr->start_index]->x_px - 10,
    mstr->nodes_array[mstr->start_index]->y_px - 45);
    render_texture(mstr, mstr->finish,
    mstr->nodes_array[mstr->end_index]->x_px - 10,
    mstr->nodes_array[mstr->end_index]->y_px - 45);
    render_pipes(mstr);
    render_nodes(mstr);
    return (TRUE);
}

int     vs_run(t_master *mstr)
{
    mstr->current_move = 0;
    render_total_background(mstr);
    while (mstr->moves_array[mstr->current_move] != NULL)
    {
        render_moves(mstr);
        SDL_Delay(100);
        mstr->current_move++;
    }
    return (TRUE);
}
