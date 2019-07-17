/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:11:18 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/16 17:57:48 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     init_visual(t_master *mstr)
{

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
        return(ft_exit(INIT_SDL));
    mstr->gWindow = SDL_CreateWindow(
        "An SDL2 window",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );
    if (!mstr->gWindow)
        return(ft_exit(CREATE_SDL));
    mstr->gScreenSurface = SDL_GetWindowSurface(mstr->gWindow);
    return (TRUE);
}

int     load_visual(t_master *mstr)
{
    mstr->gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
    if (!mstr->gHelloWorld)
        return(ft_exit(LOAD_BMP));
    return (TRUE);
}

void    run_visual(t_master *mstr)
{
    int     flag_quit;

    flag_quit = FALSE;
    while (flag_quit == FALSE)
    {
        while (SDL_PollEvent(&mstr->event_Quit) != 0)
        {
            if (mstr->event_Quit.type == SDL_QUIT)
                flag_quit = TRUE;
            else
            {
                SDL_BlitSurface(mstr->gHelloWorld, NULL, mstr->gScreenSurface, NULL);
                SDL_UpdateWindowSurface(mstr->gWindow);
            }
            
        }
    }
}

void    close_visual(t_master *mstr)
{
    SDL_FreeSurface(mstr->gHelloWorld);
    mstr->gHelloWorld = NULL;
    SDL_DestroyWindow(mstr->gWindow);
    mstr->gWindow = NULL;
    SDL_Quit();
}

void    visual(t_master *mstr)
{
    if (init_visual(mstr) == TRUE)
    {
        if (load_visual(mstr) == TRUE)
            run_visual(mstr);
        close_visual(mstr);
    }
}