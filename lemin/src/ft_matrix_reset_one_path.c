/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_reset_one_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 10:17:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/11/28 12:38:31 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_matrix_reset_one_path(t_master *mstr, int path)
{
	int i;
	int j;
	int **mtx;

	mtx = mstr->adjacency_mtx;
	i = -1;
	while ((j = -1) && ++i < mstr->nodes)
	{
		if (mtx[i][A_PATH_NUMBER] != path
				|| i == mstr->end->node_number
				|| i == mstr->start->node_number)
			continue;
		mtx[i][A_LOADED] = NOPE;
		mtx[i][A_CURRENT_SOLUTION] = DISCONNECTED;
		mtx[i][A_PATH_NUMBER] = DISCONNECTED;
		while (++j < mtx[i][A_LINKS_NB])
			mtx[i][A_OPTIONS + mstr->nodes + mtx[i][A_OPTIONS + j]] = INACTIVE;
		if (mtx[i][A_SOLUTION_START] == CERTAINLY)
			mtx[mstr->start->node_number]
			[A_OPTIONS + mstr->nodes + i] = INACTIVE;
		mtx[i][A_] = DISCONNECTED;
	}
}
