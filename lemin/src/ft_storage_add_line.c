/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage_add_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:46:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 19:28:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output_explained.h"
#include "error.h"

static void		ft_check_ants(t_master *mstr, t_line_info *entry, char *line)
{
	if (mstr->ants_nb_modified != CONFIRMED && entry->type != COMMENT)
	{
		ft_parser_ants_get(mstr, line, !mstr->ants_nb_modified);
		entry->type = ANTS;
		mstr->ants_nb_modified = CONFIRMED;
	}
}

t_ln_type		ft_storage_add_line(char *line, t_master *mstr)
{
	int				reduc_ind;
	t_line_info		*entry;
	int				index;

	index = mstr->lines_nb;
	reduc_ind = index % BATCH_MALLOC_SIZE;
	if (!reduc_ind && index)
		ft_storage_grow(mstr);
	entry = &(mstr->storage->entry[reduc_ind]);
	entry->type = ft_parser_line_type(line, mstr->piping);
	ft_check_ants(mstr, entry, line);
	if (entry->type == END_OF_READ)
		ft_exit(INVALID_LINE, mstr);
	entry->line = line;
	entry->line_index = mstr->lines_nb;
	ft_parser_fill_entry_node(mstr, line, entry);
	ft_parser_fill_entry_pipe(mstr, line, entry);
	ft_parser_apply_command(mstr, entry);
	mstr->lines_nb++;
	return (entry->type);
}
