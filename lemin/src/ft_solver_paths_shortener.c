/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_paths_shortener.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:04:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/05 17:23:48 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void ft_path_cleaning(t_master *mstr, int path_number,
							 int cur_node, int end_node)
{
	int i;
	int *node_path;
	int **mtx;

	mtx = mstr->adjacency_mtx;
	node_path = mstr->node_path;
	mtx[end_node][A_PARENT_FLOW] = cur_node;
	node_path[mtx[cur_node][A_VISIT_FLOW] + 1] = end_node;
	i = mstr->nodes_nb;
	while (--i)
	{
		if (node_path[i] == DISCONNECTED)
			continue;
		node_path[i - 1] = mtx[node_path[i]][A_PARENT_FLOW];
	}
	i = -1;
	while (node_path[++i + 1] != DISCONNECTED)
	{
		mtx[node_path[i]][A_CURRENT_SOLUTION] = node_path[i + 1];
		mtx[node_path[i]][A_LOADED_FINDER] = CERTAINLY;
		mtx[node_path[i]][A_PATH_NUMBER] = path_number;
	}
}

static int ft_is_possible_next(t_master *mstr, int cur_node,
							   int next_node, int path_nb)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (mtx[next_node][A_PATH_NUMBER] != path_nb
			&& mtx[next_node][A_PATH_NUMBER] != DISCONNECTED)
		return (NOPE);
	if (next_node == mstr->start->node_number
			|| next_node == mtx[cur_node][A_PARENT_FLOW]
			|| mtx[next_node][A_LOADED_FINDER]
			|| next_node == DISCONNECTED)
		return (NOPE);
	if (mtx[next_node][A_VISIT_FLOW] == DISCONNECTED)
	{
		mtx[next_node][A_PARENT_FLOW] = cur_node;
		mtx[next_node][A_VISIT_FLOW] = mtx[cur_node][A_VISIT_FLOW] + 1;
		return (CERTAINLY);
	}
	return (NOPE);
}

static void ft_init_stacks(t_master *mstr, int start_node, int *queue)
{
	int i;

	i = -1;
	while (++i < mstr->nodes_nb)
	{
		mstr->adjacency_mtx[i][A_VISIT_FLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_PARENT_FLOW] = DISCONNECTED;
	}
	ft_intset(mstr->node_path, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_queue, 2 * mstr->nodes_nb, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->adjacency_mtx[start_node][A_VISIT_FLOW] = NOPE;
	queue[1] = 1;
	queue[0] = 0;
}

static int ft_solver_one_path_shorten(t_master *mstr, int **mtx,
									  int cur_node, int path_number)
{
	int next_node;
	int i;
	int queue[2];

	ft_init_stacks(mstr, cur_node, queue);
	while ((i = -1) && queue[1]--)
	{
		cur_node = mstr->node_queue[queue[0]++];
		while (++i < mtx[cur_node][A_LINKS_NB])
		{
			next_node = mtx[cur_node][A_OPTIONS + i];
			if (next_node == mstr->end->node_number)
			{
				ft_path_cleaning(mstr, path_number, cur_node, next_node);
				return (SUCCESS);
			}
			if (ft_is_possible_next(mstr, cur_node, next_node, path_number))
				mstr->node_queue[queue[1]++ + queue[0]] = next_node;
		}
	}
	return (DEAD_END);
}

void ft_matrix_reset_one_path(t_master *mstr, int path)
{
	int i;
	int j;
	int **mtx;
	int linked_node;

	mtx = mstr->adjacency_mtx;
	i = -1;
	while ((j = -1) && ++i < mstr->nodes_nb)
	{
		if (mtx[i][A_PATH_NUMBER] != path
				|| i == mstr->end->node_number
				|| i == mstr->start->node_number)
			continue;
		if (!mtx[i][A_LOADED_FINDER])
		{
			mtx[i][A_LOADED] = NOPE;
			mtx[i][A_CURRENT_SOLUTION] = DISCONNECTED;
		}
		else
			mtx[i][A_LOADED] = CERTAINLY;
		while (++j < mtx[i][A_LINKS_NB])
		{
			linked_node = mtx[i][A_OPTIONS + j];
			if (mtx[i][A_LOADED_FINDER] && linked_node == mtx[i][A_CURRENT_SOLUTION])
				mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node] = ACTIVATED;
			else
				mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node] = INACTIVE;
		}
	}
}

int		ft_get_starts(t_master *mstr, int start , int path)
{
	int **mtx;
	int linked_node;
	int j;

	mtx= mstr->adjacency_mtx;
	j = -1;
	while( ++j < mtx[mstr->start->node_number][A_LINKS_NB])
	{
		linked_node = mtx[start][A_OPTIONS + j];
		if ( mtx[start][A_OPTIONS + mstr->nodes_nb + linked_node] == ACTIVATED
			&& mtx[linked_node][A_PATH_NUMBER] == path)
			return (linked_node);
	}
	return(DISCONNECTED);
}

int ft_solver_paths_shortener(t_master *mstr, int flow)
{
	int i;
	int **mtx;
	int cur;

	i = -1;
	mtx = mstr->adjacency_mtx;
	while (++i < mstr->nodes_nb)
	{
		mtx[i][A_LOADED_FINDER] = NOPE;
		mtx[i][A_CURRENT_SOLUTION] = DISCONNECTED;
	}
	mtx[mstr->end->node_number][A_LOADED] = 0;
	i = -1;
	while (++i < flow)
	{
		cur = ft_get_starts(mstr, mstr->start->node_number , i);
		if (cur == DISCONNECTED
			||ft_solver_one_path_shorten(mstr, mtx,
				cur, i) == DEAD_END)
			ft_exit(DEAD_END_ON_SOLUTION);
		ft_matrix_reset_one_path(mstr, i );
	}
	return (SUCCESS);
}
