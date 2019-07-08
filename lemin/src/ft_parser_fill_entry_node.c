/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_fill_entry_node.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:08:15 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/08 13:59:15 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

void		ft_parser_fill_entry_node(t_master *mstr, char *line,
						t_line_info *entry, t_hash_dico *dico)
{
	char *name_end;

	if (entry->type != NODE)
		return;
	name_end = ft_find_name_end(line);
	dico = 0;
	entry->name_len = (int)(name_end - line);
	entry->hash_key = ft_dico_hasher_djb2(line, name_end, HASH_SIZE);
	entry->node_number = mstr->nodes_nb;
	mstr->nodes_nb++;
}
