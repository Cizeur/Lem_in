/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_working_dico_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:28:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/08 15:27:20 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"
/*
static int	ft_dico_check_double_inc(t_master *mstr,
				t_hash_dico *dico,t_line_info *entry)
{
	t_bucket dico_entry;
	t_bucket *bucket;

	dico_entry = dico->dico_list[entry->hash_key];
	bucket = dico_entry.next;
	if (ft_strncmp())

}
*/
int			ft_dico_add(t_master *mstr, t_hash_dico *dico,t_line_info *entry)
{
	t_bucket dico_entry;

	dico_entry = dico->dico_list[entry->hash_key];
	if (!dico_entry.line_index)
		dico_entry.line_index = entry->line_index;
//	else
//		ft_dico_check_double(mstr, dico, entry);
	dico->dico_list[entry->hash_key] =  dico_entry;
	return(1);
	mstr= 0;
}
