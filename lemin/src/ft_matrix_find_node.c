/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_find_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:36:34 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/12 16:36:56 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_matrix_find_node(int *mtx_node, int start, int needle_node)
{
	int j;
	int next_node;

	j = - 1;
	while( ++j < mtx_node[A_LINKS_NB])
		{
			next_node = mtx_node[j + start];
			if (next_node == needle_node)
				return(j);
		}
	return (-1);
}
