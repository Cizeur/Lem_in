/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_generate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:29:07 by crfernan          #+#    #+#             */
/*   Updated: 2019/11/28 15:09:18 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error.h"
#include "utils.h"
#include "libft/libft.h"

static void		ft_alloc_adjancency_matrix(t_master *mstr, int nodes)
{
	int				i;
	t_cell			*mtx;
	t_matrix_cell	*mtx_val;

	mtx = (t_cell *)ft_memalloc(sizeof(t_cell) * nodes);
	mtx_val = (t_matrix_cell *)\
		ft_memalloc(sizeof(t_matrix_cell) * nodes * nodes);
	if (!mtx || !mtx_val)
		ft_exit(ADJACENCY_MTX, mstr);
	i = -1;
	while (++i < nodes)
	{
		mtx[i].line_index = INIT_VAL;
		mtx[i].m = &mtx_val[i * nodes];
	}
	mstr->stack = \
		(t_stack_cell *)ft_memalloc(sizeof(t_stack_cell) * (nodes + 1));
	mstr->stored_solution = (int *)ft_memalloc(sizeof(int) * nodes);
	mstr->solution_start = (int *)ft_memalloc(sizeof(int) * nodes);
	if (!mstr->stack || !mstr->stored_solution || !mstr->solution_start)
		ft_exit(NODE_STACK_MTX, mstr);
	mstr->cells = mtx;
	mstr->adjacency_mtx = mtx_val;
}

static void		ft_put_line_index_to_adjancency_matrix(
					t_master *mstr, int line_index, int node_number)
{
	t_cell **mtx;

	mtx = &mstr->cells;
	if (mtx[node_number]->line_index == INIT_VAL)
		mtx[node_number]->line_index = line_index;
	else if (mtx[node_number]->line_index != line_index)
		ft_exit(ADJACENCY_MTX, mstr);
}

static void		ft_put_pipe_in_adjancency_matrix(
					t_master *mstr, int node1, int node2)
{
	int nodes;
	t_cell **mtx;

	mtx = &mstr->cells;
	if (mtx[node1]->m[node2].activation
		|| node1 == node2)
		return ;
	mtx[node1]->m[node2].activation = A_INACTIVE;
	nodes = mtx[node1]->link_nb;
	mtx[node1]->link_nb += 1;
	mtx[node1]->m[nodes].adjacency = node2;
	mtx[node2]->m[node1].activation = A_INACTIVE;
	nodes = mtx[node2]->link_nb;
	mtx[node2]->link_nb += 1;
	mtx[node2]->m[nodes].adjacency = node1;
}

void			ft_matrix_generate(t_master *mstr, t_storage *storage)
{
	int			ind;
	int			reduc_ind;
	t_line_info	*entry;

	ind = -1;
	ft_alloc_adjancency_matrix(mstr, mstr->cells);
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
