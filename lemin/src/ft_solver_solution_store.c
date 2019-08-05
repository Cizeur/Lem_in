/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_solution_store.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:31:11 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/05 15:50:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

void		ft_solver_solution_store(t_master *mstr, int max_nodes, int flow)
{
	int i;
	int **mtx;

	i = -1;
	mtx = mstr->adjacency_mtx;
	mstr->final_flow = flow;
	while (++i < max_nodes)
	{
		mtx[i][A_STORED_SOLUTION_START] = mtx[i][A_SOLUTION_START];
		mtx[i][A_STORED_PATH_LEN] = mtx[i][A_CURRENT_PATH_LEN];
		mtx[i][A_STORED_SOLUTION] = mtx[i][A_CURRENT_SOLUTION];
		mtx[i][A_CURRENT_PATH_LEN] = DISCONNECTED;
		mtx[i][A_CURRENT_SOLUTION] = DISCONNECTED;
	}
	ft_intset(mstr->stored_solution, max_nodes + 1, -1);
	i = -1;
	while (++i < flow)
		mstr->stored_solution[i] = mstr->node_path[i];
	printf("#flow : %d and turns %d\n", flow, mstr->turn_counter);
}
