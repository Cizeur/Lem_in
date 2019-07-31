/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:50:19 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 18:29:47 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		control(t_master *mstr)
{
	while (SDL_PollEvent(&mstr->event_quit) != 0)
	{
		if (mstr->event_quit.type == SDL_QUIT)
			return (close_program(mstr));
	}
	return (TRUE);
}

int		vs_run(t_master *mstr)
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
