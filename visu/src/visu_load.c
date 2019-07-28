/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:38:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 12:04:54 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     load_image(t_master *mstr, t_texture *texture, char *path, int width, int height)
{
	SDL_Texture     *newTexture;
	SDL_Surface     *loadedSurface;

	clear_texture(texture);
	loadedSurface = IMG_Load(path);
	if (!loadedSurface)
		return (ft_exit(LOAD_BMP));
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
	newTexture = SDL_CreateTextureFromSurface(mstr->render, loadedSurface);
	if (!newTexture)
		return (ft_exit(LOAD_BMP));
	texture->width = width;
	texture->height = height;
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
	load_image(mstr, mstr->background, "resources_visual/order_background.jpg", S_WIDTH, S_HEIGHT);
	if (!(mstr->start = (t_texture*)ft_memalloc(sizeof(t_master))))
		return (ft_exit(ERROR_MALLOC));
	init_texture(mstr->start);
	load_image(mstr, mstr->start, "resources_visual/Start.jpg", 70, 70);
	if (!(mstr->finish = (t_texture*)ft_memalloc(sizeof(t_master))))
		return (ft_exit(ERROR_MALLOC));
	init_texture(mstr->finish);
	load_image(mstr, mstr->finish, "resources_visual/Finish.jpg", 70, 70);
	return (TRUE);
}