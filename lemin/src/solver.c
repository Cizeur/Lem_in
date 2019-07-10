/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:33:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/10 09:39:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

int 			ft_solver_bfs(t_master *mstr, int cur_node, int end_node)
{
	int dec[2];
	int **mtx;
	int next_node;
	int i;
	int queue_len;
	int queue_start;

	mtx = mstr->adjacency_mtx;
	dec[0] = mstr->nodes_nb + 4;
	dec[1] = 2 * mstr->nodes_nb + 4;
	mtx = mstr->adjacency_mtx;
	ft_intset(mstr->node_lvl_stack, mstr->nodes_nb, -1);
	ft_intset(mstr->node_path, mstr->nodes_nb, -1);
	ft_intset(mstr->node_queue, mstr->nodes_nb, -1);
	mstr->node_queue[0] = cur_node;
	mstr->node_lvl_stack[cur_node] = 0;
	queue_len = 1;
	queue_start = 0;
	mstr->node_path[0] = cur_node;
	while(queue_len)
	{
		cur_node = mstr->node_queue[queue_start];
		mstr->node_path[mstr->node_lvl_stack[cur_node]] = cur_node;
		queue_start++;
		queue_len--;
		i = -1;
		while( ++i < mtx[cur_node][mstr->nodes_nb + 3])
		{
			next_node = mtx[cur_node][dec[1] + i];
			mstr->node_path[mstr->node_lvl_stack[cur_node] + 1] = next_node;
			if (next_node == end_node)
				return(SUCCESS);
			if (next_node >= 0 && mstr->node_lvl_stack[next_node] == -1)
			{
				mstr->node_queue[queue_start + queue_len++] = next_node;
				mstr->node_lvl_stack[next_node] = mstr->node_lvl_stack[cur_node] + 1;
			}
		}
		printf("\n");
	}
	return(DEAD_END);
}

void			ft_pop_matrix(int max_nodes, int **mtx, int *node_path)
{
	int i;
	int j;
	int next_node;

	i = 0;
	while((j = -1) && node_path[i + 1] != -1 && (i + 1) < max_nodes)
	{
		while( ++j < mtx[node_path[i]][max_nodes + 3])
		{
			next_node = mtx[node_path[i]][ 2 * max_nodes + 4 + j];
			if (next_node == node_path[i + 1])
			{
				mtx[node_path[i]][max_nodes + 4 + j] = node_path[i + 1];
				mtx[node_path[i]][ 2 * max_nodes + 4 + j] = -1;
				break;
			}
		}
		j = -1;
		while( ++j < mtx[node_path[i + 1]][max_nodes + 3])
		{
			next_node = mtx[node_path[i + 1]][max_nodes + 4 + j];
			if (next_node == node_path[i])
			{
				mtx[node_path[i + 1]][max_nodes + 4 + j] = 0;
				break;
			}
		}
		i++;
	}
}

static void    ft_print_matrix(t_master *mstr)
{
    int     i;
	int		j;

  	i = -1;

    while ((j = -1) && ++i < mstr->nodes_nb)
    {
        printf ("node : %4d |", i);
		while (++j < 3 * mstr->nodes_nb + 4)
   		{

			if (j > 2 * mstr->nodes_nb + 3 + mstr->adjacency_mtx[i][mstr->nodes_nb + 3])
				break;
			else if (j == mstr->nodes_nb)
				printf("%5.*s",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][mstr->nodes_nb])->name_len,
				ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][mstr->nodes_nb])->line);
			else if (j > mstr->nodes_nb + 3)
				printf ("\033[0;33m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else if (mstr->adjacency_mtx[i][j] && j < mstr->nodes_nb)
				printf ("\033[0;31m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else if (mstr->adjacency_mtx[i][j])
				printf ("\033[0;32m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else
				printf ("%3d", mstr->adjacency_mtx[i][j]);
		}
		printf ("\n");
	}
	i = -1;
	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
		break;
		printf("%3d", mstr->node_path[i]);
		 //printf("%5.*s",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][mstr->nodes_nb])->name_len,
		//ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][mstr->nodes_nb])->line);
	}
	printf("\n");
	i = -1;
	while (++i < mstr->nodes_nb)
		printf("%3d", mstr->node_queue[i]);
		printf("\n");
	i = -1;
	while (++i < mstr->nodes_nb)
		printf("%3d", mstr->node_lvl_stack[i]);
		printf("\n");
}

void			solver(t_master *mstr)
{
	int magic[3];

	magic[0] = mstr->ants_nb;
	magic[1] = mstr->adjacency_mtx[mstr->start->node_number][mstr->nodes_nb + 3];
	magic[2] = mstr->adjacency_mtx[mstr->end->node_number][mstr->nodes_nb + 3];
	mstr->magic_number= ft_min(ft_min(magic[0], magic[1]), magic[2]);

	ft_print_matrix(mstr);
	if(!(ft_solver_bfs(mstr, mstr->start->node_number, mstr->end->node_number)))
		ft_exit(NOT_CONNECTED);
	ft_pop_matrix(mstr->nodes_nb, mstr->adjacency_mtx, mstr->node_path);
	ft_print_matrix(mstr);
	ft_solver_bfs(mstr, mstr->start->node_number, mstr->end->node_number);
	ft_pop_matrix(mstr->nodes_nb, mstr->adjacency_mtx, mstr->node_path);
	ft_print_matrix(mstr);
}
