/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inactive_nodes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:42:24 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 17:21:26 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/get_next_line.h"

void	min_and_max_(t_master *mstr, int i)
{
	if (mstr->nodes_array[i]->x < mstr->min_x)
		mstr->min_x = mstr->nodes_array[i]->x;
	if (mstr->nodes_array[i]->x > mstr->max_x)
		mstr->max_x = mstr->nodes_array[i]->x;
	if (mstr->nodes_array[i]->y < mstr->min_y)
		mstr->min_y = mstr->nodes_array[i]->y;
	if (mstr->nodes_array[i]->y > mstr->max_y)
		mstr->max_y = mstr->nodes_array[i]->y;
}

void	check_inactive_nodes(t_master *mstr)
{
	int		i;
	int		j;
	int		node_used;

	i = 0;
	while (i < mstr->nb_nodes)
	{
		j = 0;
		node_used = FALSE;
		while (j < mstr->nodes_array[i]->nb_pipes)
		{
			if (mstr->pipes_array[mstr->nodes_array[i]->pipes[j]]->active
			== PIPE_ACTIVE)
				node_used = TRUE;
			j++;
		}
		if (node_used == FALSE)
			mstr->nodes_array[i]->flag = NODE_UNUSED;
		else
			min_and_max_(mstr, i);
		i++;
	}
}
