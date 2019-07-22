/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_load_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:14:54 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/22 15:47:39 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

SDL_Texture     *load_texture_visual(t_master *mstr, char *path)
{
    SDL_Texture     *newTexture;
    SDL_Surface     *loadedSurface;

    loadedSurface = IMG_Load(path);
    if (!loadedSurface)
    {
        ft_exit(LOAD_BMP);
        SDL_FreeSurface(loadedSurface);
        return (NULL);
    }
    newTexture = SDL_CreateTextureFromSurface(mstr->gRenderer, loadedSurface);
    if (!newTexture)
    {
        ft_exit(LOAD_BMP);
        return (NULL);
    }
    SDL_FreeSurface(loadedSurface);
    return (newTexture);
}
