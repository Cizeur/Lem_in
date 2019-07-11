/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:33:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/11 18:57:38 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

static void    ft_print_matrix(t_master *mstr)
{
    int     i;
	int		j;
	return;
  	i = -1;
    while ((j = -1) && ++i < mstr->nodes_nb)
    {
        printf("\033[0;34m%5.*s : \33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][A_LINE_INDEX])->name_len,
			ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][A_LINE_INDEX])->line);
		printf ("node : %4d |", i);
		while (++j < 3 * mstr->nodes_nb + A_OPTIONS)
   		{

			if (j == mstr->nodes_nb + A_OPTIONS || j == 2 * mstr->nodes_nb + A_OPTIONS)
				printf("%3s", "|");
			if (mstr->adjacency_mtx[i][j] == DISCONNECTED)
				printf("%3s", " . ");
			else if (mstr->adjacency_mtx[i][j] == DEACTIVATED)
				printf("\033[0;31m%3s\033[0m", " X ");
			else if (j < A_OPTIONS)
				printf("\033[0;32m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else
				printf("%3d", mstr->adjacency_mtx[i][j]);

		}
		printf ("\n");
	}
	i = -1;

	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
		break;

	        printf("\033[0;34m%5.*s\33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->name_len,
			ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->line);
	}
		while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
		break;

	        printf("\033[0;34m%5.*s : \33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->name_len,
			ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->line);
	}
	i = -1;
	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
		break;
		printf("%5d", mstr->node_path[i]);
	}
	printf("\n");
	i = -1;
	while (++i < mstr->nodes_nb)
		printf("||%3d - %3d||", mstr->node_parent[i], mstr->node_queue[i]);
		printf("\n");
	i = -1;
	while (++i < mstr->nodes_nb)
		printf("%3d", mstr->node_lvl_stack[i]);
		printf("\n");
		i = -1;
}

static int		ft_find_next_node(int *mtx_node, int start, int needle_node)
{
	int j;
	int next_node;

	j = - 1;
	while( ++j < mtx_node[A_LINKS_NB])
		{
			next_node = mtx_node[j + start];
			if (next_node == needle_node)
				return(j);
		}
	return (-1);
}
/*
int				ft_good_path(int *load_path, int length)
{
	int i;

	i = -1;

	while (++i < length)
	{
		if (load_path[i] > 1)
			return (0);
	}
	return(1);
}
*/

void			ft_clean_path(t_master *mstr)
{
	int i;

	i = mstr->nodes_nb;
	while (--i)
	{
		if (mstr->node_path[i] == DISCONNECTED)
			continue;
		mstr->node_path[i - 1] = mstr->node_parent[mstr->node_path[i]];
	}
}
/*
void			ft_printf_node_path(t_master *mstr)
{
		int i;
	i = -1;

	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_parent[i] == -1)
			printf(" nope ");
		else
	        printf("\033[0;34m%5.*s \33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_parent[i]][A_LINE_INDEX])->name_len,
			ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_parent[i]][A_LINE_INDEX])->line);
	}
	printf("\n");
	i = -1;
	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
			printf(" nope ");
		else
	        printf("\033[0;35m%5.*s \33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->name_len,
			ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->line);
	}
	printf("\n");
	i = -1;
	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_parent[i] == -1)
			printf(" nope ");
		else
	        printf("\033[0;34m%3d \33[0m", mstr->node_parent[i]);
	}
	printf("\n");
	i = -1;
	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
			printf(" nope ");
		else
	        printf("\033[0;35m%3d \33[0m",mstr->node_path[i]);
	}
	printf("\n");
}
*/

int				ft_overloaded_path(t_master *mstr)
{
	int i;
	int prev;
	int cur;
	int nex;
	int **mtx;
	int load;

	mtx = mstr->adjacency_mtx;
	i = 1;
	while (mstr->node_path[i + 1] != -1 && i < mstr->nodes_nb - 1)
	{
		load = 0;
		prev = mstr->node_path[i - 1];
		cur = mstr->node_path[i];
		nex = mstr->node_path[i + 1];
		load += mtx[prev][A_LOADED] ? -1 : 0;
		load += mtx[cur][A_LOADED] ? 2 : 0;
		if (cur != mstr->end->node_number)
			load += mtx[nex][A_LOADED] ? -1 : 0;
		//printf("[[prec : %d - cur : %d - nex : %d ]] load : %d", prev, cur , nex, load);
		if (load >= 2)
		{
		//	printf("[[prec : %d - cur : %d - nex : %d ]] load : %d", prev, cur , nex, load);
			if ((i = ft_find_next_node(mtx[cur], A_OPTIONS, nex)) != -1)
				mtx[cur][A_OPTIONS + i] = DEACTIVATED;
			else
				ft_exit(FAIL_LINE_GRAB);
			return (1);
		}
		i++;
	}
	return(0);
}

