/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/17 11:19:40 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "stdlib.h"
#include "libft/libft.h"

int			main(int  argc, char **argv)
{
	t_master *mstr;

	argc--;
	argv++;
	if (!(mstr=(t_master *)ft_memalloc(sizeof(t_master))))
		return(1);
	ft_init_mstr(mstr);
	parser(mstr);
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
	return (0);
}
