/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_close.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:11:00 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/22 15:47:55 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    close_visual(t_master *mstr)
{
    SDL_DestroyTexture(mstr->gTexture);
    mstr->gTexture = NULL;
    SDL_DestroyRenderer(mstr->gRenderer);
    mstr->gRenderer = NULL;
    SDL_DestroyWindow(mstr->gWindow);
    mstr->gWindow = NULL;
    IMG_Quit();
    SDL_Quit();
}