int 			ft_solver_bfs(t_master *mstr, int cur_node, int end_node)
{
	int **mtx;
	int next_node;
	int i;
	int queue_len;
	int queue_start;
	int output;

	mtx = mstr->adjacency_mtx;
	mtx = mstr->adjacency_mtx;
	ft_intset(mstr->node_lvl_stack, mstr->nodes_nb, -1);
	ft_intset(mstr->node_path, mstr->nodes_nb, -1);
	ft_intset(mstr->node_queue, mstr->nodes_nb, -1);
	ft_intset(mstr->node_parent, mstr->nodes_nb, -1);
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
		output = cur_node;
		i = -1;
		while( ++i < mtx[cur_node][A_LINKS_NB])
		{

			next_node = mtx[cur_node][A_OPTIONS + i];
			if (next_node < 0)
				continue;
			if (next_node == end_node )
			{
				mstr->node_parent[next_node] = cur_node;
				mstr->node_path[mstr->node_lvl_stack[cur_node] + 1] = end_node;
				ft_clean_path(mstr);
				if(ft_overloaded_path(mstr))
				{
					ft_print_matrix(mstr);
					printf("\n\n##########OVEEEERLOAD###############\n");
					printf("##########OVEEEERLOAD###############\n\n\n");
					return (ft_solver_bfs(mstr, mstr->start->node_number, mstr->end->node_number));
				}
				return (SUCCESS);
			}
			else if (mstr->node_lvl_stack[next_node] == -1)
			{
				mstr->node_parent[next_node] = cur_node;
				mstr->node_queue[queue_start + queue_len++] = next_node;
				mstr->node_lvl_stack[next_node] = mstr->node_lvl_stack[cur_node] + 1;
			}
		}
	}
	return(DEAD_END);
}





void			ft_pop_matrix(int max_nodes, int **mtx, int *node_path)
{
	int i;
	int next_node;
	int cur_node;
	int pos;

	i = 0;
	while(node_path[i + 1] != -1  && (i + 1) < max_nodes)
	{
		next_node = node_path[i + 1];
		cur_node = node_path[i];
		if (mtx[cur_node][max_nodes + A_OPTIONS + next_node] != 2)
		{
			if((pos = ft_find_next_node(mtx[cur_node], A_OPTIONS, next_node)) != -1)
				ft_swap(&mtx[cur_node][A_OPTIONS + pos], &mtx[cur_node][A_OPTIONS + pos + 2 * max_nodes]);
			mtx[cur_node][max_nodes + A_OPTIONS + next_node] = ACTIVATED;
			mtx[next_node][max_nodes + A_OPTIONS + cur_node] = ACTIVATED;
			mtx[next_node][A_LOADED] = 1;
		}
		else
		{
			if((pos = ft_find_next_node(mtx[next_node], A_OPTIONS + max_nodes * 2, cur_node)) != -1)
				mtx[next_node][A_OPTIONS + pos + 2 * max_nodes] = -1;
			mtx[cur_node][max_nodes + A_OPTIONS + next_node] = 1;
			mtx[next_node][max_nodes + A_OPTIONS + cur_node] = 1;
			mtx[next_node][A_LOADED] = 0;
		}
		i++;
	}
}



void			solver(t_master *mstr)
{
	int magic[3];
	int flow = 0;
	int i;

	magic[0] = mstr->ants_nb;
	magic[1] = mstr->adjacency_mtx[mstr->start->node_number][A_LINKS_NB];
	magic[2] = mstr->adjacency_mtx[mstr->end->node_number][A_LINKS_NB];
	ft_intset(mstr->node_lvl_stack, mstr->nodes_nb, -1);
	ft_intset(mstr->node_path, mstr->nodes_nb, -1);
	ft_intset(mstr->node_queue, 2 * mstr->nodes_nb, -1);
	printf("max flow options -%d -%d -%d\n", magic[0],magic[1],magic[2]);
	mstr->magic_number= ft_min(ft_min(magic[0], magic[1]), magic[2]);
	ft_print_matrix(mstr);
	printf("WAAAAT\n");

	while (flow < mstr->magic_number)
	{
		if(!(ft_solver_bfs(mstr, mstr->start->node_number, mstr->end->node_number)))
			break;
		ft_pop_matrix(mstr->nodes_nb, mstr->adjacency_mtx, mstr->node_path);
		ft_print_matrix(mstr);
		flow++;
		i = -1;
	}
	printf("\n\nmax flow -%d\n", mstr->magic_number);
	printf("final flow -%d\n", flow);
	if(!flow)
		ft_exit(NOT_CONNECTED);
	//ft_print_matrix(mstr);
	return;
		ft_print_matrix(mstr);
}
