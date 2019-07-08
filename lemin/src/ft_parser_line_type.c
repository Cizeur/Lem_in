/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_line_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:03:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/02 17:03:38 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lem_in.h"
#include "utils.h"

static t_ln_type	ft_is_hashtag(t_master *mstr, char *line)
{

		mstr = 0;

	if (*line != '#')
		return(ERROR);
	if (!ft_strcmp(line, START_MK))
		return(START);
	else if (!ft_strcmp(line, END_MK))
		return(END);
	else
		return(COMMENT);
}

t_ln_type	ft_parser_line_type(t_master *mstr, char *line, int piping)
{
	t_ln_type type;

	if (*line == 0)
		return (ERROR);
	type = ft_is_hashtag(mstr, line);
	if (piping == NOPE)
		type = ft_parser_check_cell(mstr, line, type);
	return(type);
}
