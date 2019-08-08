/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_explained.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 09:13:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 12:59:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output_explained.h"
#include "output.h"
#include "libft/libft.h"

static void			ft_output_current_flow(int final_flow, t_master *mstr)
{
	if (!final_flow)
	{
		ft_output_putstr("SEARCHING FOR PATHS\e[32m", mstr);
		return ;
	}
	ft_output_putstr("PATHS FOUND -> FLOW: \e[32m", mstr);
	ft_output_putnbr(final_flow, mstr);
	ft_output_putstr("\xE2\x9C\x94\n", mstr);
}

static	void		ft_passed_threshold(int o_case, t_master *mstr)
{
	t_line_info *entry;

	if (o_case == OCS_INIT)
		ft_output_putstr("\n----- Welcome on the algo clarifier -----\n", mstr);
	else if (o_case == OC_MALLOC_STORAGE)
		ft_output_putstr("BASIC STRUCT AND STORAGE Mallocated \e[32m \xE2\x9C\x94", mstr);
	else if (o_case == OC_VALID_OPTIONS)
		ft_output_putstr("OPTIONS \e[32m \xE2\x9C\x94", mstr);
	else if (o_case == OC_NODES_OK)
	{
		ft_output_putstr("NODES \e[32m \xE2\x9C\x94\n", mstr);
		entry = mstr->start;
		ft_output_putstr("\e[0m\n	START NODE : \e[32m", mstr);
		ft_output_putnstr(entry->line, entry->name_len, mstr);
		ft_output_putstr("\e[0m\n	  END NODE : \e[32m", mstr);
		entry = mstr->end;
		ft_output_putnstr(entry->line, entry->name_len, mstr);
	}
	else if (o_case == OC_PIPES_OK)
		ft_output_putstr("PIPES \e[32m \xE2\x9C\x94", mstr);
	else if (o_case == OC_MALLOC_MATRIX)
		ft_output_putstr("ADJACENCY MATRIX-PATH-QUEUE Mallocated\e[32m \xE2\x9C\x94\n", mstr);
	ft_output_buffer_flush(mstr);
}

static void			ft_print_path(t_master *mstr)
{
	int			i;
	int			j;
	int			**mtx;
	t_line_info	*entry;

	i = -1;
	mtx = mstr->adjacency_mtx;
	while ((j = -1) && ++i < mstr->nodes)
	{
		if (mstr->node_path[i] == -1)
			break ;
		entry = ft_storage_get_line(mstr,
				mtx[mstr->node_path[i]][A_LINE_INDEX]);
		ft_output_putnstr(entry->line, entry->name_len, mstr);
		if (mstr->node_path[i + 1] != -1)
			ft_output_putstr(" - ", mstr);
	}
}

void			ft_output_explained(t_master *mstr, int o_case)
{
	if (mstr->output_type != OUTPUT_EXPLAINED)
		return ;
	ft_passed_threshold(o_case, mstr);
	if (o_case == OC_PATH_FOUNDS)
		ft_output_current_flow(mstr->final_flow, mstr);
	if (o_case == OC_OUTPUT_AUGMENTING_PATH)
	{
		ft_output_putstr("NEW AUGMENTING PATH : ", mstr);
		ft_print_path(mstr);
	}
	ft_output_putstr("\e[0m\n", mstr);
}
