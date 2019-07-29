/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_turn_counter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:24:48 by cesar             #+#    #+#             */
/*   Updated: 2019/07/29 14:51:46 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_turn_counter_initialiser(t_master *mstr, int *node_path, int flow)
{
	int i;
	int ants;
	int current_flow;
	int current_path_len;

	ants = mstr->ants_nb;
	current_flow = 0;
	current_path_len = mstr->adjacency_mtx[node_path[0]][A_CURRENT_PATH_LEN] ;
	i = -1;
	while (++i < flow)
	{
		ants -= (mstr->adjacency_mtx[node_path[i]][A_CURRENT_PATH_LEN] - current_path_len) * current_flow;
		current_path_len = mstr->adjacency_mtx[node_path[i]][A_CURRENT_PATH_LEN] ;
		current_flow++;
	}
	if (ants > 0)
		return(ants);
	else
		return(0);
}

void			ft_solver_turn_counter(t_master *mstr, int flow)
{
	int ants;
	int turns;

	ants = mstr->ants_nb;
	ants = ft_turn_counter_initialiser(mstr, mstr->node_path, flow);
	if (ants)
		turns = mstr->adjacency_mtx[mstr->node_path[flow - 1]][A_CURRENT_PATH_LEN] - 1;
	else
	{
		mstr->end_of_search = 1;
		return;
	}
	//printf("remaining ants : %d", ants);
	while (ants >= 0)
	{
		turns++;
		ants -= flow;
	}
	mstr->turn_counter = turns;
	//printf("turns : %d\n", turns);
}
