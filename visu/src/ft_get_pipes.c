/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:12:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/11 17:56:57 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/libft.h"

int		ft_is_not_comment(t_master *mstr, char *line)
{
	if (ft_strstr(line, "#active"))
		mstr->pipes_array[mstr->current_pipe]->active = PIPE_ACTIVE;
	else if (ft_strstr(line, "#inactive"))
		mstr->pipes_array[mstr->current_pipe]->active = PIPE_INACTIVE;
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
			tmp[i] = NULL;
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
}

void	ft_check_pipe_activation(t_master *mstr, int i1, int i2)
{
	if (mstr->pipes_array[mstr->current_pipe]->active == PIPE_ACTIVE)
	{
		mstr->nodes_array[i1]->pipes[mstr->nodes_array[i1]->nb_pipes] =
			mstr->current_pipe;
		mstr->nodes_array[i1]->nb_pipes++;
		mstr->nodes_array[i2]->pipes[mstr->nodes_array[i2]->nb_pipes] =
			mstr->current_pipe;
		mstr->nodes_array[i2]->nb_pipes++;
	}
	if (mstr->pipes_array[mstr->current_pipe]->active == PIPE_UNDEFINED)
		ft_exit(mstr, INVALID_INPUT);
}

void	ft_get_pipes(t_master *mstr, char *line)
{
	char	**tmp;
	int		i1;
	int		i2;

	i1 = FALSE;
	i2 = FALSE;
	if (ft_is_not_comment(mstr, line) == TRUE)
	{
		mstr->pipes_array[mstr->current_pipe]->pipe_index = mstr->current_pipe;
		tmp = ft_strsplit(line, '-');
		mstr->pipes_array[mstr->current_pipe]->node1_name = ft_strdup(tmp[0]);
		mstr->pipes_array[mstr->current_pipe]->node2_name = ft_strdup(tmp[1]);
		i1 = ft_get_index_node(mstr, tmp[0]);
		i2 = ft_get_index_node(mstr, tmp[1]);
		free_get_pipes(tmp);
		if (i1 == FALSE || i2 == FALSE)
			ft_exit(mstr, INVALID_NAME);
		mstr->pipes_array[mstr->current_pipe]->node1_index = i1;
		mstr->pipes_array[mstr->current_pipe]->node2_index = i2;
		ft_check_pipe_activation(mstr, i1, i2);
		mstr->current_pipe++;
	}
}
