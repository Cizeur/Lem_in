/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:09:37 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/22 15:46:02 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     init_visual(t_master *mstr)
{
    if (SDL_Init(SDL_INIT_VIDEO) == FALSE)
        return(ft_exit(INIT_SDL));
    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        return (ft_exit(INIT_SDL));
    //Create window
    mstr->gWindow = SDL_CreateWindow(
        "SDL Tutorial",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!mstr->gWindow)
        return(ft_exit(CREATE_SDL));
    //Create renderer for window
    mstr->gRenderer = SDL_CreateRenderer(mstr->gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (mstr->gRenderer == NULL)
        return(ft_exit(CREATE_SDL));
    //Initialize renderer color
    SDL_SetRenderDrawColor(mstr->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //Initialize PNG loading
    mstr->img_init_png = IMG_INIT_PNG;
    if (!mstr->img_init_png || !IMG_Init(mstr->img_init_png))
        return (ft_exit(CREATE_SDL));
    return (TRUE);
}