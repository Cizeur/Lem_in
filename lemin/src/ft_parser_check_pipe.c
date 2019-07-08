/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:59:16 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/08 13:41:10 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

t_ln_type		ft_parser_check_pipe(char *line, t_ln_type type)
{
	int		i;
	int		pipe;
	int		check_first_name;
	int		check_second_name;

	i = 0;
	pipe = 0;
	check_first_name = 0;
	check_second_name = 0;
	while (line[i] && (!ft_is_whitespace(line[i]) || line[i] == '-') && pipe < 2)
	{
		if (!ft_is_whitespace(line[i]) && pipe == 0)
			check_first_name++;
		if (line[i] == '-')
			pipe++;
		if (!ft_is_whitespace(line[i]) && pipe == 1)
			check_second_name++;
		i++;
	}
	if (!(line[i]) && pipe == 1 && check_first_name && check_second_name)
		type = PIPE;
	return (type);
}
