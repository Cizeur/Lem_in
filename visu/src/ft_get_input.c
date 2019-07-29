/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:34:01 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 13:33:28 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_get_parameters(t_master *mstr, char *line, int nb_line)
{
	if (nb_line == 0)
		mstr->nb_ants = ft_atoi(line);
	else if (nb_line == 1)
		mstr->nb_nodes = ft_atoi(line + 31);
	else if (nb_line == 2)
		mstr->nb_pipes = ft_atoi(line + 31);
	else if (nb_line == 3)
		mstr->nb_inactive = ft_atoi(line + 31);
	else if (nb_line == 4)
		mstr->nb_movements = ft_atoi(line + 31);
	if (!mstr->nb_ants || !mstr->nb_nodes
	|| !mstr->nb_pipes || !mstr->nb_movements)
		return (ft_exit(INVALID_INPUT));
	return (TRUE);
}

int		ft_get_input(t_master *mstr, char *line)
{
	if (mstr->current_node < mstr->nb_nodes)
		return (ft_get_nodes(mstr, line));
	else if (mstr->current_pipe < mstr->nb_pipes)
		return (ft_get_pipes(mstr, line));
	else if (mstr->current_move <= mstr->nb_movements)
		return (ft_get_moves(mstr, line));
	return (FALSE);
}
