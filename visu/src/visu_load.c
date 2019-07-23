/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:38:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 17:15:35 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     load_background(t_master *mstr, t_texture *texture, char *path)
{
    SDL_Texture     *newTexture;
    SDL_Surface     *loadedSurface;

    clear_texture(texture);
    loadedSurface = IMG_Load(path);
    if (!loadedSurface)
        return (ft_exit(LOAD_BMP));
    newTexture = SDL_CreateTextureFromSurface(mstr->render, loadedSurface);
    if (!newTexture)
        return (ft_exit(LOAD_BMP));
    texture->width = loadedSurface->w;
    texture->height = loadedSurface->h;
    texture->path = ft_strdup(path);
    texture->texture = newTexture;
    SDL_FreeSurface(loadedSurface);
    return (TRUE);
}

int     vs_load(t_master *mstr)
{
    if (!(mstr->background = (t_texture*)ft_memalloc(sizeof(t_master))))
        return (ft_exit(ERROR_MALLOC));
    init_texture(mstr->background);
    load_background(mstr, mstr->background, "resources_visual/order_background.jpg");
    return (TRUE);
}