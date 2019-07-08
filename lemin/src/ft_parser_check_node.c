/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_check_cell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:18:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/03 09:18:07 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"
#include "utils.h"

char	*ft_check_numbers(char *line, int *i_adr)
{
	char	*pos;
	int		i;

	i = *i_adr;
	pos = 0;
	while (i >= 0 && ft_is_whitespace(line[i]))
		--i;
	if (i < 0 || !ft_isdigit(line[i]))
		return (0);
	while (i >= 0 && ft_isdigit(line[i]))
		--i;
	if (line[i] == '-')
		--i;
	if (i < 0 || !ft_is_whitespace(line[i]))
		return (0);
	while (i >= 0 && ft_is_whitespace(line[i]))
		--i;
	if (i < 0)
		return (0);
	pos = &(line[i + 1]);
	*i_adr = i;
	return (pos);
}

t_ln_type		ft_parser_check_cell(char *line, t_ln_type type)
{
	int i;
	char *pos[4];

	ft_bzero(pos, sizeof(pos));
	i = ft_strlen(line) - 1;
	pos[POS_LINE] = line;
	pos[POS_START] = ft_find_name_start(pos[POS_LINE]);
	if ((pos[POS_Y] = ft_check_numbers(line, &i)))
	{
		if ((pos[POS_X] = ft_check_numbers(line, &i)))
			type = CELL;
	}
	return(type);
}


