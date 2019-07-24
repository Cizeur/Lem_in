/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:33:37 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/24 12:07:52 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"



static void			ft_path_cleaning(t_master *mstr)
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

static 	void 	ft_small_debug_print(t_master *mstr, int cur, int nex)
{
	if (DEBUG_PRINT_MATRIX)
	{
		printf("\n\n##########OVEEEERLOAD###############\n");
		printf("Between node : %d - %d      \n", cur, nex);
		ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
		printf("##########OVEEEERLOAD###############\n\n\n");
	}
}

static int		ft_path_is_overloaded(t_master *mstr)
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
		if (load >= 2)
		{
			mstr->killed++;
			if ((i = ft_matrix_find_node(mtx[cur], A_OPTIONS, nex)) != -1)
				mtx[cur][A_OPTIONS + i] = DEACTIVATED;
			else
				ft_exit(FAIL_LINE_GRAB);
			//
			ft_small_debug_print(mstr, cur, nex);
			//
			return (1);
		}
		i++;
	}
	return(0);
}

static void		ft_init_stacks(t_master *mstr, int start_node)
{
	ft_intset(mstr->node_lvl_stack, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_path, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_queue, mstr->nodes_nb, DISCONNECTED);
	ft_intset(mstr->node_parent, mstr->nodes_nb, DISCONNECTED);
	mstr->node_queue[0] = start_node;
	mstr->node_path[0] = start_node;
	mstr->node_lvl_stack[start_node] = 0;

}

int 			ft_solver_bfs(t_master *mstr, int cur_node, int end_node)
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
	while(queue_len)
	{
		cur_node = mstr->node_queue[queue_start];
		mstr->node_path[mstr->node_lvl_stack[cur_node]] = cur_node;
		queue_start++;
		queue_len--;
		i = -1;
		while( ++i < mtx[cur_node][A_LINKS_NB])
		{
			next_node = mtx[cur_node][A_OPTIONS + i];
			if (next_node < 0)
				continue;
			if (next_node == end_node)
			{
				mstr->node_parent[next_node] = cur_node;
				mstr->node_path[mstr->node_lvl_stack[cur_node] + 1] = end_node;
				ft_path_cleaning(mstr);
				if(ft_path_is_overloaded(mstr))
					return (ft_solver_bfs(mstr, mstr->start->node_number, mstr->end->node_number));
				return (SUCCESS);
			}
			else if (mstr->node_lvl_stack[next_node] == DISCONNECTED)
			{
				mstr->node_parent[next_node] = cur_node;
				mstr->node_queue[queue_start + queue_len++] = next_node;
				mstr->node_lvl_stack[next_node] = mstr->node_lvl_stack[cur_node] + 1;
			}
		}
	}
	return(DEAD_END);
}



void			ft_adjacency_matrix_solution_store(t_master *mstr)
{
	int i;
	int j;
	int **mtx;
	int possible_unused;

	i = -1;
	mtx = mstr->adjacency_mtx;
	while (++i < mstr->nodes_nb)
	{
		j = -1;
		while (++j < mtx[i][A_LINKS_NB])
			{
			mtx[i][j + A_OPTIONS + 3 * mstr->nodes_nb] = mtx[i][j + A_OPTIONS + 2 * mstr->nodes_nb];
			if ((possible_unused = mtx[i][j + A_OPTIONS]) >= 0
				&& mtx[i][mstr->nodes_nb + A_OPTIONS + possible_unused] == UNUSED)
				mtx[i][j + A_OPTIONS + 3 * mstr->nodes_nb] = mtx[i][j + A_OPTIONS];
			if (mtx[i][j + A_OPTIONS + 2 * mstr->nodes_nb] >= 0
				&& i != mstr->start->node_number)
				mtx[i][A_STORED_SOLUTION] = mtx[i][j + A_OPTIONS + 2 * mstr->nodes_nb];
			}
	}
}

void			solver(t_master *mstr)
{
	int magic[3];
	int flow = 0;

	magic[0] = mstr->ants_nb;
	magic[1] = mstr->adjacency_mtx[mstr->start->node_number][A_LINKS_NB];
	magic[2] = mstr->adjacency_mtx[mstr->end->node_number][A_LINKS_NB];
	mstr->magic_number= ft_min(ft_min(magic[0], magic[1]), magic[2]);
	//
	ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
	//
	while (flow < mstr->magic_number)
	{
		if(!(ft_solver_bfs(mstr, mstr->start->node_number, mstr->end->node_number)))
			break;
		ft_matrix_popping(mstr->nodes_nb, mstr->adjacency_mtx, mstr->node_path);
		ft_adjacency_matrix_solution_store(mstr);
		ft_solver_extract_path_len(mstr, mstr->nodes_nb);
		//
		ft_print_matrix(mstr, DEBUG_PRINT_MATRIX);
		//
		flow++;
	}
	if(!flow)
		ft_exit(NOT_CONNECTED);
	mstr->nb_solutions = flow;
}
