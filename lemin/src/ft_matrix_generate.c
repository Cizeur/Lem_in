/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_generate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:29:07 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 15:27:37 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error.h"
#include "utils.h"
#include "libft/libft.h"

static void		ft_alloc_adjancency_matrix(t_master *mstr, int nodes)
{
	int i;
	int **mtx;
	int malloc_size;

	i = -1;
	malloc_size = mstr->nodes * sizeof(int);
	if (!(mtx = (int **)ft_memalloc(sizeof(int *) * nodes)))
		ft_exit(ADJACENCY_MTX, mstr);
	while (++i < nodes)
	{
		if (!(mtx[i] = (int *)ft_memalloc(sizeof(int)
				* (2 * nodes + A_OPTIONS))))
			ft_exit(ADJACENCY_MTX, mstr);
		ft_intset(mtx[i], 2 * nodes + A_OPTIONS, DISCONNECTED);
		mtx[i][A_LINKS_NB] = 0;
		mtx[i][A_LOADED] = 0;
	}
	mstr->node_queue = (int *)ft_memalloc(sizeof(int) * (2 * nodes + 1));
	mstr->node_parents = (int *)ft_memalloc(sizeof(int) * (2 * nodes + 1));
	mstr->node_path = (int *)ft_memalloc(sizeof(int) * (nodes + 1));
	mstr->stored_solution = (int *)ft_memalloc(sizeof(int) * (nodes + 1));
	if (!mstr->node_queue || !mstr->node_parents
			|| !mstr->node_path || !mstr->stored_solution)
		ft_exit(NODE_STACK_MTX, mstr);
	mstr->adjacency_mtx = mtx;
}

static void		ft_put_line_index_to_adjancency_matrix(
					t_master *mstr, int line_index, int node_number)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (mtx[node_number][A_LINE_INDEX] == DISCONNECTED)
		mtx[node_number][A_LINE_INDEX] = line_index;
	else if (mtx[node_number][A_LINE_INDEX] != line_index)
		ft_exit(ADJACENCY_MTX, mstr);
}

static void		ft_put_pipe_in_adjancency_matrix(
					t_master *mstr, int node1, int node2)
{
	int nodes;
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (mtx[node1][mstr->nodes + node2 + A_OPTIONS] != DISCONNECTED)
		return ;
	mtx[node1][mstr->nodes + node2 + A_OPTIONS] = INACTIVE;
	nodes = mtx[node1][A_LINKS_NB];
	mtx[node1][A_LINKS_NB] += 1;
	mtx[node1][A_OPTIONS + nodes] = node2;
	mtx[node2][mstr->nodes + node1 + A_OPTIONS] = INACTIVE;
	nodes = mtx[node2][A_LINKS_NB];
	mtx[node2][A_LINKS_NB] += 1;
	mtx[node2][A_OPTIONS + nodes] = node1;
}

void			ft_matrix_generate(t_master *mstr, t_storage *storage)
{
	int			ind;
	int			reduc_ind;
	t_line_info	*entry;

	ind = -1;
	ft_alloc_adjancency_matrix(mstr, mstr->nodes);
	while (++ind < mstr->lines_nb)
	{
		reduc_ind = ind % BATCH_MALLOC_SIZE;
		if (!reduc_ind && ind)
			storage = storage->next;
		if (!storage)
			ft_exit(ERROR_STORAGE, mstr);
		entry = &(storage->entry[reduc_ind]);
		if (entry)
		{
			if (entry->type == NODE)
				ft_put_line_index_to_adjancency_matrix(
						mstr, entry->line_index, entry->node_number);
			if (entry->type == PIPE)
				ft_put_pipe_in_adjancency_matrix(
						mstr, entry->pipe[0], entry->pipe[1]);
		}
	}
}
