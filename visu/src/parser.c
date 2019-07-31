/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:40:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 15:11:31 by crfernan         ###   ########.fr       */
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
	if (ft_str_cmp(line, "#inactive") == TRUE)
		return (TRUE);
	return (FALSE);
}

int		read_parameters(t_master *mstr)
{
	int			ret;
	char		*line;
	int			nb_line;
	int			problem;

	nb_line = 0;
	problem = FALSE;
	while (problem == FALSE && nb_line < 5
	&& (ret = get_next_line(0, &line)) > 0)
	{
		if (ret == FALSE)
			return (ft_exit(mstr, FAIL_ON_READ));
		if (ft_get_parameters(mstr, line, nb_line) == FALSE)
			problem = TRUE;
		nb_line++;
		free(line);
		line = NULL;
	}
	if (problem == TRUE || inizialization(mstr) == FALSE)
		return (FALSE);
	if (ret != TRUE)
		return (ft_exit(mstr, FAIL_ON_READ));
	return (nb_line);
}

int		read_nodes_pipes_moves(t_master *mstr, int nb_line)
{
	int			ret;
	char		*line;
	int			problem;

	problem = FALSE;
	while (problem == FALSE && (ret = get_next_line(0, &line)) > 0)
	{
		if (ret == -1)
			return (ft_exit(mstr, FAIL_ON_READ));
		if (ft_comment_or_empty(line) == TRUE)
		{
			if (ft_get_input(mstr, line) == FALSE)
				problem = TRUE;
		}
		free(line);
		line = NULL;
		nb_line++;
	}
	if (problem == TRUE)
		return (FALSE);
	check_inactive_nodes(mstr);
	return (TRUE);
}

int		parser(t_master *mstr)
{
	int			nb_line;

	if ((nb_line = read_parameters(mstr)) == FALSE)
		return (FALSE);
	if (read_nodes_pipes_moves(mstr, nb_line) == FALSE)
		return (FALSE);
	return (TRUE);
}
