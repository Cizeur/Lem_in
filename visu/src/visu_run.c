/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:50:19 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 19:16:49 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int   control(t_master *mstr)
{
    while (SDL_PollEvent(&mstr->event_Quit) != 0)
    {
        if (mstr->event_Quit.type == SDL_QUIT)
            return (close_program(mstr));
    }
    return (TRUE);
}

int    render_total_background(t_master *mstr)
{
    if (SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF) == FALSE
    || SDL_RenderClear(mstr->render) == FALSE
    || render_texture(mstr, mstr->background, 0, 0) == FALSE
    || render_texture(mstr, mstr->start,
    mstr->nodes_array[mstr->start_index]->x_px - 10,
    mstr->nodes_array[mstr->start_index]->y_px - 45) == FALSE
    || render_texture(mstr, mstr->finish,
    mstr->nodes_array[mstr->end_index]->x_px - 10,
    mstr->nodes_array[mstr->end_index]->y_px - 45) == FALSE
    || render_pipes(mstr) == FALSE
    || render_nodes(mstr) == FALSE)
        return (FALSE);
    return (TRUE);
}

int     vs_run(t_master *mstr)
{
    mstr->current_move = 0;
    if (render_total_background(mstr) == FALSE)
        return (FALSE);
    while (mstr->moves_array[mstr->current_move] != NULL)
    {
        if (render_moves(mstr) == FALSE)
            return (FALSE);
        SDL_Delay(100);
        mstr->current_move++;
    }
    return (TRUE);
}
