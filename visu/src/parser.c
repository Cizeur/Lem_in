/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:40:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/12 12:01:04 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/get_next_line.h"

void	parser(t_master *mstr)
{
	int			ret;
	char		*line;
	int			nb_line;

	nb_line = 0;
	while ((ret = get_next_line(0, &line)) > 0 && nb_line < 5) 
	{
		if (ret == -1)
			ft_exit(FAIL_ON_READ);
		ft_get_parameters(mstr, line, nb_line);
		nb_line++;
		line = NULL;
	}
	// ft_print_parameters(mstr);
	inizialization(mstr);
	ft_get_input(mstr, line, nb_line);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ret == -1)
			ft_exit(FAIL_ON_READ);
		ft_get_input(mstr, line, nb_line);
		nb_line++;
		line = NULL;
	}
}