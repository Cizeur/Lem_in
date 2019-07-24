/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_max_path_len.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:22 by cesar             #+#    #+#             */
/*   Updated: 2019/07/24 12:25:35 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_get_path_len(int **mtx, int cur_node, int end_node)
{
	int path_len;

	path_len = 1;
	while (cur_node != end_node)
	{
		if (cur_node == DISCONNECTED)
			ft_exit(DEAD_END_ON_SOLUTION);
		cur_node = mtx[cur_node][A_STORED_SOLUTION];
		path_len++;
	}
	return (path_len);
}


void 			ft_solver_extract_path_len(t_master *mstr, int max_nodes)
{
	int	**mtx;
	int i;
	int path_start;

	mtx = mstr->adjacency_mtx;
	i = -1;
	printf("start\n\n");
	while (++i < mtx[mstr->start->node_number][A_LINKS_NB])
	{
		path_start = mtx[mstr->start->node_number][A_OPTIONS + max_nodes * 2 + i];
		if(path_start == DISCONNECTED)
			continue;
		mtx[path_start][A_PATH_LEN] = ft_get_path_len(mtx, path_start, mstr->end->node_number);
	}
}
