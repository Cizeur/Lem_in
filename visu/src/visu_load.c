/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:38:14 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 13:40:05 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

char g_path_from_visu_textures[12][150] = {
	{"resources_visual/background.jpg"},
	{"resources_visual/home.png"},
	{"resources_visual/end.png"},
	{"resources_visual/tend4.png"},
	{"resources_visual/ballon.png"},
	{"resources_visual/bike.png"},
	{"resources_visual/car.png"},
	{"resources_visual/ship.png"},
	{"resources_visual/submarine.png"},
	{"resources_visual/train.png"},
	{"resources_visual/van.png"},
	{"resources_visual/velero.png"},
};

char g_path_from_git_textures[12][150] = {
	{"visu/resources_visual/background.jpg"},
	{"visu/resources_visual/home.png"},
	{"visu/resources_visual/end.png"},
	{"visu/resources_visual/tend4.png"},
	{"visu/resources_visual/ballon.png"},
	{"visu/resources_visual/bike.png"},
	{"visu/resources_visual/car.png"},
	{"visu/resources_visual/ship.png"},
	{"visu/resources_visual/submarine.png"},
	{"visu/resources_visual/train.png"},
	{"visu/resources_visual/van.png"},
	{"visu/resources_visual/velero.png"},
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

int load_nodes_textures(t_master *mstr)
{
	if (!(mstr->background = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->background);
	if (load_image(mstr, mstr->background, g_path_from_visu_textures[0], S_WIDTH, S_HEIGHT) == FALSE)
		if (load_image(mstr, mstr->background, g_path_from_git_textures[0], S_WIDTH, S_HEIGHT) == FALSE)
			return (FALSE);
	if (!(mstr->start = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->start);
	if (load_image(mstr, mstr->start, g_path_from_visu_textures[1], 100, 100) == FALSE)
		if (load_image(mstr, mstr->start, g_path_from_git_textures[1], 100, 100) == FALSE)
			return (FALSE);
	if (!(mstr->finish = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->finish);
	if (load_image(mstr, mstr->finish, g_path_from_visu_textures[2], 100, 100) == FALSE)
		if (load_image(mstr, mstr->finish, g_path_from_git_textures[2], 100, 100) == FALSE)
			return (FALSE);
	if (!(mstr->node = (t_texture*)ft_memalloc(sizeof(t_texture))))
		return (ft_exit(mstr, ERROR_MALLOC));
	init_texture(mstr->node);
	if (load_image(mstr, mstr->node, g_path_from_visu_textures[3], 70, 70) == FALSE)
		if (load_image(mstr, mstr->node, g_path_from_git_textures[3], 70, 70) == FALSE)
			return (FALSE);
	return (TRUE);
}

int     vs_load(t_master *mstr)
{
	int i;

	i = 4;
	if (!(mstr->textures = (t_texture**)ft_memalloc(sizeof(t_texture*) * 8)))
	 	return (ft_exit(mstr, ERROR_MALLOC));
	while (i < 12)
	{
		if (!(mstr->textures[i] = (t_texture*)ft_memalloc(sizeof(t_texture))))
			return (ft_exit(mstr, ERROR_MALLOC));
		init_texture(mstr->textures[i]);
		if (load_image(mstr, mstr->textures[i], g_path_from_visu_textures[i], 100, 100) == FALSE)
			if (load_image(mstr, mstr->textures[i], g_path_from_git_textures[i], 100, 100) == FALSE)
				return (FALSE);
		i++;
	}
	load_nodes_textures(mstr);
	return (TRUE);
}
