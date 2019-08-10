/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cizeur <cizeur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:08:38 by cizeur            #+#    #+#             */
/*   Updated: 2019/08/10 21:09:11 by cizeur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "visu.h"
#include "libft/libft.h"

void	free_ants(t_master *mstr)
{
	int		i;

	i = 0;
	if (mstr->ants_array)
	{
		while (i < mstr->nb_ants)
		{
			free(mstr->ants_array[i]);
			i++;
		}
		free(mstr->ants_array);
	}
}

void	free_nodes(t_master *mstr)
{
	int		i;

	i = 0;
	if (mstr->nodes_array)
	{
		while (i < mstr->nb_nodes)
		{
			free(mstr->nodes_array[i]->pipes);
			free(mstr->nodes_array[i]->name);
			free(mstr->nodes_array[i]);
			i++;
		}
		free(mstr->nodes_array);
	}
}

void	free_pipes(t_master *mstr)
{
	int		i;

	i = 0;
	if (mstr->pipes_array)
	{
		while (i < mstr->nb_pipes)
		{
			free(mstr->pipes_array[i]->node1_name);
			free(mstr->pipes_array[i]->node2_name);
			free(mstr->pipes_array[i]);
			i++;
		}
		free(mstr->pipes_array);
	}
}

void	free_moves(t_master *mstr)
{
	int			i;
	t_moves		*current;
	t_moves		*next;

	i = 0;
	if (mstr->moves_array)
	{
		while (i < mstr->nb_movements + 1)
		{
			current = mstr->moves_array[i];
			while (current != NULL)
			{
				next = current->next;
				free(current);
				current = next;
			}
			i++;
		}
		free(mstr->moves_array);
	}
}

void	free_textures(t_master *mstr)
{
	int		i;

	i = 0;
	free_texture(mstr->background);
	free_texture(mstr->start);
	free_texture(mstr->finish);
	free_texture(mstr->node);
	if (mstr->textures)
	{
		while (i < 8)
		{
			free_texture(mstr->textures[i]);
			i++;
		}
		free(mstr->textures);
	}
}
