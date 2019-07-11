/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:35:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/11 18:54:15 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "lem_in.h"

void 		ft_storage_print(t_storage *storage, int ind_max)
{
	return;
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
		printf("||%s||- type %d - index %d ",
		entry->line, entry->type, entry->line_index);
		if (entry->type == NODE)
			printf("node_nb %d - name [[%.*s]] -hash %d",
				entry->node_number ,entry->name_len
				,entry->line, entry->hash_key);
		if (entry->type == PIPE)
			printf("  pipe[%d-%d]",
				entry->pipe[0], entry->pipe[1]);
		printf("\n");
	}
}


static void    ft_print_matrix(t_master *mstr)
{
    int     i;
	int		j;
	int		check;
	int		end[2];
	int 	start[2];

  	//return;
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
				if (mstr->adjacency_mtx[i][j+ A_OPTIONS + 2 * mstr->nodes_nb] == 0)
				{
					start[0]++;
					start[1] = 1;
				}
				if (mstr->adjacency_mtx[i][j + A_OPTIONS + 2 * mstr->nodes_nb] == 1)
				{
					end[0]++;
					end[1] = 1;
				}
			}
		}
		if (check)
					printf("  --  %.*s",ft_storage_get_line(mstr->storage_start, mstr->adjacency_mtx[i][A_LINE_INDEX])->name_len,
						ft_storage_get_line(mstr->storage_start, mstr->adjacency_mtx[i][A_LINE_INDEX])->line);
		if (check > 1)
					printf("\033[0;31m	error\033[0m");
		if (start[1])
					printf("\033[0;31m	start ?\033[0m");
		if (end[1])
					printf("\033[0;31m	end ?\033[0m");
		if (check)
			printf("\n");
    }
	printf("NB of link to start %d\n NB of link to end %d\n", start[0], end[0]);
}
/*
static void    ft_print_matrix(t_master *mstr)
{
    int     i;
	int		j;
//	return;
  	i = -1;
	printf("\n");
    while ((j = -1) && ++i < mstr->nodes_nb)
    {
        printf ("node : %4d |", i);
		while (++j < 2 * mstr->nodes_nb + A_OPTIONS)
   		{

			if (j > 2 * mstr->nodes_nb + 3 + mstr->adjacency_mtx[i][mstr->nodes_nb + 3])
				break;
			else if (j == mstr->nodes_nb)
				printf("\033[0;34m%5.*s\33[0m",ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][mstr->nodes_nb])->name_len,
				ft_storage_get_line(mstr->storage, mstr->adjacency_mtx[i][mstr->nodes_nb])->line);
			else if (mstr->adjacency_mtx[i][j] == -1 && j <= 2 * mstr->nodes_nb + 3 )
				printf ("%3s", " ");
			else if (j > 2 * mstr->nodes_nb + 3)
				printf ("\033[0;36m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else if (j > mstr->nodes_nb + 3)
				printf ("\033[0;33m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else if (j == mstr->nodes_nb + 2)
				printf ("\033[0;35m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else if (mstr->adjacency_mtx[i][j] && j < mstr->nodes_nb)
				printf ("\033[0;31m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else if (mstr->adjacency_mtx[i][j])
				printf ("\033[0;32m%3d\033[0m", mstr->adjacency_mtx[i][j]);
			else
				printf ("%3d", mstr->adjacency_mtx[i][j]);

			if (mstr->adjacency_mtx[i][j] != DISCONNECTED)
				printf("%3d", mstr->adjacency_mtx[i][j]);
			else
				printf("%3s", "");
		}

		printf ("\n");
	}
}
*/
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
	ft_adjacency_matrix_generate(mstr, mstr->storage_start);
	ft_storage_print(mstr->storage_start, mstr->lines_nb);
	printf("collisions : %d\n", mstr->dico->collisions);
	#define TEST "Mvo6"
	printf("get %s - %d\n", TEST , ft_dico_get(mstr->storage_start, mstr->dico, TEST , ft_strlen(TEST)));
	printf("start: %d and end %d\n", mstr->start->node_number, mstr->end->node_number);
	//ft_print_matrix(mstr);
	solver(mstr);
	ft_print_matrix(mstr);
	printf("\n\n\n\n");
	return;
	ft_print_matrix(mstr);
}
