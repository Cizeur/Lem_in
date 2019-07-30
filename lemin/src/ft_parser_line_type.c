/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_line_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 17:03:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/30 15:28:51 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lem_in.h"
#include "utils.h"

static t_ln_type	ft_is_hashtag(char *line)
{
	if (*line != '#')
		return(END_OF_READ);
	if (!ft_strcmp(line, START_MK))
		return(START);
	else if (!ft_strcmp(line, END_MK))
		return(END);
	else
		return(COMMENT);
}

t_ln_type	ft_parser_line_type(char *line, int piping)
{
	t_ln_type type;

	type = END_OF_READ;
	if (*line == 0 || *line == 'L' || ft_is_whitespace(*line))
		return (END_OF_READ);
	if ((type = ft_is_hashtag(line))!= END_OF_READ)
		return (type);
	else if (piping == NOPE && !ft_strchr(line, '-'))
		type = ft_parser_check_node(line, type);
	else
		type = ft_parser_check_pipe(line, type);
	return (type);
}
