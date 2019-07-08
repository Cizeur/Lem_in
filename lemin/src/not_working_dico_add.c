/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dico_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:28:35 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/03 15:06:50 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"

t_hash_index	*ft_new_hash_entry(char *pos[4], int key, int cell_index)
{
	t_hash_index *new_hash;

	new_hash = NULL;
	new_hash = (t_hash_index *)ft_memalloc(sizeof(t_hash_index));
	if (!new_hash)
		ft_exit(FAILED_DICO_ENTRY_CREATION);
	new_hash->key = key;
	new_hash->cell_index = cell_index;
	new_hash->name = pos[POS_LINE];
	new_hash->name_start = pos[POS_START];
	new_hash->name_len = (int)(pos[POS_X] - pos[POS_START]);
	new_hash->next = NULL;
	return (new_hash);
}

t_hash_index	*ft_check_double(t_hash_index *cur, char *pos[4], int key, int cell_index)
{
	t_hash_index *start;
	t_hash_index *tmp;

	start = cur;
	while (cur)
	{
		//printf("[[%-3.*s]]", cur->name_len,  cur->name_start);
		if (pos[POS_X] - pos[POS_START] == cur->name_len &&
			!ft_memcmp(cur->name_start, pos[POS_START], cur->name_len))
			return(NULL);
		tmp = cur;
		cur = cur->next;
	}
	tmp->next = ft_new_hash_entry(pos, key, cell_index);
	return(start);
	key = 0;
}

int			ft_dico_add(t_hash_dico *dico, char *pos[4])
{
	int hash_key;
	t_hash_index **current_index;

	hash_key = ft_dico_hasher_djb2(pos[POS_START], pos[POS_X], HASH_SIZE);
	current_index = &dico->dico_list[hash_key];
	if (*current_index == NULL)
		*current_index = ft_new_hash_entry(pos, dico->current_key, dico->cell_nb);
	else
	{
		*current_index = ft_check_double(*current_index, pos,
							dico->current_key, dico->cell_nb);
		if(!*current_index)
			return(0);
		dico->collisions++;
	}
	dico->cell_nb++;
	dico->current_key++;
	return (1);
}
