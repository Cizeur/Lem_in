/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:33:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/03 15:42:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static int		ft_get_max_flow_limit(t_master *mstr)
{
	int limit[3];
	limit[0] = mstr->ants_nb;
	limit[1] = mstr->adjacency_mtx[mstr->start->node_number][A_LINKS_NB];
	limit[2] = mstr->adjacency_mtx[mstr->end->node_number][A_LINKS_NB];
	return (ft_min(ft_min(limit[0], limit[1]), limit[2]));
}

void			solver(t_master *mstr)
{
	int flow;

	mstr->max_flow = ft_get_max_flow_limit(mstr);
	mstr->final_flow = 0;
	flow = 0;
	while (flow < mstr->max_flow && !mstr->end_of_search)
	{
		if (!(ft_solver_paths_splitter(mstr, mstr->start->node_number,
					mstr->end->node_number)))
			break ;
		ft_matrix_popping(mstr->nodes_nb, mstr->adjacency_mtx, mstr->node_path);
		ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
		if (!(ft_solver_paths_finder(mstr, ++flow)))
			break;
		ft_solver_paths_get_starts(mstr, mstr->nodes_nb, mstr->node_path);
		ft_solver_paths_get_len(mstr, flow, mstr->node_path);
		ft_solver_paths_sort(mstr, flow, mstr->node_path);
		ft_solver_turn_counter(mstr, flow);
		if (!mstr->end_of_search)
			ft_solver_solution_store(mstr, mstr->nodes_nb, flow);
	}
	if(!mstr->final_flow)
		ft_exit(NOT_CONNECTED);
}
