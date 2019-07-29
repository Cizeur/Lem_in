/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_solution_store.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 08:31:11 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/29 13:33:57 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_solver_solution_store(int **mtx, int max_nodes)
{
	int i;

	i = -1;
	while (++i < max_nodes)
	{
		mtx[i][A_STORED_PATH_LEN] = mtx[i][A_CURRENT_PATH_LEN];
		mtx[i][A_STORED_SOLUTION] = mtx[i][A_CURRENT_SOLUTION];
		mtx[i][A_CURRENT_PATH_LEN] = DISCONNECTED;
		mtx[i][A_CURRENT_SOLUTION] = DISCONNECTED;
	}
}
