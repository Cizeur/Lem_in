/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_paths_finder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 11:04:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/03 18:12:20 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void		ft_init_stacks(t_master *mstr, int start_node)
{
	int i;

	i = -1;
	while (++i < mstr->nodes_nb)
	{
		mstr->adjacency_mtx[i][A_VISITED_FLOW] = DISCONNECTED;
		mstr->adjacency_mtx[i][A_PARENT_FLOW] = DISCONNECTED;
	}
	ft_intset(mstr->node_path, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_queue, 2 * mstr->nodes_nb, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->adjacency_mtx[start_node][A_VISITED_FLOW] = 0;
}

static void		ft_path_cleaning(t_master *mstr, int path_number)
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
		node_path[i - 1] = mtx[node_path[i]][A_PARENT_FLOW];
	}
	mtx[node_path[1]][A_SOLUTION_START] = 1;
	while (node_path[++i + 1] != DISCONNECTED)
	{
		mtx[node_path[i]][A_CURRENT_SOLUTION] = node_path[i + 1];
		mtx[node_path[i]][A_LOADED_FINDER] = CERTAINLY;
		mtx[node_path[i]][A_PATH_NUMBER] = path_number;
	}
}

static int		ft_is_possible_next(t_master *mstr, int cur_node, int next_node)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (next_node == DISCONNECTED
		|| next_node == mstr->start->node_number
		|| next_node == mtx[cur_node][A_PARENT_FLOW]
		|| mtx[next_node][A_LOADED_FINDER]
		|| mtx[cur_node][mstr->nodes_nb + A_OPTIONS + next_node] != ACTIVATED)
		return (NOPE);
	return (CERTAINLY);
}

int		ft_solver_one_path_finder(t_master *mstr, int cur_node, int end_node, int path_number)
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
			if (next_node == end_node)
			{
				mtx[end_node][A_PARENT_FLOW] = cur_node;
				mstr->node_path[mtx[cur_node][A_VISITED_FLOW] + 1] = end_node;
				ft_path_cleaning(mstr, path_number);
				return (SUCCESS);
			}
			if (!ft_is_possible_next(mstr, cur_node, next_node))
				continue;
			if (mtx[next_node][A_VISITED_FLOW] == DISCONNECTED)
			{
				mtx[next_node][A_PARENT_FLOW] = cur_node;
				mstr->node_queue[queue_len++ +queue_start] = next_node;
				mtx[next_node][A_VISITED_FLOW] = mtx[cur_node][A_VISITED_FLOW] + 1;
			}
		}
	}
	return (DEAD_END);
}

void			ft_unload_nodes(t_master *mstr)
{
	int i;
	int j;
	int **mtx;
	int linked_node;

	mtx = mstr->adjacency_mtx;
	i = -1;
	while ((j = -1) && ++i < mstr->nodes_nb)
	{
		if (!(mtx[i][A_LOADED])
			|| i == mstr->end->node_number
			|| i == mstr->start->node_number)
			continue;
		while (++j < mtx[i][A_LINKS_NB])
		{
			linked_node = mtx[i][A_OPTIONS + j];
			if (!mtx[i][A_LOADED_FINDER])
				mtx[i][A_LOADED] = NOPE;
			if (mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node] != DISCONNECTED)
				mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node] = 1;
			if (mtx[i][A_LOADED_FINDER] && linked_node == mtx[i][A_CURRENT_SOLUTION])
				mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node] = ACTIVATED;
		}
	}
}

int				ft_solver_paths_finder(t_master *mstr, int flow)
{
	int i;
	int **mtx;

	i = -1;
	mtx = mstr->adjacency_mtx;
	while (++i < mstr->nodes_nb)
	{
		mtx[i][A_LOADED_FINDER] = NOPE;
		mtx[i][A_PATH_NUMBER] = DISCONNECTED;
	}
	mtx[mstr->end->node_number][A_LOADED] = 0;
	i = -1;
	while (++i < flow)
	{
		if (ft_solver_one_path_finder(mstr, mstr->start->node_number,
					mstr->end->node_number, i) == DEAD_END)
		{
			printf("#NOPE %d\n", flow);
			return (DEAD_END);
		}
		ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
	}
	printf("#YES %d\n", flow);
	ft_unload_nodes(mstr);
	ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
	return (SUCCESS);
}
