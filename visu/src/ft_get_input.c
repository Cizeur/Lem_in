/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:34:01 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/08 17:23:30 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_check_parameters(t_master *mstr, char *line, int nb_line)
{
	if ((nb_line == 0 && mstr->nb_ants == 0)
	|| (ft_strstr(line, LINE_NODES) && mstr->nb_nodes == 0)
	|| (ft_strstr(line, LINE_PIPES) && mstr->nb_pipes == 0)
	|| (ft_strstr(line, LINE_MOVES) && mstr->nb_movements == 0)
	|| (nb_line > 4))
	{
		free(line);
		ft_exit(mstr, INVALID_INPUT);
	}
}

void	ft_get_parameters(t_master *mstr, char *line, int nb_line)
{
	if (nb_line == 0)
	{
		if (ft_str_isdigit(line) == FALSE)
		{
			free (line);
			ft_exit(mstr, INVALID_INPUT);
		}
		mstr->nb_ants = ft_atoi(line);
	}
	else if (ft_strstr(line, LINE_NODES))
		mstr->nb_nodes = ft_atoi(line + 31);
	else if (ft_strstr(line, LINE_PIPES))
		mstr->nb_pipes = ft_atoi(line + 31);
	else if (ft_strstr(line, LINE_MOVES))
		mstr->nb_movements = ft_atoi(line + 31);
	else if (ft_strstr(line, LINE_ACTIVE))
		mstr->nb_inactive = ft_atoi(line + 31);
	ft_check_parameters(mstr, line, nb_line);
}

void	ft_get_input(t_master *mstr, char *line)
{
	if (mstr->current_node < mstr->nb_nodes)
		ft_get_nodes(mstr, line);
	else if (mstr->current_pipe < mstr->nb_pipes)
		ft_get_pipes(mstr, line);
	else if (mstr->current_move <= mstr->nb_movements)
		ft_get_moves(mstr, line);
}
