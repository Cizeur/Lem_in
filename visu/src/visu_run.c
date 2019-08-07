/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:50:19 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/07 20:34:25 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	vs_run(t_master *mstr)
{
	mstr->current_move = 0;
	render_total_background(mstr);
	while (mstr->moves_array[mstr->current_move] != NULL
	&& mstr->flag_exit == FALSE)
	{
		render_moves(mstr);
		SDL_Delay(100);
		if (mstr->flag_move == TRUE)
			mstr->current_move++;
	}
}
