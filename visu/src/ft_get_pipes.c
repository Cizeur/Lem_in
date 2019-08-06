/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:12:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 20:04:07 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_is_not_comment_2(t_master *mstr, char *line)
{

	if (ft_strstr(line, "#active"))
	{
		mstr->pipes_array[mstr->current_pipe]->active = PIPE_ACTIVE;
		return (FALSE);
	}
	if (ft_strstr(line, "#inactive"))
	{
		mstr->pipes_array[mstr->current_pipe]->active = PIPE_INACTIVE;
		return (FALSE);
	}
	if (line[0] == '#')
		return (FALSE);
	return (TRUE);
}

void	free_get_pipes(char **tmp)
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

void	ft_get_pipes(t_master *mstr, char *line)
{
	char	**tmp;
	int		i1;
	int		i2;

	if (ft_is_not_comment_2(mstr, line) == TRUE)
	{
		mstr->pipes_array[mstr->current_pipe]->pipe_index = mstr->current_pipe;
		tmp = ft_strsplit(line, '-');
		mstr->pipes_array[mstr->current_pipe]->node1_name = ft_strdup(tmp[0]);
		mstr->pipes_array[mstr->current_pipe]->node2_name = ft_strdup(tmp[1]);
		i1 = ft_get_index_node(mstr, tmp[0]);
		i2 = ft_get_index_node(mstr, tmp[1]);
		mstr->pipes_array[mstr->current_pipe]->node1_index = i1;
		mstr->pipes_array[mstr->current_pipe]->node2_index = i2;
		if (mstr->pipes_array[mstr->current_pipe]->active == PIPE_ACTIVE)
		{
			mstr->nodes_array[i1]->pipes[mstr->nodes_array[i1]->nb_pipes]
			= mstr->current_pipe;
			mstr->nodes_array[i1]->nb_pipes++;
			mstr->nodes_array[i2]->pipes[mstr->nodes_array[i2]->nb_pipes]
			= mstr->current_pipe;
			mstr->nodes_array[i2]->nb_pipes++;
		}
		free_get_pipes(tmp);
		mstr->current_pipe++;
	}
}
