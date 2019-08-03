/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage_add_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 13:46:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/31 11:37:38 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ln_type 	ft_storage_add_line(char *line, t_master *mstr)
{
	int 			reduc_ind;
	t_line_info		*entry;
	int				index;

	index = mstr->lines_nb;
	reduc_ind = index % BATCH_MALLOC_SIZE;
	if (!reduc_ind && index)
		ft_storage_grow(mstr);
	entry = &(mstr->storage->entry[reduc_ind]);
	entry->type = !mstr->lines_nb ? ANTS_NB :
		ft_parser_line_type(line, mstr->piping);
	if (entry->type == END_OF_READ)
		return (END_OF_READ);
	mstr->piping = entry->type == PIPE ? CERTAINLY : mstr->piping;
	entry->line = line;
	entry->line_index = mstr->lines_nb;
	ft_parser_fill_entry_node(mstr, line, entry);
	ft_parser_fill_entry_pipe(mstr, line, entry);
	ft_parser_apply_command(mstr, entry);
	mstr->lines_nb++;
	return (entry->type);
}
