/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:13:50 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 17:20:10 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

char	*trim(char *move)
{
	char	**strsplit;
	char	*trim;

	strsplit = ft_strsplit(move, ' ');
	trim = ft_strdup(strsplit[0]);
	free(strsplit[0]);
	free(strsplit[1]);
	free(strsplit);
	return (trim);
}

void	free_get_moves(char *tmp, char **strsplit)
{
	int		i;

	i = 0;
	if (strsplit)
	{
		while (strsplit[i])
		{
			free(strsplit[i]);
			i++;
		}
		free(strsplit);
	}
	if (tmp)
		free(tmp);
}

int		ft_fill_movements(t_master *mstr, char *move, int index)
{
	char	*tmp;
	char	**strsplit;
	int		ant_index;
	int		node_index;

	tmp = trim(move);
	strsplit = ft_strsplit(tmp, '-');
	ant_index = ft_atoi(strsplit[0]) - 1;
	if ((node_index = ft_get_index_node(mstr, strsplit[1])) == FALSE)
	{
		free_get_moves(tmp, strsplit);
		return (ft_exit(mstr, INVALID_NAME));
	}
	mstr->moves_array[mstr->current_move]->current_index = index;
	mstr->moves_array[mstr->current_move]->ant_index = ant_index;
	if (mstr->ants_array[ant_index]->current_node == FALSE)
		mstr->moves_array[mstr->current_move]->node1_index = mstr->start_index;
	else
		mstr->moves_array[mstr->current_move]->node1_index =
		mstr->ants_array[ant_index]->current_node;
	mstr->moves_array[mstr->current_move]->node2_index = node_index;
	mstr->ants_array[ant_index]->current_move = mstr->current_move;
	mstr->ants_array[ant_index]->current_node = node_index;
	free_get_moves(tmp, strsplit);
	return (TRUE);
}

int		ft_new_movement(t_master *mstr)
{
	int			move_index;
	t_moves		*current;

	move_index = mstr->current_move;
	if (!(current = (t_moves*)ft_memalloc(sizeof(t_moves))))
		return (ft_exit(mstr, ERROR_MALLOC));
	if (!mstr->moves_array[move_index])
		current->next = NULL;
	else
		current->next = mstr->moves_array[move_index];
	current->move_index = mstr->current_move;
	mstr->moves_array[move_index] = current;
	return (TRUE);
}

void	free_moves_ants(char **moves_ants)
{
	int		i;

	i = 0;
	if (moves_ants)
	{
		while (moves_ants[i])
		{
			free(moves_ants[i]);
			i++;
		}
		free(moves_ants);
	}
}

int		ft_get_moves(t_master *mstr, char *line)
{
	int		i;
	char	**moves_ants;
	int		problem;

	i = 0;
	moves_ants = ft_strsplit(line, 'L');
	problem = FALSE;
	if (moves_ants && moves_ants[i])
	{
		while (problem == FALSE && moves_ants[i])
		{
			if (ft_new_movement(mstr) == FALSE
			|| ft_fill_movements(mstr, moves_ants[i], i) == FALSE)
				problem = TRUE;
			i++;
		}
		mstr->current_move++;
	}
	free_moves_ants(moves_ants);
	return (TRUE);
}
