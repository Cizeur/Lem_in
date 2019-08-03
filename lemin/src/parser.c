/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:35:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/03 14:45:26 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "lem_in.h"

void		parser(t_master *mstr)
{
	char		*line;
	int			r;
	t_ln_type	line_type;

	line = ft_parser_ants_get(mstr);
	mstr->storage_start = mstr->storage;
	line_type = ft_storage_add_line(line, mstr);
	line = NULL;
	while ((r = get_next_line(0, &line)) > 0
			&& line_type != END_OF_READ)
	{
		line_type = ft_storage_add_line(line, mstr);
		line = NULL;
	}
	if (r == -1)
		ft_exit(FAIL_ON_READ);
	if (!mstr->start || !mstr->end)
		ft_exit(START_OR_END_MISSING);
	ft_matrix_generate(mstr, mstr->storage_start);
}
