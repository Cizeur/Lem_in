/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_run.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:55:56 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 17:01:20 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    run_visual(t_master *mstr)
{
    (void)mstr;

    // int         i;
    // int         flag_quit;

    // flag_quit = FALSE;
    // while (flag_quit == FALSE)
    // {
    //     while (SDL_PollEvent(&mstr->event_Quit) != 0)
    //     {
    //         if (mstr->event_Quit.type == SDL_QUIT)
    //             flag_quit = TRUE;
    //         while (i < SCREEN_WIDTH)
    //         {
    //             //Clear screen
    //             SDL_SetRenderDrawColor(mstr->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //             SDL_RenderClear(mstr->gRenderer);
    //             //Render background texture to screen
    //             render_texture(mstr, mstr->background_texture, 0, 0);
    //             //Render foo texture to screen
    //             render_texture(mstr, mstr->foo_texture, i, 190);
    //             //Update screen
    //             SDL_RenderPresent(mstr->gRenderer);
    //             //Delay
    //             SDL_Delay(10);
    //             i = i + 10;
    //         }
    //     }
    // }
}

    // SDL_Rect    fillRect = {
    //     SCREEN_WIDTH / 4,
    //     SCREEN_HEIGHT / 4,
    //     SCREEN_WIDTH / 2,
    //     SCREEN_HEIGHT / 2
    // };

    // SDL_Rect    outlineRect = {
    //     SCREEN_WIDTH / 6,
    //     SCREEN_HEIGHT / 6,
    //     SCREEN_WIDTH * 2 / 3,
    //     SCREEN_HEIGHT * 2 / 3
    // };

    // if (mstr->event_Quit.type == SDL_QUIT)
    //     flag_quit = TRUE;
    // //Clear screen
    // SDL_SetRenderDrawColor(mstr->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    // SDL_RenderClear(mstr->gRenderer);

    // //Render red filled quad
    // SDL_SetRenderDrawColor(mstr->gRenderer, 0xFF, 0x00, 0x00, 0xFF );
    // SDL_RenderFillRect(mstr->gRenderer, &fillRect );

    // //Render green outlined quad
    // SDL_SetRenderDrawColor(mstr->gRenderer, 0x00, 0xFF, 0x00, 0xFF);
    // SDL_RenderDrawRect(mstr->gRenderer, &outlineRect);

    // //Draw blue horizontal line
    // SDL_SetRenderDrawColor(mstr->gRenderer, 0x00, 0x00, 0xFF, 0xFF);
    // SDL_RenderDrawLine(mstr->gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

    // //Draw vertical line of yellow dots
    // SDL_SetRenderDrawColor(mstr->gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
    // i = 0;
    // while (i < SCREEN_HEIGHT)
    // {
    //     SDL_RenderDrawPoint(mstr->gRenderer, SCREEN_WIDTH / 2, i);
    //     i = i + 4;
    // }

    // //Update screen
    // SDL_RenderPresent(mstr->gRenderer);