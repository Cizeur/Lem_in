/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/11 15:28:12 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"
#include "output_explained.h"
#include "error.h"

int			main(int argc, char **argv)
{
	t_master	*mstr;
	int			start;
	int			end;
	int			explained;

	mstr = 0;
	explained = ft_explained_get(mstr, --argc, ++argv);
	if (!(mstr = (t_master *)ft_memalloc(sizeof(t_master))))
		ft_exit(FAIL_MALLOC_MSTR, mstr);
	ft_init_mstr(mstr, explained);
	if (explained)
		ft_putstr("STRUCT AND STORAGE Malloc'ed \e[32m \xE2\x9C\x94\e[0m\n");
	ft_option_get(mstr, argc, argv);
	ft_output_explained(mstr, OC_MALLOC_STORAGE);
	ft_output_explained(mstr, OC_VALID_OPTIONS);
	parser(mstr);
	start = mstr->start->node_number;
	end = mstr->end->node_number;
	if (mstr->adjacency_mtx[start][A_OPTIONS + mstr->nodes + end]
			!= DISCONNECTED)
		output_start_end(mstr);
	solver(mstr);
	output(mstr);
	ft_exit(STANDARD, mstr);
	return (0);
}
