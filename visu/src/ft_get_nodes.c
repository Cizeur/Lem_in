/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:14:30 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/12 16:37:06 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_is_not_comment(t_master *mstr, char *line)
{
	if (line[0] != '#')
		return (1);
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
	return (0);
}

void	ft_free_tmp(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}

void	ft_get_nodes(t_master *mstr, char *line)
{
	char		**tmp;

	if (ft_is_not_comment(mstr, line) == 1)
	{
		mstr->nodes_array[mstr->current_node]->node_index = mstr->current_node;
		tmp = ft_strsplit(line, ' ');
		mstr->nodes_array[mstr->current_node]->name = ft_strdup(tmp[0]);
		mstr->nodes_array[mstr->current_node]->len_name = ft_strlen(tmp[0]);
		mstr->nodes_array[mstr->current_node]->x = ft_atoi(tmp[1]);
		mstr->nodes_array[mstr->current_node]->y = ft_atoi(tmp[2]);
		ft_free_tmp(tmp);
		mstr->current_node++;
	}
}