/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:14:30 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/09 15:14:06 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/libft.h"

int		ft_start_end(t_master *mstr, char *line)
{
	if (ft_strstr(line, "##start"))
	{
		mstr->start_index = mstr->current_node;
		mstr->nodes_array[mstr->current_node]->flag = NODE_START;
		return (TRUE);
	}
	if (ft_strstr(line, "##end"))
	{
		mstr->end_index = mstr->current_node;
		mstr->nodes_array[mstr->current_node]->flag = NODE_END;
		return (TRUE);
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

void	ft_check_overlap(t_master *mstr, t_nodes *node, char **tmp)
{
	int		i;

	i = 0;
	while (i < mstr->current_node)
	{
		if (node->x == mstr->nodes_array[i]->x
		&& node->y == mstr->nodes_array[i]->y)
		{
			free_get_nodes(tmp);
			ft_exit(mstr, OVERLAPING_ROOMS);
		}
		i++;
	}
}

void		ft_check_nodes(t_master *mstr, char **tmp)
{
	if ((mstr->nodes_array[mstr->current_node]->name == NULL)
	|| (mstr->nodes_array[mstr->current_node]->len_name == 0)
	|| (mstr->nodes_array[mstr->current_node]->x == 0 && tmp[1][0] != '0')
	|| (mstr->nodes_array[mstr->current_node]->y == 0 && tmp[2][0] != '0'))
	{
		free_get_nodes(tmp);
		ft_exit(mstr, INVALID_INPUT);
	}
}

void		ft_get_nodes(t_master *mstr, char *line)
{
	char		**tmp;

	if (ft_start_end(mstr, line) == FALSE)
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
		ft_check_nodes(mstr, tmp);
		ft_check_overlap(mstr, mstr->nodes_array[mstr->current_node], tmp);
		free_get_nodes(tmp);
		mstr->current_node++;
	}
}
