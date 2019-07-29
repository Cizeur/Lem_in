/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:12:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 12:59:24 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_is_not_comment_2(t_master *mstr, char *line)
{
	if (line[0] == '#')
	{
        mstr->pipes_array[mstr->current_pipe]->active = PIPE_INACTIVE;
      	return (0);
    }
    return (1);
}

void    free_get_pipes(char **tmp)
{
    free(tmp[0]);
    free(tmp[1]);
    free(tmp);
}

int 	ft_get_pipes(t_master *mstr, char *line)
{
    char    **tmp;
    int     index1;
    int     index2;
  
    if (ft_is_not_comment_2(mstr, line) == 1)
    {
        mstr->pipes_array[mstr->current_pipe]->pipe_index = mstr->current_pipe;
        tmp = ft_strsplit(line, '-');
        mstr->pipes_array[mstr->current_pipe]->node1_name = ft_strdup(tmp[0]);
        mstr->pipes_array[mstr->current_pipe]->node2_name = ft_strdup(tmp[1]);
        if ((index1 = ft_get_index_node(mstr, tmp[0])) == FALSE
        || (index2 = ft_get_index_node(mstr, tmp[1])) == FALSE)
            return (FALSE);
        mstr->pipes_array[mstr->current_pipe]->node1_index = index1;
        mstr->pipes_array[mstr->current_pipe]->node2_index = index2;
        mstr->nodes_array[index1]->pipes[mstr->nodes_array[index1]->nb_pipes] = index2;
        mstr->nodes_array[index1]->nb_pipes++;
        mstr->nodes_array[index2]->pipes[mstr->nodes_array[index2]->nb_pipes] = index1;
        mstr->nodes_array[index2]->nb_pipes++;
        mstr->current_pipe++;
        free_get_pipes(tmp);
    }
    return (TRUE);
}