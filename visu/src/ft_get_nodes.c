/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:14:30 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/11 18:53:12 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_is_not_comment(t_master *mstr, char *line)
{
	// printf("LINE = \"%s\" || mstr->nb_nodes = %d\n", line, mstr->nb_nodes);
	if (line[0] != '#')
		return (1);
	else if (ft_strstr(line, "##start"))
		mstr->end_index = mstr->nb_nodes;
	else if (ft_strstr(line, "##end"))
		mstr->end_index = mstr->nb_nodes;
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
	t_nodes		*node;

	ft_putnbr(mstr->nb_nodes);
	node = mstr->nodes_array[mstr->nb_nodes];
	ft_putendl("WHAT");
	if (ft_is_not_comment(mstr, line) == 1)
	{
		printf("\nLINE = \"%s\" || mstr->nb_nodes = %d\n", line, mstr->nb_nodes);
		node->node_index = mstr->nb_nodes;
		ft_putendl("calling ft_strsplit");
		tmp = ft_strsplit(line, ' ');
		ft_putendl("calling ft_strdup");
		mstr->nodes_array[mstr->nb_nodes]->name = ft_strdup(tmp[0]);
		ft_putendl("calling ft_strlen");
		mstr->nodes_array[mstr->nb_nodes]->len_name = ft_strlen(tmp[0]);
		ft_putendl("calling ft_atoi");
		mstr->nodes_array[mstr->nb_nodes]->x = ft_atoi(tmp[1]);
		ft_putendl("calling ft_atoi");
		mstr->nodes_array[mstr->nb_nodes]->y = ft_atoi(tmp[2]);
		mstr->nodes_array[mstr->nb_nodes]->nb_pipes = 0;
		// ft_free_tmp(tmp);
		mstr->nb_nodes++;
	}
}