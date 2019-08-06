/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_paths_shortener.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:04:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/06 10:11:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void	ft_path_cleaning(t_master *mstr, int path_number,
							 int cur_node, int end_node)
{
	int i;
	int *node_path;
	int **mtx;

	mtx = mstr->adjacency_mtx;
	node_path = mstr->node_path;
	mtx[end_node][A_PARENT_FLOW] = cur_node;
	node_path[mtx[cur_node][A_VISIT_FLOW] + 1] = end_node;
	i = mstr->nodes;
	while (--i)
	{
		if (node_path[i] == DISCONNECTED)
			continue;
		node_path[i - 1] = mtx[node_path[i]][A_PARENT_FLOW];
	}
	i = 0;
	mtx[node_path[1]][A_SOLUTION_START] = CERTAINLY;
	while (node_path[++i + 1] != DISCONNECTED)
	{
		mtx[node_path[i]][A_CURRENT_SOLUTION] = node_path[i + 1];
		mtx[node_path[i]][A_LOADED] = CERTAINLY;
		mtx[node_path[i]][A_PATH_NUMBER] = path_number;
		mtx[node_path[i]]
			[A_OPTIONS + mstr->nodes + node_path[i + 1]] = ACTIVATED;
	}
	mtx[node_path[0]][A_OPTIONS + mstr->nodes + node_path[1]] = ACTIVATED;
}

static int	ft_is_possible_next(t_master *mstr, int cur_node, int next_node)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (mtx[next_node][A_PATH_NUMBER] != DISCONNECTED)
		return (NOPE);
	if (next_node == mstr->start->node_number
			|| next_node == mtx[cur_node][A_PARENT_FLOW]
			|| mtx[next_node][A_LOADED]
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

static void	ft_init_stacks(t_master *mstr, int start_node, int *queue)
{
	int i;

	i = -1;
	while (++i < mstr->nodes)
	{
		mstr->adjacency_mtx[i][A_VISIT_FLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_PARENT_FLOW] = DISCONNECTED;
	}
	ft_intset(mstr->node_path, mstr->nodes, DISCONNECTED);
	ft_intset(mstr->node_queue, 2 * mstr->nodes, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->adjacency_mtx[start_node][A_VISIT_FLOW] = NOPE;
	queue[1] = 1;
	queue[0] = 0;
}

static int	ft_solver_one_path_shorten(t_master *mstr, int **mtx,
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
			if (ft_is_possible_next(mstr, cur_node, next_node))
				mstr->node_queue[queue[1]++ + queue[0]] = next_node;
		}
	}
	return (DEAD_END);
}

static void	ft_matrix_reset_one_path(t_master *mstr, int path)
{
	int i;
	int j;
	int **mtx;

	mtx = mstr->adjacency_mtx;
	i = -1;
	while ((j = -1) && ++i < mstr->nodes)
	{
		if (mtx[i][A_PATH_NUMBER] != path
				|| i == mstr->end->node_number
				|| i == mstr->start->node_number)
			continue;
		mtx[i][A_LOADED] = NOPE;
		mtx[i][A_CURRENT_SOLUTION] = DISCONNECTED;
		mtx[i][A_PATH_NUMBER] = DISCONNECTED;
		while (++j < mtx[i][A_LINKS_NB])
			mtx[i][A_OPTIONS + mstr->nodes + mtx[i][A_OPTIONS + j]] = INACTIVE;
		if (mtx[i][A_SOLUTION_START] == CERTAINLY)
			mtx[mstr->start->node_number]
			[A_OPTIONS + mstr->nodes + i] = INACTIVE;
		mtx[i][A_SOLUTION_START] = DISCONNECTED;
	}
}


int ft_solver_paths_shortener(t_master *mstr, int flow)
{
	int i;
	int **mtx;

	i = -1;
	mtx = mstr->adjacency_mtx;
	mtx[mstr->end->node_number][A_LOADED] = 0;
	i = -1;
	while (++i < flow)
	{
		ft_matrix_reset_one_path(mstr, i);
		if (ft_solver_one_path_shorten(mstr, mtx,
			mstr->start->node_number, i) == DEAD_END)
			ft_exit(DEAD_END_ON_SOLUTION);
	}
	return(SUCCESS);
}