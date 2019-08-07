/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/07 10:02:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"

int			main(int argc, char **argv)
{
	t_master	*mstr;
	int			start;
	int			end;

	argc--;
	argv++;
	if (!(mstr = (t_master *)ft_memalloc(sizeof(t_master))))
		ft_exit(FAIL_MALLOC_MSTR, mstr);
	ft_init_mstr(mstr);
	ft_option_get(mstr, argc, argv);
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
