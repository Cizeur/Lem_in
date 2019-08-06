/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_count_inactive_pipes.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:31:44 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/03 14:41:55 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_output_count_inactive_pipes(t_master *mstr)
{
	int **mtx;
	int *solution_start;
	int active_pipes;
	int i;

	i = -1;
	mtx = mstr->adjacency_mtx;
	solution_start = mstr->stored_solution;
	active_pipes = 0;
	while (++i < mstr->final_flow)
		active_pipes += mtx[solution_start[i]][A_STORED_PATH_LEN] + 1;
	mstr->inactives_pipes_nb = mstr->pipes - active_pipes;
}
