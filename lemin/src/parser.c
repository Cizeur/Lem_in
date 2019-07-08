/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:35:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/08 16:26:45 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "lem_in.h"

void 		ft_storage_print(t_storage *storage, int ind_max)
{
	int 			ind;
	int 			reduc_ind;
	t_line_info		*entry;
	int				pos;
	int				length;

	ind = -1;
	pos = 0;
	while(++ind < ind_max)
	{
		reduc_ind = ind % BATCH_MALLOC_SIZE;
		if (!reduc_ind && ind)
			storage = storage->next;
		entry = &(storage->entry[reduc_ind]);
		length = ft_strlen(entry->line);
		//ft_putstr(entry->line);
		//ft_putchar('\n');
	//	printf("||%s||- type %d - index %d ",
	//	entry->line, entry->type, entry->line_index);
	//	if (entry->type == NODE)
	//		printf("node_nb %d - name [[%.*s]] -hash %d",
	//			entry->node_number ,entry->name_len
	//			,entry->line, entry->hash_key);
	//	printf("\n");
	}
}


void		parser(t_master *mstr)
{
	char		*line;
	int			r;
	t_ln_type	line_type;

	line = ft_parser_ants_get(mstr);
	mstr->storage_start = mstr->storage;
	line_type = ft_storage_add_line(line, mstr);
	line = NULL;
	while ((r = get_next_line(0, &line)) > 0
			&& line_type != END_OF_READ)
	{
		line_type = ft_storage_add_line(line, mstr);
		line = NULL;
	}
	if (r == -1)
		ft_exit(FAIL_ON_READ);
	ft_storage_print(mstr->storage_start, mstr->lines_nb);
	printf("collisions : %d\n", mstr->dico->collisions);
}
