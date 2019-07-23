/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:45:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 13:01:34 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     init_texture(t_texture *texture)
{
    texture->height = 0;
    texture->width = 0;
    texture->path = NULL;
    texture->texture = NULL;
    return (TRUE);
}

int     clear_texture(t_texture *texture)
{
    texture->height = 0;
    texture->width = 0;
    if (texture->path)
        free(texture->path);
    texture->path = NULL;
    if (texture->texture)
        SDL_DestroyTexture(texture->texture);
    texture->texture = NULL;
    return (TRUE);
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
        return (ft_exit(LOAD_IMG));
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
    newTexture = SDL_CreateTextureFromSurface(mstr->gRenderer, loadedSurface);
    if (!newTexture)
        return (ft_exit(CREATE_TEXTURE));
    texture->width = loadedSurface->w;
    texture->height = loadedSurface->h;
    texture->path = ft_strdup(path);
    texture->texture = newTexture;
    SDL_FreeSurface(loadedSurface);
    return (TRUE);
}

int     render_texture(t_master *mstr, t_texture *texture, int x, int y)
{
    SDL_Rect    renderQuad = {x, y, texture->width, texture->height};
    SDL_RenderCopy(mstr->gRenderer, texture->texture, NULL, &renderQuad);
    return (TRUE);
}
