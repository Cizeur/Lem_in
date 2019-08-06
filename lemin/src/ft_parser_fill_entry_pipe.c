/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_fill_entry_pipe.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:08:15 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/06 15:40:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"
#include "libft/libft.h"

void	ft_parser_fill_entry_pipe(t_master *mstr, char *line,
			t_line_info *entry)
{
	int			dash_pos;
	char		*dash;

	if (entry->type != PIPE)
		return ;
	dash = ft_strchr(line, '-');
	dash_pos = (int)(dash - line);
	if ((entry->pipe[0] = ft_dico_get(mstr, mstr->dico, line, dash_pos)) != -1)
	{
		dash++;
		if ((entry->pipe[1] = ft_dico_get(mstr, mstr->dico,
										dash, ft_strlen(dash))) != -1)
		{
			entry->pipe[0] =
				ft_storage_get_line(mstr, entry->pipe[0])->node_number;
			entry->pipe[1] =
				ft_storage_get_line(mstr, entry->pipe[1])->node_number;
			mstr->pipes++;
			return ;
		}
	}
	entry->type = END_OF_READ;
}
