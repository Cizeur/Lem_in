/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_reset_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:25:13 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/05 14:45:37 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_matrix_reset_state(t_master *mstr)
{
	int i;
	int j;
	int **mtx;
	int linked_node;

	mtx = mstr->adjacency_mtx;
	i = -1;
	while ((j = -1) && ++i < mstr->nodes_nb)
	{
		if (!(mtx[i][A_LOADED])
			|| i == mstr->end->node_number
			|| i == mstr->start->node_number)
			continue;
		while (++j < mtx[i][A_LINKS_NB])
		{
			linked_node = mtx[i][A_OPTIONS + j];
			mtx[i][A_LOADED] = !mtx[i][A_LOADED_FINDER] ? NOPE : CERTAINLY;
			if (mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node]
					!= DISCONNECTED)
				mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node] = INACTIVE;
			if (mtx[i][A_LOADED_FINDER] && linked_node
					== mtx[i][A_CURRENT_SOLUTION])
				mtx[i][A_OPTIONS + mstr->nodes_nb + linked_node] = ACTIVATED;
		}
	}
}
