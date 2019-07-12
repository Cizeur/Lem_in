/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_matrix_popping.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:20:38 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/12 16:41:47 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_no_more_links(int *mtx_node, int start)
{
	int j;
	int next_node;

	j = - 1;
	while( ++j < mtx_node[A_LINKS_NB])
		{
			next_node = mtx_node[j + start];
			if (next_node != DISCONNECTED)
				return(0);
		}
	return (1);
}

void			ft_matrix_popping(int max_nodes, int **mtx, int *node_path)
{
	int i;
	int next_node;
	int cur_node;
	int pos;

	i = 0;
	while((i + 1) < max_nodes && node_path[i + 1] != -1)
	{
		next_node = node_path[i + 1];
		cur_node = node_path[i];
		if (mtx[cur_node][max_nodes + A_OPTIONS + next_node] != ACTIVATED)
		{
			if((pos = ft_matrix_find_node(mtx[cur_node], A_OPTIONS, next_node)) != DISCONNECTED)
				ft_swap(&mtx[cur_node][A_OPTIONS + pos], &mtx[cur_node][A_OPTIONS + pos + 2 * max_nodes]);
			mtx[cur_node][max_nodes + A_OPTIONS + next_node] = ACTIVATED;
			mtx[next_node][max_nodes + A_OPTIONS + cur_node] = ACTIVATED;
			mtx[next_node][A_LOADED] = 1;
		}
		else
		{
			if((pos = ft_matrix_find_node(mtx[next_node], A_OPTIONS + max_nodes * 2, cur_node)) != DISCONNECTED)
				ft_swap(&mtx[next_node][A_OPTIONS + pos], &mtx[next_node][A_OPTIONS + pos + 2 * max_nodes]);
			if (ft_no_more_links(mtx[cur_node], 2 * max_nodes + A_OPTIONS))
			{
				mtx[cur_node][max_nodes + A_OPTIONS + next_node] = USED;
				mtx[next_node][max_nodes + A_OPTIONS + cur_node] = USED;
				mtx[cur_node][A_LOADED] = NOPE;
			}
		}
		i++;
	}
}
