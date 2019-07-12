/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:35:16 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/12 16:39:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "lem_in.h"

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
	if (!mstr->start || !mstr->end)
		ft_exit(START_OR_END_MISSING);
	ft_matrix_generate(mstr, mstr->storage_start);
//_
	ft_debug_storage_print(mstr->storage_start, mstr->lines_nb, DEBUG_PRINT_STORAGE);
	printf("collisions : %d\n", mstr->dico->collisions);
	printf("start: %d and end %d\n", mstr->start->node_number, mstr->end->node_number);
//^//
	solver(mstr);
//
	int magic[3];
	magic[0] = mstr->ants_nb;
	magic[1] = mstr->adjacency_mtx[mstr->start->node_number][A_LINKS_NB];
	magic[2] = mstr->adjacency_mtx[mstr->end->node_number][A_LINKS_NB];
	ft_print_test(mstr, DEBUG_PRINT_TEST_RESULT);
	printf("max flow options -%d -%d -%d\n", magic[0],magic[1],magic[2]);
	printf("\n\nmax flow -%d\n", mstr->magic_number);
	printf("final flow -%d\n", mstr->nb_solutions);
	printf("amount of killed pipe - %d\n", mstr->killed);
//^//
}
