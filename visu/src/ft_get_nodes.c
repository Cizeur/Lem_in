/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:14:30 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/27 18:47:28 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_is_not_comment(t_master *mstr, char *line)
{
	if (line[0] != '#')
		return (TRUE);
	else if (ft_strstr(line, "##start"))
	{
		mstr->start_index = mstr->current_node;
		mstr->nodes_array[mstr->current_node]->flag = NODE_START;
	}
	else if (ft_strstr(line, "##end"))
	{
		mstr->end_index = mstr->current_node;
		mstr->nodes_array[mstr->current_node]->flag = NODE_END;
	}
	return (FALSE);
}

void	free_get_nodes(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}

void	ft_get_nodes(t_master *mstr, char *line)
{
	char		**tmp;

	if (ft_is_not_comment(mstr, line) == TRUE)
	{
		mstr->nodes_array[mstr->current_node]->node_index = mstr->current_node;
		tmp = ft_strsplit(line, ' ');
		mstr->nodes_array[mstr->current_node]->name = ft_strdup(tmp[0]);
		mstr->nodes_array[mstr->current_node]->len_name = ft_strlen(tmp[0]);
		mstr->nodes_array[mstr->current_node]->x = ft_atoi(tmp[1]);
		if (ft_atoi(tmp[1]) < mstr->min_x)
			mstr->min_x = ft_atoi(tmp[1]);
		if (ft_atoi(tmp[1]) > mstr->max_x)
			mstr->max_x = ft_atoi(tmp[1]);
		mstr->nodes_array[mstr->current_node]->y = ft_atoi(tmp[2]);
		if (ft_atoi(tmp[2]) < mstr->min_y)
			mstr->min_y = ft_atoi(tmp[2]);
		if (ft_atoi(tmp[2]) > mstr->max_y)
			mstr->max_y = ft_atoi(tmp[2]);
		if (mstr->nodes_array[mstr->current_node]->flag == NODE_START)
			mstr->start_name = ft_strdup(tmp[0]);
		if (mstr->nodes_array[mstr->current_node]->flag == NODE_END)
			mstr->end_name = ft_strdup(tmp[0]);
		free_get_nodes(tmp);
		mstr->current_node++;
	}
}