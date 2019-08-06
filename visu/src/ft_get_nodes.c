/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:14:30 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 15:57:43 by crfernan         ###   ########.fr       */
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
	int		i;

	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
}

int		ft_check_overlap(t_master *mstr, t_nodes *node)
{
	int		i;

	i = 0;
	while (i < mstr->current_node)
	{
		if (node->x == mstr->nodes_array[i]->x
		&& node->y == mstr->nodes_array[i]->y)
			return (ft_exit(mstr, OVERLAPING_ROOMS));
		i++;
	}
	return (TRUE);
}

int		ft_check_nodes(t_master *mstr, char **tmp)
{
	if (mstr->nodes_array[mstr->current_node]->name == NULL
	|| mstr->nodes_array[mstr->current_node]->len_name == 0
	|| (mstr->nodes_array[mstr->current_node]->x == 0 && tmp[1][0] != '0')
	|| (mstr->nodes_array[mstr->current_node]->y == 0 && tmp[2][0] != '0'))
		return (ft_exit(mstr, INVALID_INPUT));
	if (ft_check_overlap(mstr, mstr->nodes_array[mstr->current_node]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int		ft_get_nodes(t_master *mstr, char *line)
{
	char		**tmp;
	int			out;

	out = TRUE;
	if (ft_is_not_comment(mstr, line) == TRUE)
	{
		mstr->nodes_array[mstr->current_node]->node_index = mstr->current_node;
		tmp = ft_strsplit(line, ' ');
		mstr->nodes_array[mstr->current_node]->name = ft_strdup(tmp[0]);
		mstr->nodes_array[mstr->current_node]->len_name = ft_strlen(tmp[0]);
		mstr->nodes_array[mstr->current_node]->x = ft_atoi(tmp[1]);
		mstr->nodes_array[mstr->current_node]->y = ft_atoi(tmp[2]);
		if (mstr->nodes_array[mstr->current_node]->flag == NODE_START)
			mstr->start_name = ft_strdup(tmp[0]);
		if (mstr->nodes_array[mstr->current_node]->flag == NODE_END)
			mstr->end_name = ft_strdup(tmp[0]);
		out = ft_check_nodes(mstr, tmp);
		free_get_nodes(tmp);
		mstr->current_node++;
	}
	return (out);
}
