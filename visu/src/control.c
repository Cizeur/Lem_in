/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:30:49 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/07 20:34:20 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "key_press.h"


void    control_move_forward(t_master *mstr)
{
    if (mstr->event.type == SDL_KEYDOWN
    && mstr->event.key.keysym.sym == SDLK_RIGHT)
    {
        if (mstr->current_move < mstr->nb_movements)
        {
            if (mstr->frame >= 60)
            {
                mstr->frame = 0;
                mstr->current_move += 1;
            }
            else
                mstr->frame += 5;
        }
        mstr->flag_move = FALSE;
    }
}

void    control_move_backwards(t_master *mstr)
{
    if (mstr->event.type == SDL_KEYDOWN
    && mstr->event.key.keysym.sym == SDLK_LEFT)
    {
        if (mstr->frame >= 5)
            mstr->frame -= 5;
        else if (mstr->current_move > 0)
        {
            mstr->frame = 60;
            mstr->current_move -= 1;
        }
        mstr->flag_move = FALSE;
    }
}

void    control_pause_and_delay(t_master *mstr)
{
    if (mstr->event.type == SDL_KEYDOWN
    && mstr->event.key.keysym.sym == SDLK_UP
    && mstr->delay > 2)
        mstr->delay -= 2;
    if (mstr->event.type == SDL_KEYDOWN
    && mstr->event.key.keysym.sym == SDLK_DOWN && mstr->delay > 0)
        mstr->delay += 2;
    if (mstr->event.type == SDL_KEYDOWN
    && mstr->event.key.keysym.sym == SDLK_SPACE)
    {
        if (mstr->flag_move == FALSE)
            mstr->flag_move = TRUE;
        else if (mstr->flag_move == TRUE)
            mstr->flag_move = FALSE;
    }
    if (mstr->event.type == SDL_KEYDOWN
    && mstr->event.key.keysym.sym == SDLK_RSHIFT)
    {
        mstr->current_move = 0;
        mstr->frame = 0;
    }
}

void    control_exit(t_master *mstr)
{
    if (mstr->event.type == SDL_QUIT
    || (mstr->event.type == SDL_KEYDOWN
    && mstr->event.key.keysym.sym == SDLK_ESCAPE))
        close_program(mstr, VISU_FINISHED);
}


int		control(t_master *mstr)
{
	while (SDL_PollEvent(&mstr->event) != 0)
	{
		control_exit(mstr);
        control_move_forward(mstr);
        control_move_backwards(mstr);
        control_pause_and_delay(mstr);
	}
	return (TRUE);
}
