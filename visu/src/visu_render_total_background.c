/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_render_total_background.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:43:06 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 18:29:25 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		render_total_background(t_master *mstr)
{
	if (SDL_SetRenderDrawColor(mstr->render, 0xFF, 0xFF, 0xFF, 0xFF) == FALSE
	|| SDL_RenderClear(mstr->render) == FALSE
	|| render_texture(mstr, mstr->background, 0, 0) == FALSE
	|| render_nodes(mstr) == FALSE
	|| render_pipes(mstr) == FALSE
	|| render_nodes(mstr) == FALSE
	|| render_texture(mstr, mstr->start,
	mstr->nodes_array[mstr->start_index]->x_px - 15,
	mstr->nodes_array[mstr->start_index]->y_px - 50) == FALSE
	|| render_texture(mstr, mstr->finish,
	mstr->nodes_array[mstr->end_index]->x_px - 50,
	mstr->nodes_array[mstr->end_index]->y_px - 80) == FALSE)
		return (FALSE);
	return (TRUE);
}
