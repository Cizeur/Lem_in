/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:33:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/09 19:19:59 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_solver_bfs(t_master *mstr, int cur_node)
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
	ft_bzero(mstr->node_lvl_stack, sizeof(int) * mstr->nodes_nb);
	ft_bzero(mstr->node_queue, sizeof(int) * mstr->nodes_nb);
	mstr->node_queue[0] = cur_node;
	mstr->node_lvl_stack[cur_node] = 1;
	queue_len = 1;
	queue_start = 0;
	while(queue_len)
	{
		cur_node = mstr->node_queue[queue_start];
		queue_start++;
		queue_len--;
		i = -1;
		while( ++i < mtx[cur_node][mstr->nodes_nb + 3])
		{
			next_node = mtx[cur_node][dec[1] + i];
			if (!mstr->node_lvl_stack[next_node])
			{
				mstr->node_queue[queue_start + 1 + queue_len++] = next_node;
				mstr->node_lvl_stack[next_node] = mstr->node_lvl_stack[cur_node] + 1;
			}
		}
	}
}


void			solver(t_master *mstr)
{
	int magic[3];

	magic[0] = mstr->ants_nb;
	magic[1] = mstr->adjacency_mtx[mstr->start->node_number][mstr->nodes_nb + 3];
	magic[2] = mstr->adjacency_mtx[mstr->end->node_number][mstr->nodes_nb + 3];
	mstr->magic_number= ft_min(ft_min(magic[0], magic[1]), magic[2]);
	ft_solver_bfs(mstr, mstr->start->node_number);
	int i = -1;
	printf("\n");
	while (++i < mstr->nodes_nb)
		printf("%3d", mstr->node_lvl_stack[i]);
		printf("\n");
}
