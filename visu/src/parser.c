/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:40:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/11 18:15:32 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

int			ft_comment_or_empty_1(char *line)
{
	if (ft_str_isdigit(line) == TRUE)
		return (TRUE);
	if (ft_strstr(line, LINE_NODES))
		return (TRUE);
	if (ft_strstr(line, LINE_PIPES))
		return (TRUE);
	if (ft_strstr(line, LINE_MOVES))
		return (TRUE);
	if (ft_strstr(line, LINE_ACTIVE))
		return (TRUE);
	return (FALSE);
}

int			ft_comment_or_empty_2(char *line)
{
	if (!line || !line[0])
		return (FALSE);
	if (ft_str_cmp(line, "##start") == TRUE)
		return (TRUE);
	if (ft_str_cmp(line, "##end") == TRUE)
		return (TRUE);
	if (ft_str_cmp(line, "#active") == TRUE)
		return (TRUE);
	if (ft_str_cmp(line, "#inactive") == TRUE)
		return (TRUE);
	if (line[0] == '#' || line[0] == '\n')
		return (FALSE);
	return (TRUE);
}

void		read_parameters(t_master *mstr)
{
	int			ret;
	char		*line;
	int			nb_line;
	int			started;

	nb_line = 0;
	started = FALSE;
	while (nb_line < 5 && (ret = get_next_line(0, &line)) > 0)
	{
		if (!started && line && *line == '#')
			started = TRUE;
		if (line && ft_comment_or_empty_1(line) == TRUE)
		{
			ft_get_parameters(mstr, line, nb_line);
			nb_line++;
		}
		if (line)
			free(line);
		line = NULL;
	}
	if (ret <= 0)
		ft_exit(mstr, FAIL_ON_READ);
}

void		read_nodes_pipes_moves(t_master *mstr)
{
	int			ret;
	char		*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line && ft_comment_or_empty_2(line) == TRUE)
			ft_get_input(mstr, line);
		if (line)
			free(line);
		line = NULL;
	}
	if (ret == FALSE)
		ft_exit(mstr, FAIL_ON_READ);
}

void		parser(t_master *mstr)
{
	mstr->nb_ants = FALSE;
	mstr->nb_nodes = FALSE;
	mstr->nb_pipes = FALSE;
	mstr->nb_movements = FALSE;
	mstr->nb_inactive = FALSE;
	read_parameters(mstr);
	check_parameters(mstr);
	inizialization(mstr);
	read_nodes_pipes_moves(mstr);
	check_nodes_pipes_moves(mstr);
}
