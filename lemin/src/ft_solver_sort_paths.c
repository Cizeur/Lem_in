/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_sort_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:34:34 by cesar             #+#    #+#             */
/*   Updated: 2019/07/29 17:21:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

void			ft_path_sorter(int **mtx, int *path_starts, int flow)
{
	int i;

	i = -1;
	while (++i < flow - 1)
	{
		if (mtx[path_starts[i]][A_CURRENT_PATH_LEN] > mtx[path_starts[i + 1]][A_CURRENT_PATH_LEN])
		{
			ft_swap(&path_starts[i], &path_starts[i + 1]);
			i = -1;
		}
	}
}

void 			ft_solver_sort_paths(t_master *mstr, int max_nodes, int flow)
{
	int	**mtx;
	int *sorted;
	int i;
	int path_start;

	ft_intset(mstr->node_path, max_nodes + 1, -1);
	sorted = mstr->node_path;
	mtx = mstr->adjacency_mtx;
	i = -1;
	while (++i < mtx[mstr->start->node_number][A_LINKS_NB])
	{
		path_start = mtx[mstr->start->node_number][A_OPTIONS + max_nodes * 2 + i];
		if(path_start == DISCONNECTED)
			continue;
		else
			*sorted++ = path_start;
	}
	ft_path_sorter(mtx, mstr->node_path, flow);
}
