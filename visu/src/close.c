/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:55:52 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 12:09:26 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

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
		while (i < mstr->nb_movements)
		{
			current = mstr->moves_array[i];
			next = mstr->moves_array[i]->next;
			while (next != NULL)
			{
				free(current);
				current = next;
				next = current->next;
			}
			i++;
		}
		free(mstr->moves_array);
	}
}

int		close_program(t_master *mstr)
{
	free_ants(mstr);
	free_nodes(mstr);
	free_pipes(mstr);
	free_moves(mstr);
	free_texture(mstr->background);
	free_texture(mstr->start);
	free_texture(mstr->finish);
	SDL_DestroyRenderer(mstr->render);
	mstr->render = NULL;
	SDL_DestroyWindow(mstr->window);
	mstr->window = NULL;
	IMG_Quit();
	SDL_Quit();
	free(mstr);
	mstr = NULL;
	return (FALSE);
}
