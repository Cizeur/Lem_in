/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_path_splitter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 09:36:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/11/28 16:58:42 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"
#include "libft/libft.h"
#include "output_explained.h"

static void		ft_path_cleaning(t_master *mstr, int queue_end, int end_node)
{
	int i;
	int j;

	mstr->node_queue[queue_end] = end_node;
	mstr->node_parents[queue_end] = queue_end - 1;
	i = queue_end + 1;
	j = 0;
	while (i--)
	{
		if (i == queue_end)
		{
			mstr->node_path[j++] = mstr->node_queue[i];
			queue_end = mstr->node_parents[i];
		}
	}
	queue_end = j - 1;
	j = -1;
	while (++j <= queue_end / 2)
		ft_swap(&mstr->node_path[j], &mstr->node_path[queue_end - j]);
	ft_output_explained(mstr, OC_OUTPUT_AUGMENTING_PATH);
}


static int		ft_check_node(t_master *mstr, t_stack_cell *qcur,
								int next_node, t_stack_cell *qend)
{
	t_cell *mtx;

	mtx = mstr->cells;
	if (mstr->cells[next_node].last_visit 
		&& mstr->cells[next_node].last_visit != V_FLOW)
		return (NOPE);
	if (mtx[qcur->cell].loaded
		&& mtx[qcur->cell].m[next_node].activation != A_RECEIVE)
		return (NOPE);
	qend->cell = next_node;
	qend->parent_in_stack = qcur;
	if (mtx[qcur->cell].m[next_node].activation == A_RECEIVE)
		qend->visite_type = V_BACKFLOW;
	else
		qend->visite_type = V_FLOW;
	return (SUCCESS);
}

int				ft_solver_paths_splitter(t_master *mstr, t_cell *mtx,
								int cur_node, int end_node)
{
	int cur_node;
	int next_node;
	t_stack_cell *qcur;
	t_stack_cell *qend;
	int node_adj;

	ft_init_stack(mstr, cur_node, queue);
	qcur = mstr->stack;
	qend = qcur++;
	while (!(node_adj = 0) && qcur->visite_type)
	{
		while (node_adj++ < mtx[qcur->cell].link_nb)
		{
			next_node = mtx[cur_node].m[node_adj].adjacency;
			if (next_node == end_node)
			{
				qend->cell = end_node;
				ft_path_cleaning(mstr, qend, end_node);
				return (SUCCESS);
			}
			if (ft_check_node(mstr, qcur, next_node ,qend))
				qend++;
		}
		qcur++;
	}
	return (DEAD_END);
}
