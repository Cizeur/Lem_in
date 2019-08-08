/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:35:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 19:29:25 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "lem_in.h"
#include "output_explained.h"
#include "error.h"

void		parser(t_master *mstr)
{
	char		*line;
	int			r;
	t_ln_type	line_type;

	line_type = COMMENT;
	mstr->storage_start = mstr->storage;
	while ((r = get_next_line(0, &line)) > 0)
	{
		line_type = ft_storage_add_line(line, mstr);
		line = 0;
		mstr->piping = line_type == PIPE ? CERTAINLY : mstr->piping;
		if (line_type == END_OF_READ)
			ft_exit(INVALID_LINE, mstr);
		if ((!mstr->start || !mstr->end) && mstr->piping)
			ft_exit(START_OR_END_MISSING, mstr);
	}
	if (r == -1)
		ft_exit(FAIL_ON_READ, mstr);
	ft_output_explained(mstr, OC_PIPES_OK);
	ft_matrix_generate(mstr, mstr->storage_start);
	ft_output_explained(mstr, OC_MALLOC_MATRIX);
}
