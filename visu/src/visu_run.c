/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:50:19 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 20:14:23 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		control(t_master *mstr)
{
	while (SDL_PollEvent(&mstr->event_quit) != 0)
	{
		if (mstr->event_quit.type == SDL_QUIT)
			close_program(mstr, VISU_FINISHED);
	}
	return (TRUE);
}

void	vs_run(t_master *mstr)
{
	mstr->current_move = 0;
	render_total_background(mstr);
	while (mstr->moves_array[mstr->current_move] != NULL)
	{
		render_moves(mstr);
		SDL_Delay(100);
		mstr->current_move++;
	}
}
