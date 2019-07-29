/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:40:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 19:13:54 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/get_next_line.h"

int		parser(t_master *mstr)
{
	int			ret;
	char		*line;
	int			nb_line;
	int			problem;

	nb_line = 0;
	problem = FALSE;
	while (problem == FALSE && nb_line < 5 && (ret = get_next_line(0, &line)) > 0)
	{
		if (ret == FALSE)
			return(ft_exit(mstr, FAIL_ON_READ));
		if (ft_get_parameters(mstr, line, nb_line) == FALSE)
			problem = TRUE;
		nb_line++;
		line = NULL;
	}
	if (problem == TRUE || inizialization(mstr) == FALSE)
		return (FALSE);
	if (ret != TRUE)
		return(ft_exit(mstr, FAIL_ON_READ));
	while (problem == FALSE && (ret = get_next_line(0, &line)) > 0)
	{
		if (ret == -1)
			return (ft_exit(mstr, FAIL_ON_READ));
		if (ft_get_input(mstr, line) == FALSE)
			problem = TRUE;
		line = NULL;
		nb_line++;
	}
	if (problem == TRUE)
		return (FALSE);
	return (TRUE);
}