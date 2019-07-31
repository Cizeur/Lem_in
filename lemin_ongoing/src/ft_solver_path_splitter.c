/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_path_splitter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:36:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/31 18:20:48 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void		ft_path_cleaning(t_master *mstr)
{
	int i;

	i = mstr->nodes_nb;
//	printf("\nnew flow \n");
	while (--i)
	{
		if (mstr->node_path[i] == DISCONNECTED)
			continue;
		mstr->node_path[i - 1] = mstr->node_parent[mstr->node_path[i]];
	}
//	while (i < mstr->nodes_nb && mstr->node_path[i] != DISCONNECTED)
//		printf("%d-", mstr->node_path[i++]);
//	printf("\n");
}

static int		 ft_check_node(t_master *mstr, int cur_node, int next_node, int queue_pos)
{
	int **mtx;
	int flow;
	int visited_lvl;


	mtx =  mstr->adjacency_mtx;
	flow = cur_node == mstr->start->node_number
		|| !(mtx[mstr->node_parent[cur_node]][A_LOADED]
		&& mtx[cur_node][A_LOADED])
		? F_FLOW : F_BACKFLOW;
	if (mtx[cur_node][A_LOADED] && flow == F_FLOW && !mtx[next_node][A_LOADED])
		return(NOPE);
	if (mtx[next_node][A_VISITED_BACKFLOW] != DISCONNECTED)
		return(NOPE);
	visited_lvl = flow == F_FLOW ? A_VISITED_FLOW : A_VISITED_BACKFLOW;
	if (mtx[next_node][visited_lvl] == DISCONNECTED)
	{
		mstr->node_parent[next_node] = cur_node;
		mstr->node_queue[queue_pos] = next_node;
		mtx[next_node][visited_lvl] = mtx[cur_node][A_VISITED_FLOW] + 1;
		mtx[next_node][A_VISITED_FLOW] = mtx[next_node][visited_lvl];
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
	}
	ft_intset(mstr->node_path, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_queue, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_parent, mstr->nodes_nb, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->adjacency_mtx[start_node][A_VISITED_FLOW] = 0;
	mstr->adjacency_mtx[start_node][A_VISITED_BACKFLOW] = 0;
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
		mstr->node_path[mtx[cur_node][A_VISITED_FLOW]] = cur_node;
		queue_start++;
		queue_len--;
		i = -1;
		while (++i < mtx[cur_node][A_LINKS_NB])
		{
			next_node = mtx[cur_node][A_OPTIONS + i];
			if (next_node == mstr->node_parent[cur_node] || next_node == DISCONNECTED
				||next_node == mstr->start->node_number)
				continue;
			if (next_node == end_node)
			{
				//printf("|| %d - %d ||", cur_node, next_node);
				mstr->node_parent[next_node] = cur_node;
				mstr->node_path[mtx[cur_node][A_VISITED_FLOW] + 1] = end_node;
				ft_path_cleaning(mstr);
				return (SUCCESS);
			}
			if(ft_check_node(mstr, cur_node, next_node, queue_len + queue_start))
			{
				queue_len++;
				continue;
				printf("	%s||%d%s %s %d%s{%d}||",
					cur_node == mstr->start->node_number
					|| !(mtx[mstr->node_parent[cur_node]][A_LOADED])
					? "F->" : "B-<",
					cur_node,
					mtx[cur_node][A_LOADED]?"!":"",
					cur_node == mstr->start->node_number
					|| !mtx[cur_node][A_LOADED] || !mtx[next_node][A_LOADED]
					? "F" : "B",
					next_node,
					mtx[next_node][A_LOADED]?"!":"",
					mtx[next_node][A_VISITED_FLOW]);
			}
			else
			{
				continue;
				printf("	%s[[%d%s %s %d%s{%d}]]",
					cur_node == mstr->start->node_number
					|| !(mtx[mstr->node_parent[cur_node]][A_LOADED])
					? "F->" : "B-<",
					cur_node,
					mtx[cur_node][A_LOADED]?"!":"",
					cur_node == mstr->start->node_number
					|| !mtx[cur_node][A_LOADED] || !mtx[next_node][A_LOADED]
					? "F" : "B",
					next_node,
					mtx[next_node][A_LOADED]?"!":"",
					mtx[next_node][A_VISITED_FLOW]);
			}

		}
	}
	return (DEAD_END);
}
