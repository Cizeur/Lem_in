/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:36:49 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/12 10:19:41 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"


/*
void				ft_solution_print(t_master *mstr)
{
	int i;
	int **mtx;

	i = -1;
	mtx = mstr->adjacency_mtx;
	printf("##SOLUTIONS## :\n");
	ft_intset(mstr->node_lvl_stack, mstr->nodes_nb + 1, DISCONNECTED);
	ft_intset(mstr->node_queue, mstr->nodes_nb + 1, DISCONNECTED);
	while (++i < mstr->nodes_nb)
	{
		ft_intset(mstr->node_path, mstr->nodes_nb + 1, DISCONNECTED);
		if ( mtx[mstr->start->node_number][i + 2 * mstr->nodes_nb + A_OPTIONS] != DISCONNECTED)
			ft_solution_print_one(mstr);
	//	printf("\n");
	}
}
*/
