/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:40:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/07 09:45:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/get_next_line.h"

int		ft_comment_or_empty(char *line)
{
	if (line[0] != '#' && line[0] != '\n')
		return (TRUE);
	if (ft_str_cmp(line, "##start") == TRUE)
		return (TRUE);
	if (ft_str_cmp(line, "##end") == TRUE)
		return (TRUE);
	if (ft_str_cmp(line, "#active") == TRUE)
		return (TRUE);
	if (ft_str_cmp(line, "#inactive") == TRUE)
		return (TRUE);
	return (FALSE);
}

/*
***	comments before or in between number of ants
*/

void		read_parameters(t_master *mstr)
{
	int			ret;
	char		*line;
	int			nb_line;

	nb_line = 0;
	while (nb_line < 5 && (ret = get_next_line(0, &line)) > 0)
	{
		ft_get_parameters(mstr, line, nb_line);
		nb_line++;
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
	int			nb_line;

	nb_line = 5;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_comment_or_empty(line) == TRUE)
			ft_get_input(mstr, line);
		free(line);
		line = NULL;
		nb_line++;
	}
	if (ret == FALSE)
		ft_exit(mstr, FAIL_ON_READ);
}

void		parser(t_master *mstr)
{
	read_parameters(mstr);
	inizialization(mstr);
	read_nodes_pipes_moves(mstr);
	check_inactive_nodes(mstr);
}
