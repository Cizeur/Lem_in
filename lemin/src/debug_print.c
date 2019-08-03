/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:53:44 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/02 16:16:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    ft_print_matrix(t_master *mstr, int activation)
{
	int     i;
	int		j;

	if (!activation)
		return;
	i = -1;
	printf("\n");
	while ((j = -1) && ++i < mstr->nodes_nb)
	{
		if (DEBUG_TRUNC_MATRIX && mstr->adjacency_mtx[i][A_PATH_NUMBER] == DISCONNECTED)
				continue;
		printf("\033[0;34m%10.*s : \33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][A_LINE_INDEX])->name_len,
				ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][A_LINE_INDEX])->line);
		printf ("node : %4d |", i);
		while (++j < 3 * mstr->nodes_nb + A_OPTIONS)
		{

			if (DEBUG_TRUNC_MATRIX && j >= A_OPTIONS)
				break;
			if ((j - A_OPTIONS) % mstr->nodes_nb == 0)
				printf("%3s", "|");
			if (mstr->adjacency_mtx[i][j] == DISCONNECTED)
				printf("%3s", " . ");
			else if (mstr->adjacency_mtx[i][j] == DEACTIVATED)
				printf("\033[0;31m%3s\033[0m", " X ");
			else if (j < A_OPTIONS)
				printf("\033[0;32m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else
				printf("%3d", mstr->adjacency_mtx[i][j]);

		}
		printf ("\n");
	}
	i = -1;

	if (DEBUG_TRUNC_MATRIX)
		return;
	printf("\n");
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
			break;

		printf("\033[0;34m%5.*s\33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->name_len,
				ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->line);
	}
	while (++i < mstr->nodes_nb)
	{
		if (mstr->node_path[i] == -1)
			break;

		printf("\033[0;34m%5.*s : \33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->name_len,
				ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[mstr->node_path[i]][A_LINE_INDEX])->line);
	}
	i = -1;
	printf("\nNode Path\n");
	printf("\n");
	while (++i < mstr->nodes_nb)
	{
	//	if (mstr->node_path[i] == -1)
	//		break;
		printf("%5d", mstr->node_path[i]);
	}
	printf("\nNode Parent\n");
	printf("\n");
	i = -1;
	while (++i < mstr->nodes_nb)
		printf("||%3d - %3d||", mstr->node_parent[i], mstr->node_queue[i]);
	printf("\n");
}

void    		ft_print_test(t_master *mstr, int activation)
{
    int     i;
	int		j;
	int		check;
	int		end[2];
	int 	start[2];

 	if (!activation)
		return;
	i = -1;
	end[0] = 0;
	start[0] = 0;
    while ((j = -1) && ++i < mstr->nodes_nb)
    {
		end[1] = 0;
		start[1] = 0;
		check = 0;
		while (++j < mstr->nodes_nb)
   		{
			if (mstr->adjacency_mtx[i][j + A_OPTIONS + 2 * mstr->nodes_nb] != -1)
			{
				if (!check)
					printf ("node : %4d |", i);
				check++;
				printf ("\033[0;33m%6d\033[0m", mstr->adjacency_mtx[i][j + A_OPTIONS + 2 * mstr->nodes_nb]);
				if (mstr->adjacency_mtx[i][j+ A_OPTIONS + 2 * mstr->nodes_nb] == mstr->start->node_number)
				{
					start[0]++;
					start[1] = 1;
				}
				if (mstr->adjacency_mtx[i][j + A_OPTIONS + 2 * mstr->nodes_nb] == mstr->end->node_number)
				{
					end[0]++;
					end[1] = 1;
				}
			}
		}
		if (check)
					printf("  --  %.*s",ft_storage_get_line(mstr->storage_start, mstr->adjacency_mtx[i][A_LINE_INDEX])->name_len,
						ft_storage_get_line(mstr->storage_start, mstr->adjacency_mtx[i][A_LINE_INDEX])->line);
		if (check > 1 && i != mstr->start->node_number)
					printf("\033[0;31m	error\033[0m");
		if (i == mstr->start->node_number)
					printf("\033[0;31m	||START||\033[0m");
		if (start[1])
					printf("\033[0;31m	start ?\033[0m");
		if (end[1])
					printf("\033[0;31m	end ?\033[0m");
		if (check)
			printf("\n");
    }
	printf("NB of link to start %d\n NB of link to end %d\n", start[0], end[0]);
}


void 		ft_debug_storage_print(t_storage *storage, int ind_max,  int activation)
{
	int 			ind;
	int 			reduc_ind;
	t_line_info		*entry;
	int				pos;
	int				length;


 	if (!activation)
		return;
	ind = -1;
	pos = 0;
	while(++ind < ind_max)
	{
		reduc_ind = ind % BATCH_MALLOC_SIZE;
		if (!reduc_ind && ind)
			storage = storage->next;
		entry = &(storage->entry[reduc_ind]);
		length = ft_strlen(entry->line);
		printf("\033[0;31m||%s||\033[0;33m- type %d \033[0;34m- index %d ",
		entry->line, entry->type, entry->line_index);
		if (entry->type == NODE)
			printf("\033[0;35mnode_nb %d - \033[0;36mname [[%.*s]] -hash %d",
				entry->node_number ,entry->name_len
				,entry->line, entry->hash_key);
		if (entry->type == PIPE)
			printf("\033[0;37m  pipe[%d-%d]\033[0m",
				entry->pipe[0], entry->pipe[1]);
		printf("\n");
	}
}
