/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_popping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:20:38 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/03 17:46:33 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
/*
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
*/
void			ft_matrix_popping(int max_nodes, int **mtx, int *node_path)
{
	int i;
	int next_node;
	int cur_node;

	i = 0;
	while((i + 1) < max_nodes && node_path[i + 1] != -1)
	{
		next_node = node_path[i + 1];
		cur_node = node_path[i];
		mtx[next_node][A_LOADED] = CERTAINLY;
		mtx[cur_node][A_OPTIONS + max_nodes + next_node] = ACTIVATED;
		i++;
	}
}
