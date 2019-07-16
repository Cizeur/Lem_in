/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:12:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/16 17:03:32 by crfernan         ###   ########.fr       */
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

int     ft_str_cmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1[i] == '\0' && s2[i] == '\0')
        return (1);
    return (0);
}

int     ft_get_index_node(t_master *mstr, char *name)
{
    int     i;

    i = 0;
    while (i < mstr->nb_nodes)
    {
        if (ft_str_cmp(mstr->nodes_array[i]->name, name))
            return (i);
        i++;
    }
    return (ft_exit(INVALID_NAME));
}

void    ft_free_tmp_2(char **tmp)
{
    free(tmp[0]);
    free(tmp[1]);
    free(tmp);
}

void	ft_get_pipes(t_master *mstr, char *line)
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
        index1 = ft_get_index_node(mstr, tmp[0]);
        mstr->pipes_array[mstr->current_pipe]->node1_index = index1;
        index2 = ft_get_index_node(mstr, tmp[1]);
        mstr->pipes_array[mstr->current_pipe]->node2_index = index2;
        mstr->nodes_array[index1]->pipes[mstr->nodes_array[index1]->nb_pipes] = index2;
        mstr->nodes_array[index1]->nb_pipes++;
        mstr->nodes_array[index2]->pipes[mstr->nodes_array[index2]->nb_pipes] = index1;
        mstr->nodes_array[index2]->nb_pipes++;
        mstr->current_pipe++;
        ft_free_tmp_2(tmp);
    }
}