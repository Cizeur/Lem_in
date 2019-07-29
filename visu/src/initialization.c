/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:26:31 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 11:21:04 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_alloc_ants(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->ants_array = (t_ants **)
		ft_memalloc(sizeof(t_ants *) * mstr->nb_ants)))
		return (ft_exit(ERROR_MALLOC));
	while (i < mstr->nb_ants)
	{
		if (!(mstr->ants_array[i] = (t_ants *)
			ft_memalloc(sizeof(t_ants) * mstr->nb_ants)))
			return (ft_exit(ERROR_MALLOC));
		mstr->ants_array[i]->ant_index = i;
		mstr->ants_array[i]->current_move = 0;
		mstr->ants_array[i]->current_node = FALSE;
		i++;
	}
	return (TRUE);
}

int		ft_alloc_nodes(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->nodes_array = (t_nodes **)
		ft_memalloc(sizeof(t_nodes *) * mstr->nb_nodes)))
		return (ft_exit(ERROR_MALLOC));
	while (i < mstr->nb_nodes)
	{
		if (!(mstr->nodes_array[i] = (t_nodes *)
			ft_memalloc(sizeof(t_nodes))))
			return (ft_exit(ERROR_MALLOC));
		if (!(mstr->nodes_array[i]->pipes = (int *)
			ft_memalloc(sizeof(int) * mstr->nb_nodes)))
			return (ft_exit(ERROR_MALLOC));
		mstr->nodes_array[i]->nb_pipes = 0;
		mstr->nodes_array[i]->x_px = FALSE;
		mstr->nodes_array[i]->y_px = FALSE;
		mstr->nodes_array[i]->flag = NODE_NOTHING;
		i++;
	}
	return (TRUE);
}

int		ft_alloc_pipes(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->pipes_array = (t_pipes **)
		ft_memalloc(sizeof(t_pipes *) * mstr->nb_pipes)))
		return (ft_exit(ERROR_MALLOC));
	while (i < mstr->nb_pipes)
	{
		if (!(mstr->pipes_array[i] = (t_pipes *)
			ft_memalloc(sizeof(t_pipes))))
			return (ft_exit(ERROR_MALLOC));
		mstr->pipes_array[i]->active = PIPE_ACTIVE;
		i++;
	}
	return (TRUE);
}

int		ft_alloc_moves(t_master *mstr)
{
	int		i;

	i = 0;
	if (!(mstr->moves_array = (t_moves **)
		ft_memalloc(sizeof(t_moves *) * mstr->nb_movements + 1)))
		return (ft_exit(ERROR_MALLOC));
	mstr->moves_array[mstr->nb_movements] = NULL;
	return (TRUE);
}

int		inizialization(t_master *mstr)
{
	mstr->start_index = FALSE;
	mstr->end_index = FALSE;
	mstr->current_node = 0;
	mstr->current_pipe = 0;
	mstr->current_move = 0;
	mstr->max_x = -2147483648;
	mstr->min_x = 2147483647;
	mstr->max_y = -2147483648;
	mstr->min_y = 2147483647;
	if (ft_alloc_ants(mstr) == TRUE
	&& ft_alloc_nodes(mstr) == TRUE
	&& ft_alloc_pipes(mstr) == TRUE
	&& ft_alloc_moves(mstr) == TRUE)
		return (TRUE);
	return (FALSE);
}
