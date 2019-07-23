/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:24 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 20:11:17 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		vs_init_rect_array(t_master *mstr)
{
	int		i;
	// int		x;
	// int		y;

	i = 0;
	if (!(mstr->rect_array = (SDL_Rect**)ft_memalloc(sizeof(SDL_Rect*) * mstr->nb_nodes)))
		return (ft_exit(INIT_SDL));
	while (i < mstr->nb_nodes)
	{
		if (!(mstr->rect_array[i] = (SDL_Rect*)ft_memalloc(sizeof(SDL_Rect))))
			return (ft_exit(INIT_SDL));
		// x = (S_WIDTH / 10) * mstr->nodes_array[i]->x;
		// y = (S_HEIGHT / 10) * mstr->nodes_array[i]->y;
		// mstr->rect_array[i]->x = (S_WIDTH / 10) + x;
		// mstr->rect_array[i]->y = (S_WIDTH / 10) + y;
		// mstr->rect_array[i]->w = S_WIDTH / 50;
		// mstr->rect_array[i]->h = S_HEIGHT / 50;
		i++;
	}
	return (TRUE);
}


int		vs_init(t_master *mstr)
{
	if (SDL_Init(SDL_INIT_VIDEO) == FALSE)
		return (ft_exit(INIT_SDL));
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		return (ft_exit(INIT_SDL));
	mstr->window = SDL_CreateWindow("Lem-Im visual", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN);
	if (!mstr->window)
		return (ft_exit(INIT_SDL));
	mstr->render = SDL_CreateRenderer(mstr->window, -1,
		SDL_RENDERER_ACCELERATED);
	if (mstr->render == NULL)
		return (ft_exit(INIT_SDL));
	SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF);
	mstr->img_init_png = IMG_INIT_PNG;
	if (!mstr->img_init_png || !IMG_Init(mstr->img_init_png))
		return (ft_exit(INIT_SDL));
	vs_init_rect_array(mstr);
	return (TRUE);
}
