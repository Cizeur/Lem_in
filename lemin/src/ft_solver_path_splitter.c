/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_path_splitter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:36:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/03 17:55:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void		ft_path_cleaning(t_master *mstr, int queue_end)
{
	int i;
	int j;

	i = queue_end + 1;
	j= 0;
	while(i--)
	{
		if (i == queue_end)
		{
			mstr->node_path[j++] = mstr->node_queue[i];
			queue_end = mstr->node_parents[i];
		}
	}
	queue_end = j -1;
	j = -1;
	while(++j <= queue_end / 2)
		ft_swap(&mstr->node_path[j], &mstr->node_path[queue_end - j]);
}

static int			ft_check_node(t_master *mstr, int cur_node,
								int next_node, int queue_pos, int queue_start)
{
	int **mtx;
	int flow;
	int visited_lvl;

	mtx = mstr->adjacency_mtx;
	flow = cur_node == mstr->start->node_number
		|| !(mtx[mstr->node_queue[mstr->node_parents[queue_start]]][A_LOADED]
		&& mtx[cur_node][A_LOADED])
		? F_FLOW : F_BACKFLOW;
	if (mtx[cur_node][A_LOADED] && flow == F_FLOW && !mtx[next_node][A_LOADED])
		return (NOPE);
	if (mtx[cur_node][A_LOADED]
		&& mtx[next_node][mstr->nodes_nb + A_OPTIONS + cur_node] != ACTIVATED
		&& mtx[next_node][A_LOADED])
		return (NOPE);
	if (mtx[next_node][A_VISITED_BACKFLOW] != DISCONNECTED)
		return (NOPE);
	visited_lvl = flow == F_FLOW ? A_VISITED_FLOW : A_VISITED_BACKFLOW;
	if (mtx[next_node][visited_lvl] == DISCONNECTED)
	{
		mstr->node_queue[queue_pos] = next_node;
		mstr->node_parents[queue_pos] = queue_start;
		mtx[next_node][A_VISITED_FLOW] = 1;
		if (flow == F_BACKFLOW)
		{
			mtx[next_node][A_VISITED_BACKFLOW] = 1;
		}
		return (SUCCESS);
	}
	return (NOPE);
}

static void		ft_init_stacks(t_master *mstr, int start_node)
{
	int i;

	i = -1;
	while (++i < mstr->nodes_nb)
	{
		mstr->adjacency_mtx[i][A_VISITED_FLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_VISITED_BACKFLOW] = DISCONNECTED;
	}
	ft_intset(mstr->node_path, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_queue, 2 * mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_parents, 2 * mstr->nodes_nb, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_parents[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->adjacency_mtx[start_node][A_VISITED_FLOW] = 0;
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
				|| next_node == mstr->start->node_number
				|| mtx[cur_node][mstr->nodes_nb + A_OPTIONS + next_node] == ACTIVATED
				|| next_node == mstr->node_queue[mstr->node_parents[queue_start - 1]])
				continue;
			if (next_node == end_node)
			{
				mstr->node_queue[queue_start] = end_node;
				mstr->node_parents[queue_start] = queue_start - 1;
				ft_path_cleaning(mstr, queue_start);
				return (SUCCESS);
			}
			if(ft_check_node(mstr, cur_node, next_node, queue_len + queue_start, queue_start - 1))
				queue_len++;
		}
	}
	return (DEAD_END);
}
