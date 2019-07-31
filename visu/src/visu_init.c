/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:24 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 14:10:18 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		vs_init(t_master *mstr)
{
	if (SDL_Init(SDL_INIT_VIDEO) == FALSE)
		return (ft_exit(mstr, INIT_VISU));
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		return (ft_exit(mstr, INIT_VISU));
	mstr->window = SDL_CreateWindow("Lem-Im visual", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN);
	if (!mstr->window)
		return (ft_exit(mstr, INIT_VISU));
	mstr->render = SDL_CreateRenderer(mstr->window, -1,
	SDL_RENDERER_ACCELERATED);
	if (mstr->render == NULL)
		return (ft_exit(mstr, INIT_VISU));
	SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
	mstr->img_init_png = IMG_INIT_PNG;
	if (!mstr->img_init_png || !IMG_Init(mstr->img_init_png))
		return (ft_exit(mstr, INIT_VISU));
	mstr->flag_exit = FALSE;
	return (TRUE);
}
