/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:34:01 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/11 17:57:36 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/libft.h"

void	ft_check_parameters(t_master *mstr, char *line, int nb_line)
{
	if ((nb_line == 0 && mstr->nb_ants < TRUE)
	|| (ft_strstr(line, LINE_NODES) && mstr->nb_nodes < TRUE)
	|| (ft_strstr(line, LINE_PIPES) && mstr->nb_pipes < TRUE)
	|| (ft_strstr(line, LINE_MOVES) && mstr->nb_movements < TRUE)
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
			free(line);
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

int		format_input(char *line)
{
	if (ft_strstr(line, "-") && ft_strstr(line, "L"))
		return (MOVE);
	else if (ft_strchr(line, '-') != NULL
	|| (ft_str_cmp(line, COMMENT_ACTIVE) == TRUE)
	|| (ft_str_cmp(line, COMMENT_INACTIVE) == TRUE))
		return (PIPE);
	else if (ft_strchr(line, ' ') != NULL
	|| (ft_str_cmp(line, COMMENT_START) == TRUE)
	|| (ft_str_cmp(line, COMMENT_END) == TRUE))
		return (NODE);
	else
		return (FALSE);
}

void	ft_get_input(t_master *mstr, char *line)
{
	int		format_line;

	if ((format_line = format_input(line)) != FALSE)
	{
		if (format_line == NODE
		&& mstr->current_node < mstr->nb_nodes)
			ft_get_nodes(mstr, line);
		else if (format_line == PIPE
		&& mstr->current_pipe < mstr->nb_pipes)
			ft_get_pipes(mstr, line);
		else if (format_line == MOVE
		&& mstr->current_move <= mstr->nb_movements)
			ft_get_moves(mstr, line);
		else
			ft_exit(mstr, INVALID_INPUT);
	}
}
