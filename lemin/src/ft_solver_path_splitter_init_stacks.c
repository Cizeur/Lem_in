/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_path_splitter_init_stacks.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:26:29 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/11 16:32:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

void			ft_solver_path_splitter_init_stacks(t_master *mstr,
						int start_node, int *queue)
{
	int i;

	i = -1;
	while (++i < mstr->nodes)
	{
		mstr->adjacency_mtx[i][A_VISIT_FLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_VISIT_BACKFLOW] = DISCONNECTED;
	}
	ft_intset(mstr->node_path, mstr->nodes, DISCONNECTED);
	ft_intset(mstr->node_queue, 2 * mstr->nodes + 1, DISCONNECTED);
	ft_intset(mstr->node_parents, 2 * mstr->nodes + 1, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_parents[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->adjacency_mtx[start_node][A_VISIT_FLOW] = 0;
	queue[1] = 1;
	queue[0] = 0;
}
