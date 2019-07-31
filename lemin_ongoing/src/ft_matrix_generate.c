/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_generate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:29:07 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 14:57:03 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error.h"
#include "utils.h"


static void    ft_alloc_adjancency_matrix(t_master *mstr)
{
    int     i;

    i = 0;
    if (!(mstr->adjacency_mtx = (int**)ft_memalloc(sizeof(int*) * mstr->nodes_nb)))
        ft_exit(ADJACENCY_MTX);
    while (i < mstr->nodes_nb)
    {
        if (!(mstr->adjacency_mtx[i] = (int*)ft_memalloc(sizeof(int) * (4 * (mstr->nodes_nb) + A_OPTIONS))))
            ft_exit(ADJACENCY_MTX);
        ft_intset(mstr->adjacency_mtx[i], 4 * mstr->nodes_nb + A_OPTIONS , DISCONNECTED);
        mstr->adjacency_mtx[i][A_LINKS_NB] = 0;
        mstr->adjacency_mtx[i][A_LOADED] = 0;
        i++;
    }
    if (!(mstr->node_lvl_stack = (int*)ft_memalloc(sizeof(int) * (mstr->nodes_nb + 1))))
        ft_exit(NODE_STACK_MTX);
    if (!(mstr->node_queue = (int*)ft_memalloc(sizeof(int) * 2 * (mstr->nodes_nb + 1))))
        ft_exit(NODE_STACK_MTX);
    if (!(mstr->node_path = (int*)ft_memalloc(sizeof(int) * (mstr->nodes_nb + 1))))
        ft_exit(NODE_STACK_MTX);
    if (!(mstr->node_parent = (int*)ft_memalloc(sizeof(int) * (mstr->nodes_nb + 1))))
        ft_exit(NODE_STACK_MTX);
    if (!(mstr->stored_solution = (int*)ft_memalloc(sizeof(int) * (mstr->nodes_nb + 1))))
        ft_exit(NODE_STACK_MTX);
}

static void    ft_put_line_index_to_adjancency_matrix(t_master *mstr, int line_index, int node_number)
{
    if (mstr->adjacency_mtx[node_number][A_LINE_INDEX] == DISCONNECTED)
        mstr->adjacency_mtx[node_number][A_LINE_INDEX] = line_index;
    else if (mstr->adjacency_mtx[node_number][A_LINE_INDEX] != line_index)
        ft_exit(ADJACENCY_MTX);
}

static void    ft_put_pipe_in_adjancency_matrix(t_master *mstr, int node1, int node2)
{
        int nodes;

        if (mstr->adjacency_mtx[node1][mstr->nodes_nb + node2 + A_OPTIONS] != DISCONNECTED)
            return;
        mstr->adjacency_mtx[node1][mstr->nodes_nb + node2 + A_OPTIONS] = 1;
        nodes = mstr->adjacency_mtx[node1][A_LINKS_NB];
        mstr->adjacency_mtx[node1][A_LINKS_NB]+=1;
        mstr->adjacency_mtx[node1][A_OPTIONS + nodes] = node2;

        mstr->adjacency_mtx[node2][mstr->nodes_nb + node1 + A_OPTIONS] = 1;
        nodes = mstr->adjacency_mtx[node2][A_LINKS_NB];
        mstr->adjacency_mtx[node2][A_LINKS_NB]+=1;
        mstr->adjacency_mtx[node2][A_OPTIONS + nodes] = node1;

}

void		ft_matrix_generate(t_master *mstr, t_storage *storage)
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
 }
