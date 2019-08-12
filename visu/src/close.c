/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:55:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/12 08:38:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/libft.h"

void	close_program(t_master *mstr, int program_state)
{
	if (mstr)
	{
		if (mstr->start_name)
			free(mstr->start_name);
		if (mstr->end_name)
			free(mstr->end_name);
		free_ants(mstr);
		free_nodes(mstr);
		free_pipes(mstr);
		free_moves(mstr);
		free_textures(mstr);
		if (mstr->render)
			SDL_DestroyRenderer(mstr->render);
		if (mstr->window)
			SDL_DestroyWindow(mstr->window);
		ft_bzero(mstr, sizeof(t_master));
		free(mstr);
		mstr = NULL;
	}
	IMG_Quit();
	SDL_Quit();
	exit(program_state == VISU_FAILED ? 1 : 0);
}
