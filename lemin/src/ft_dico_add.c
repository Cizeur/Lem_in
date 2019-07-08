/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_working_dico_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:28:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/08 16:36:36 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"


static t_bucket	ft_dico_check_double_inc(t_master *mstr,
				t_hash_dico *dico,t_line_info *entry)
{
	t_bucket *dico_entry;
	t_bucket *bucket;
	t_bucket *tmp;
	t_line_info *cmp_line;

	dico_entry = &(dico->dico_list[entry->hash_key]);
	bucket = dico_entry;
	while (bucket)
	{
		cmp_line = ft_storage_get_line(mstr->storage_start, bucket->line_index);
		if (entry->name_len == cmp_line->name_len &&
			!ft_strncmp(entry->line, cmp_line->line, cmp_line->name_len))
			ft_exit(FAIL_REPEAT_ENTRY);
		tmp = bucket;
		bucket = bucket->next;
	}
	if (!(bucket = (t_bucket *)ft_memalloc(sizeof(t_bucket))))
		ft_exit(FAIL_MALLOC_DIC);
	tmp->next = bucket;
	bucket->line_index = entry->line_index;
	return (*dico_entry);
}

int			ft_dico_add(t_master *mstr, t_hash_dico *dico,t_line_info *entry)
{
	t_bucket dico_entry;

	dico_entry = dico->dico_list[entry->hash_key];
	if (!dico_entry.line_index)
		dico_entry.line_index = entry->line_index;
	else
	{
		dico_entry = ft_dico_check_double_inc(mstr, dico, entry);
		dico->collisions++;
	}
	dico->dico_list[entry->hash_key] =  dico_entry;
	return(1);
	mstr= 0;
}
