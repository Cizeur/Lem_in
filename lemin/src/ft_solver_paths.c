/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:22 by cesar             #+#    #+#             */
/*   Updated: 2019/07/30 17:42:02 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

void			ft_solver_paths_get_starts(t_master *mstr, int max_nodes, int *extracted)
{
	int i;
	int **mtx;
	int path_start;

	mtx = mstr->adjacency_mtx;
	i = -1;
	ft_intset(extracted, max_nodes + 1, -1);
	while (++i < mtx[mstr->start->node_number][A_LINKS_NB])
	{
		path_start = mtx[mstr->start->node_number][A_OPTIONS + max_nodes * 2 + i];
		if(path_start == DISCONNECTED)
			continue;
		*extracted++ = path_start;
	}
}

static int		ft_get_path_len(int **mtx, int cur_node, int end_node)
{
	int path_len;

	path_len = 1;
	while (cur_node != end_node)
	{
		if (cur_node == DISCONNECTED)
			return(DEACTIVATED);
		cur_node = mtx[cur_node][A_CURRENT_SOLUTION];
		path_len++;
	}
	return (--path_len);
}

void 			ft_solver_paths_get_len(t_master *mstr, int flow, int *extracted)
{
	int	**mtx;
	int i;


	mtx = mstr->adjacency_mtx;
	i = -1;
	while (++i < flow && !mstr->end_of_search)
	{
			mtx[extracted[i]][A_CURRENT_PATH_LEN]
			= ft_get_path_len(mtx, extracted[i], mstr->end->node_number);
			if (mtx[extracted[i]][A_CURRENT_PATH_LEN] == DEACTIVATED)
				mstr->end_of_search = 1;
	}
}

void			ft_solver_paths_sort(t_master *mstr, int flow, int *extracted)
{
	int i;
	int **mtx;

	mtx = mstr->adjacency_mtx;
	i = -1;
	while (++i < flow - 1)
	{
		if (mtx[extracted[i]][A_CURRENT_PATH_LEN] > mtx[extracted[i + 1]][A_CURRENT_PATH_LEN])
		{
			ft_swap(&extracted[i], &extracted[i + 1]);
			i = -1;
		}
	}
}
