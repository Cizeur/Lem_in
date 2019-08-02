/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_path_splitter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:36:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/02 13:00:58 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void		ft_path_cleaning(t_master *mstr)
{
	int i;
	int *node_path;
	int **mtx;

	mtx = mstr->adjacency_mtx;
	node_path = mstr->node_path;
	i = mstr->nodes_nb;
	while (--i)
	{
		if (node_path[i] == DISCONNECTED)
			continue;
		if (mtx[mtx[node_path[i]][A_PARENT_FLOW]][A_VISITED_FLOW] == i - 1)
			node_path[i - 1] = mtx[node_path[i]][A_PARENT_FLOW];
		else
			node_path[i - 1] = mtx[node_path[i]][A_PARENT_BACKFLOW];
	}
}

static void		ft_edge_cutting(t_master *mstr, int max_nodes)
{
	int i;
	int *node_path;
	int **mtx;
	int cur_node;
	int next_node;

	mtx = mstr->adjacency_mtx;
	node_path = mstr->node_path;
	i = -1;
	while (node_path[++i + 1] != DISCONNECTED)
	{
		cur_node = node_path[i];
		next_node = node_path[i + 1];
		if(!(mtx[cur_node][A_LOADED] && mtx[next_node][A_LOADED]))
			continue;
		if (mtx[next_node][A_OPTIONS + max_nodes + cur_node] == ACTIVATED)
		{
			mtx[next_node][A_OPTIONS + max_nodes + cur_node] = DEACTIVATED;
			continue;
		}
		mtx[cur_node][A_OPTIONS + max_nodes + next_node] = USED;
	}
}

static int		 ft_check_node(t_master *mstr, int cur_node, int next_node, int queue_pos)
{
	int **mtx;
	int flow;
	int visited_lvl;
	int parent;

	mtx =  mstr->adjacency_mtx;
	parent = mtx[cur_node][A_VISITED_BACKFLOW] != DISCONNECTED ?
		A_PARENT_BACKFLOW : A_PARENT_FLOW;
	flow = cur_node == mstr->start->node_number
		|| !(mtx[mtx[cur_node][parent]][A_LOADED]
		&& mtx[cur_node][A_LOADED])
		? F_FLOW : F_BACKFLOW;
	if (mtx[cur_node][A_LOADED] && flow == F_FLOW && !mtx[next_node][A_LOADED])
		return(NOPE);
	if (mtx[next_node][A_VISITED_BACKFLOW] != DISCONNECTED)
		return(NOPE);
	visited_lvl = flow == F_FLOW ? A_VISITED_FLOW : A_VISITED_BACKFLOW;
	if (mtx[next_node][visited_lvl] == DISCONNECTED)
	{
		mtx[next_node][flow == F_FLOW ? A_PARENT_FLOW : A_PARENT_BACKFLOW] = cur_node;
		mstr->node_queue[queue_pos] = next_node;
		mtx[next_node][visited_lvl] = ft_max(mtx[cur_node][A_VISITED_FLOW], mtx[cur_node][A_VISITED_BACKFLOW]) + 1;
		if (mtx[next_node][A_VISITED_FLOW] == DISCONNECTED)
		{
			mtx[next_node][A_VISITED_FLOW] =
			mtx[next_node][visited_lvl];
			mtx[next_node][A_PARENT_FLOW] =
			cur_node;
		}
		return(SUCCESS);
	}
	return(NOPE);
}

static void		ft_init_stacks(t_master *mstr, int start_node)
{
	int i;

	i = -1;
	while (++i < mstr->nodes_nb)
	{
		mstr->adjacency_mtx[i][A_VISITED_FLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_VISITED_BACKFLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_PARENT_BACKFLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_PARENT_FLOW] = DISCONNECTED;
	}
	ft_intset(mstr->node_path, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_queue, 2* mstr->nodes_nb, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->adjacency_mtx[start_node][A_VISITED_FLOW] = 0;
	mstr->adjacency_mtx[start_node][A_PARENT_FLOW] = start_node;
}

int ft_solver_paths_splitter(t_master *mstr, int cur_node, int end_node)
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
		queue_start++;
		queue_len--;
		i = -1;
		while (++i < mtx[cur_node][A_LINKS_NB])
		{
			next_node = mtx[cur_node][A_OPTIONS + i];
			if ( next_node == DISCONNECTED
				||next_node == mstr->start->node_number
				||next_node == mtx[cur_node][A_PARENT_FLOW]
				||mtx[cur_node][mstr->nodes_nb + A_OPTIONS + next_node] == ACTIVATED)
				continue;
			if (next_node == end_node)
			{
				//printf("|| %d - %d ||", cur_node, next_node);
				mtx[end_node][A_PARENT_FLOW] = cur_node;
				mstr->node_path[mtx[cur_node][A_VISITED_FLOW] + 1] = end_node;
				ft_path_cleaning(mstr);
				ft_edge_cutting(mstr, mstr->nodes_nb);
				return (SUCCESS);
			}
			if(ft_check_node(mstr, cur_node, next_node, queue_len + queue_start))
				queue_len++;
		}
	}
	return (DEAD_END);
}
