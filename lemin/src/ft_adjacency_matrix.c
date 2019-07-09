/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjacency_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:29:07 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/09 12:50:44 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error.h"

static void    ft_alloc_adjancency_matrix(t_master *mstr)
{
    int     i;

    i = 0;
    if (!(mstr->adjacency_mtx = (int**)ft_memalloc(sizeof(int*) * mstr->nodes_nb)))
        ft_exit(ADJACENCY_MTX);
    while (i < mstr->nodes_nb)
    {
        if (!(mstr->adjacency_mtx[i] = (int*)ft_memalloc(sizeof(int) * (2 * mstr->nodes_nb + 4))))
            ft_exit(ADJACENCY_MTX);
        mstr->adjacency_mtx[i][mstr->nodes_nb + 1] = DISCONNECTED;
        mstr->adjacency_mtx[i][mstr->nodes_nb + 2] = DISCONNECTED;
        i++;
    }
}

static void    ft_put_line_index_to_adjancency_matrix(t_master *mstr, int line_index, int node_number)
{
    if (!(mstr->adjacency_mtx[node_number][mstr->nodes_nb]))
        mstr->adjacency_mtx[node_number][mstr->nodes_nb] = line_index;
    else if (mstr->adjacency_mtx[node_number][mstr->nodes_nb] != line_index)
        ft_exit(ADJACENCY_MTX);
}

static void    ft_calculate_start_end_adjancency_matrix(t_master *mstr)
{
    return;
    int     i;
    int     j;

    i = -1;


    while (++i < mstr->nodes_nb)
    {

        j = 0;
        while (j < mstr->nodes_nb && mstr->adjacency_mtx[i][j] == 0)
            j++;
        if (j != mstr->nodes_nb)
        {
            mstr->adjacency_mtx[i][mstr->nodes_nb + 1] = j;
            j = mstr->nodes_nb - 1;
            while (j >= 0 && mstr->adjacency_mtx[i][j] == 0)
                j--;
            mstr->adjacency_mtx[i][mstr->nodes_nb + 2] = j;
        }
    }
}

static void    ft_put_pipe_in_adjancency_matrix(t_master *mstr, int node1, int node2)
{
        int min;
        int max;
        int nodes;

        if (mstr->adjacency_mtx[node1][node2])
            return;

        nodes = mstr->adjacency_mtx[node1][mstr->nodes_nb + 3];
        mstr->adjacency_mtx[node1][mstr->nodes_nb + 3]++;
        mstr->adjacency_mtx[node1][mstr->nodes_nb + 4 + nodes] = node2;
        nodes = mstr->adjacency_mtx[node2][mstr->nodes_nb + 3];
        mstr->adjacency_mtx[node2][mstr->nodes_nb + 3]++;
        mstr->adjacency_mtx[node2][mstr->nodes_nb + 4 + nodes] = node1;
        mstr->adjacency_mtx[node1][node2] = 1;
        mstr->adjacency_mtx[node2][node1] = 1;
        min = mstr->adjacency_mtx[node1][mstr->nodes_nb + 1];
        max = mstr->adjacency_mtx[node1][mstr->nodes_nb + 2];
        mstr->adjacency_mtx[node1][mstr->nodes_nb + 1] = min == DISCONNECTED || min > node2 ? node2 : min;
        mstr->adjacency_mtx[node1][mstr->nodes_nb + 2] = max == DISCONNECTED || max < node2 ? node2 : max;
        min = mstr->adjacency_mtx[node2][mstr->nodes_nb + 1];
        max = mstr->adjacency_mtx[node2][mstr->nodes_nb + 2];
        mstr->adjacency_mtx[node2][mstr->nodes_nb + 1] = min == DISCONNECTED || min > node1 ? node1 : min;
        mstr->adjacency_mtx[node2][mstr->nodes_nb + 2] = max == DISCONNECTED || max < node1 ? node1 : max;
}

void		ft_adjacency_matrix_generate(t_master *mstr, t_storage *storage)
{
	int 			ind;
	int 			reduc_ind;
	t_line_info		*entry;

	ind = -1;
	ft_alloc_adjancency_matrix(mstr);
	while(++ind < mstr->lines_nb)
	{
		reduc_ind = ind % BATCH_MALLOC_SIZE;
		if (!reduc_ind && ind)
			storage = storage->next;
        if(!storage)
            ft_exit(ERROR_STORAGE);
		entry = &(storage->entry[reduc_ind]);
        if (entry)
        {
		    if(entry->type == NODE)
		    	ft_put_line_index_to_adjancency_matrix(
			    	mstr, entry->line_index, entry->node_number);
	    	if(entry->type == PIPE)
		    	ft_put_pipe_in_adjancency_matrix(
		    		mstr, entry->pipe[0], entry->pipe[1]);
        }
	}
	ft_calculate_start_end_adjancency_matrix(mstr);
}
