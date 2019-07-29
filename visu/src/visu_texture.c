/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:45:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 19:16:08 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void     init_texture(t_texture *texture)
{
    texture->height = 0;
    texture->width = 0;
    texture->path = NULL;
    texture->texture = NULL;
}

void     clear_texture(t_texture *texture)
{
    texture->height = 0;
    texture->width = 0;
    if (texture->path)
        free(texture->path);
    texture->path = NULL;
    if (texture->texture)
        SDL_DestroyTexture(texture->texture);
    texture->texture = NULL;
}

int     free_texture(t_texture *texture)
{
    if (texture)
    {
        texture->height = 0;
        texture->width = 0;
        if (texture->path)
            free(texture->path);
        texture->path = NULL;
        if (texture->texture)
            SDL_DestroyTexture(texture->texture);
        texture->texture = NULL;
        free(texture);
    }
    return (TRUE);
}

int     load_texture_from_file(t_master *mstr, t_texture *texture, char *path)
{
    SDL_Texture*    newTexture;
    SDL_Surface*    loadedSurface;

    clear_texture(texture);
    loadedSurface = IMG_Load(path);
    if(!loadedSurface)
        return (ft_exit(mstr, LOAD_VISU));
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
    newTexture = SDL_CreateTextureFromSurface(mstr->render, loadedSurface);
    if (!newTexture)
        return (ft_exit(mstr, LOAD_VISU));
    texture->width = loadedSurface->w;
    texture->height = loadedSurface->h;
    texture->path = ft_strdup(path);
    texture->texture = newTexture;
    SDL_FreeSurface(loadedSurface);
    return (TRUE);
}

int      render_texture(t_master *mstr, t_texture *texture, int x, int y)
{
    SDL_Rect    renderQuad = {x, y, texture->width, texture->height};
    if (SDL_RenderCopy(mstr->render, texture->texture, NULL, &renderQuad) == FALSE)
        return (ft_exit(mstr, RENDER_VISU));
    return (TRUE);
}
