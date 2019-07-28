/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:55:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 14:52:34 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    vs_close(t_master *mstr)
{
    free_texture(mstr->background);
    free_texture(mstr->start);
    free_texture(mstr->finish);
    SDL_DestroyRenderer(mstr->render);
    mstr->render = NULL;
    SDL_DestroyWindow(mstr->window);
    mstr->window = NULL;
    IMG_Quit();
    SDL_Quit();
    return (FALSE);
}