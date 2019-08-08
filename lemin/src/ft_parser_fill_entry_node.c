/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_fill_entry_node.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:08:15 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 18:57:18 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"
#include "error.h"

void		ft_parser_fill_entry_node(t_master *mstr, char *line,
						t_line_info *entry)
{
	char	*name_end;
	int		i;

	if (entry->type != NODE)
		return ;
	name_end = ft_find_name_end(line);
	i = -1;
	entry->name_len = (int)(name_end - line);
	while (++i < entry->name_len)
	{
		if (line[i] == '-')
			ft_exit(DASH_IN_NAME, mstr);
	}
	entry->hash_key = ft_dico_hasher_djb2(line, name_end, HASH_SIZE);
	entry->node_number = mstr->nodes;
	mstr->nodes++;
	ft_dico_add(mstr, mstr->dico, entry);
}
