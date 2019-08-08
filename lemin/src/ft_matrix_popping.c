/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_popping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:20:38 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 13:55:07 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_matrix_popping(t_master *mstr, int max_nodes, int *node_path)
{
	int i;
	int next_node;
	int cur_node;
	int **mtx;

	i = 0;
	mtx = mstr->adjacency_mtx;
	while ((i + 1) < max_nodes && node_path[i + 1] != -1)
	{
		next_node = node_path[i + 1];
		cur_node = node_path[i];
		if (!(mtx[cur_node][A_LOADED] && mtx[next_node][A_LOADED]))
			mtx[cur_node][A_OPTIONS + max_nodes + next_node] = ACTIVATED;
		if (mtx[cur_node][A_LOADED] && mtx[next_node][A_LOADED])
		{
			mtx[next_node][A_OPTIONS + max_nodes + cur_node] = INACTIVE;
			if (mstr->output_type)
				ft_output_explained_cut_pipes(mstr, cur_node, next_node);
		}
		mtx[cur_node][A_LOADED] = CERTAINLY;
		i++;
	}
	mtx[node_path[0]][A_LOADED] = NOPE;
}
