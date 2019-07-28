/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:13:50 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 13:36:45 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

char	*trim(char *move)
{
	char	**strsplit;
	char	*trim;

	strsplit = ft_strsplit(move, ' ');
	trim = strsplit[0];
	free(strsplit[1]);
	free(strsplit);
	return (trim);
}

void	free_get_moves(char *tmp, char **strsplit)
{
	free(tmp);
	free(strsplit[0]);
	free(strsplit[1]);
	free(strsplit);
}

void	ft_fill_movements(t_master *mstr, char *move, int index)
{
	char	*tmp;
	char	**strsplit;
	int		ant_index;
	int		node_index;

	tmp = trim(move);
	strsplit = ft_strsplit(tmp, '-');
	ant_index = ft_atoi(strsplit[0]) - 1;
	node_index = ft_get_index_node(mstr, strsplit[1]);
	mstr->moves_array[mstr->current_move]->current_index = index;
	mstr->moves_array[mstr->current_move]->ant_index = ant_index;
	if (mstr->ants_array[ant_index]->current_node == FALSE)
		mstr->moves_array[mstr->current_move]->node1_index = mstr->start_index;
	else
		mstr->moves_array[mstr->current_move]->node1_index = mstr->ants_array[ant_index]->current_node;
	mstr->moves_array[mstr->current_move]->node2_index = node_index;
	mstr->ants_array[ant_index]->current_move = mstr->current_move;
	mstr->ants_array[ant_index]->current_node = node_index;
	free_get_moves(tmp, strsplit);
}

int		ft_new_movement(t_master *mstr)
{
	int			move_index;
	t_moves		*current;

	move_index = mstr->current_move;
	if (!(current = (t_moves*)ft_memalloc(sizeof(t_moves))))
		return (ERROR_MALLOC);
	if (!mstr->moves_array[move_index])
		current->next = NULL;
	else
		current->next = mstr->moves_array[move_index];
	current->move_index = mstr->current_move;
	mstr->moves_array[move_index] = current;
	return (TRUE);
}

void	ft_get_moves(t_master *mstr, char *line)
{
	int		i;
	char	**moves_ants;

	i = 0;
	moves_ants = ft_strsplit(line, 'L');
	if (moves_ants[i])
	{
		while (moves_ants[i])
		{
			ft_new_movement(mstr);
			ft_fill_movements(mstr, moves_ants[i], i);
			free(moves_ants[i]);
			// printf("mstr->current_move = %d\n", mstr->current_move);
			// printf("mstr->moves_array[]->current_index = %d\n", mstr->moves_array[mstr->current_move]->current_index);
			// printf("mstr->moves_array[]->ant_index = %d\n", mstr->moves_array[mstr->current_move]->ant_index);
			// printf("mstr->moves_array[]->node1_index = %d\n", mstr->moves_array[mstr->current_move]->node1_index);
			// printf("mstr->moves_array[]->node2_index = %d\n", mstr->moves_array[mstr->current_move]->node2_index);
			i++;
		}
		free(moves_ants);
		mstr->current_move++;
	}
}
