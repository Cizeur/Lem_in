/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:33:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/02 15:59:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

void			solver(t_master *mstr)
{
	int magic[3];
	int flow;

	magic[0] = mstr->ants_nb;
	magic[1] = mstr->adjacency_mtx[mstr->start->node_number][A_LINKS_NB];
	magic[2] = mstr->adjacency_mtx[mstr->end->node_number][A_LINKS_NB];
	mstr->magic_number= ft_min(ft_min(magic[0], magic[1]), magic[2]);
	//
	ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
	//
	flow = 0;
	while (flow < mstr->magic_number && !mstr->end_of_search)
	{
		if(!(ft_solver_paths_splitter(mstr, mstr->start->node_number, mstr->end->node_number)))
			break;
		ft_matrix_popping(mstr->nodes_nb, mstr->adjacency_mtx, mstr->node_path);
		if(!(ft_solver_paths_finder(mstr, flow)))
		{
			break;
		}
		flow++;
		ft_solver_paths_get_starts(mstr, mstr->nodes_nb, mstr->node_path);
		ft_solver_paths_get_len(mstr, flow, mstr->node_path);
		ft_solver_paths_sort(mstr, flow, mstr->node_path);
		ft_solver_turn_counter(mstr, flow);
		ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
		if (!mstr->end_of_search)
			ft_solver_solution_store(mstr, mstr->nodes_nb, flow);
		else
		{
			flow--;
		}
	}
	if(!flow)
		ft_exit(NOT_CONNECTED);
	mstr->nb_solutions = flow;
}
