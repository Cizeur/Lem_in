/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:45:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 20:19:18 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	init_texture(t_texture *texture)
{
	texture->height = 0;
	texture->width = 0;
	texture->path = NULL;
	texture->texture = NULL;
}

void	clear_texture(t_texture *texture)
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

int		free_texture(t_texture *texture)
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

int		load_texture_from_file(t_master *mstr, t_texture *texture, char *path)
{
	SDL_Texture		*new_texture;
	SDL_Surface		*loaded_surface;

	clear_texture(texture);
	loaded_surface = IMG_Load(path);
	if (!loaded_surface)
		return (FALSE);
	SDL_SetColorKey(loaded_surface, SDL_TRUE,
	SDL_MapRGB(loaded_surface->format, 0xFF, 0xFF, 0xFF));
	new_texture = SDL_CreateTextureFromSurface(mstr->render, loaded_surface);
	if (!new_texture)
		return (FALSE);
	texture->path = ft_strdup(path);
	texture->texture = new_texture;
	SDL_FreeSurface(loaded_surface);
	return (TRUE);
}

void	render_texture(t_master *mstr, t_texture *texture, int x, int y)
{
	SDL_Rect	render_quad;

	render_quad.x = x;
	render_quad.y = y;
	render_quad.w = texture->width;
	render_quad.h = texture->height;
	if (SDL_RenderCopy(mstr->render, texture->texture, NULL, &render_quad)
	== FALSE)
		ft_exit(mstr, RENDER_VISU);
}
