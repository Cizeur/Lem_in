/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dico_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:28:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/08 17:03:07 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"


int			ft_dico_get(t_storage *storage_start, t_hash_dico *dico, char *needle, int len)
{
	t_bucket 	*dico_entry;
	t_line_info *cmp_line;
	int			hash;

	printf("%s\n", needle);
	hash = ft_dico_hasher_djb2(needle, needle + len, HASH_SIZE);
	dico_entry = &(dico->dico_list[hash]);
	if (!(dico_entry->line_index))
		return(-1);
	while (dico_entry)
	{
		cmp_line = ft_storage_get_line(storage_start, dico_entry->line_index);
		if (len == cmp_line->name_len &&
			!ft_strncmp(needle, cmp_line->line, cmp_line->name_len))
			return (cmp_line->line_index);
		dico_entry = dico_entry->next;
	}
	return(-1);
}
