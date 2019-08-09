/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:42:24 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/09 16:40:26 by crfernan         ###   ########.fr       */
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

void	check_parameters(t_master *mstr)
{
	if ((mstr->nb_ants < TRUE)
	|| (mstr->nb_nodes < TRUE)
	|| (mstr->nb_pipes < TRUE)
	|| (mstr->nb_movements < TRUE)
	|| (mstr->nb_inactive < TRUE))
		ft_exit(mstr, INVALID_INPUT);
}

void	check_nodes_pipes_moves(t_master *mstr)
{
	if ((mstr->current_node > mstr->nb_nodes)
	|| (mstr->current_pipe > mstr->nb_pipes)
	|| (mstr->current_move > mstr->nb_movements))
		ft_exit(mstr, INVALID_INPUT);
	check_inactive_nodes(mstr);
}
