/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_bfs_find_two_way_edge.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:36:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/31 11:40:49 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void			ft_path_cleaning(t_master *mstr)
{
	int i;

	i = mstr->nodes_nb;
	while (--i)
	{
		if (mstr->node_path[i] == DISCONNECTED)
			continue;
		mstr->node_path[i - 1] = mstr->node_parent[mstr->node_path[i]];
	}
}

static int ft_check_node(t_master *mstr, int cur_node, int next_node, int queue_pos)
{
	int **mtx;
	int flow;
	int visited_lvl;

	mtx =  mstr->adjacency_mtx;
	flow = mtx[cur_node][A_LOADED] ? F_BACKFLOW : F_FLOW;
	if (next_node < 0
		|| (mtx[cur_node][A_LOADED] && flow == F_FLOW && !mtx[next_node][A_LOADED])
		|| (mtx[next_node][A_VISITED_BACKFLOW] && !mtx[cur_node][A_LOADED]))
		return (NOPE);
	if (next_node == mstr->end->node_number)
	{
		mstr->node_parent[next_node] = cur_node;
		mstr->node_path[mstr->node_lvl_stack[cur_node] + 1] = mstr->end->node_number;
		ft_path_cleaning(mstr);
		return (SUCCESS);
	}
	if (mtx[cur_node][A_LOADED] && flow == F_FLOW && !mtx[next_node][A_LOADED])
		return (NOPE);
	if (mtx[next_node][A_VISITED_BACKFLOW] && !mtx[cur_node][A_LOADED])
		return (NOPE);
	visited_lvl = flow == F_FLOW ? A_VISITED_FLOW : A_VISITED_BACKFLOW;
	if (mtx[next_node][visited_lvl] == DISCONNECTED)
	{
		mstr->node_parent[next_node] = cur_node;
		mstr->node_queue[queue_pos] = next_node;
		mtx[next_node][visited_lvl] = mtx[cur_node][A_VISITED_FLOW] + 1;
		mtx[A_VISITED_FLOW] = mtx[visited_lvl];
	}
}

int ft_solver_bfs(t_master *mstr, int cur_node, int end_node)
{
	int **mtx;
	int next_node;
	int i;
	int queue_len;
	int queue_start;

	mtx = mstr->adjacency_mtx;
	queue_len = 1;
	queue_start = 0;
	ft_init_stacks(mstr, cur_node);
	while (queue_len)
	{
		cur_node = mstr->node_queue[queue_start];
		mstr->node_path[mtx[A_VISITED_FLOW][cur_node]] = cur_node;
		queue_start++;
		queue_len--;
		i = -1;
		while (++i < mtx[cur_node][A_LINKS_NB])
		{
			next_node = mtx[cur_node][A_OPTIONS + i];
			if (ft_check_node(mstr, cur_node, next_node, queue_len++ + queue_start) == SUCCESS)
				return (SUCCESS);
		}
	}
	return (DEAD_END);
}
