/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:38:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 11:27:28 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

char g_path_textures[8][150] = {
	{"resources_visual/ballon.png"},
	{"resources_visual/bike.png"},
	{"resources_visual/car.png"},
	{"resources_visual/ship.png"},
	{"resources_visual/submarine.png"},
	{"resources_visual/train.png"},
	{"resources_visual/van.png"},
	{"resources_visual/velero.png"},
};

int     load_image(t_master *mstr, t_texture *texture, char *path, int width, int height)
{
	SDL_Texture     *newTexture;
	SDL_Surface     *loadedSurface;

	clear_texture(texture);
	loadedSurface = IMG_Load(path);
	if (!loadedSurface)
		return (ft_exit(mstr, LOAD_VISU));
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
	newTexture = SDL_CreateTextureFromSurface(mstr->render, loadedSurface);
	if (!newTexture)
		return (ft_exit(mstr, LOAD_VISU));
	texture->path = ft_strdup(path);
	texture->width = width;
	texture->height = height;
	texture->texture = newTexture;
	SDL_FreeSurface(loadedSurface);
	return (TRUE);
}

int     vs_load(t_master *mstr)
{
	int i;

	i = 0;
	if (!(mstr->textures = (t_texture**)ft_memalloc(sizeof(t_texture*) * 8)))
	 	return (ft_exit(mstr, ERROR_MALLOC));
	while (i < 8)
	{
		if (!(mstr->textures[i] = (t_texture*)ft_memalloc(sizeof(t_texture))))
			return (ft_exit(mstr, ERROR_MALLOC));
		init_texture(mstr->textures[i]);
		if (load_image(mstr, mstr->textures[i], g_path_textures[i], 100, 100) == FALSE)
			return (FALSE);
		i++;
	}
	if (!(mstr->background = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->background);
	if (load_image(mstr, mstr->background, "resources_visual/background.jpg", S_WIDTH, S_HEIGHT) == FALSE)
		return (FALSE);
	if (!(mstr->start = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->start);
	if (load_image(mstr, mstr->start, "resources_visual/home.png", 100, 100) == FALSE)
		return (FALSE);
	if (!(mstr->finish = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->finish);
	if (load_image(mstr, mstr->finish, "resources_visual/end.png", 100, 100) == FALSE)
		return (FALSE);
	if (!(mstr->node = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->node);
	if (load_image(mstr, mstr->node, "resources_visual/tend4.png", 70, 70) == FALSE)
		return (FALSE);
	return (TRUE);
}
