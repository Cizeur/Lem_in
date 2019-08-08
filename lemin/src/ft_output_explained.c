/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_explained.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 09:13:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 16:35:07 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output_explained.h"
#include "output.h"
#include "libft/libft.h"

static void		ft_output_current_flow(int final_flow, t_master *mstr)
{
	if (!final_flow)
	{
		ft_output_putstr("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", mstr);
		ft_output_putstr(
			"\n!!!    \e[32mSEARCHING FOR PATHS\e[0m    !!!", mstr);
		ft_output_putstr("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", mstr);
		return ;
	}
	ft_output_putstr("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", mstr);
	ft_output_putstr("\n!!!PATHS \e[32mVALIDATED\e[0m -> FLOW: \e[32m", mstr);
	ft_output_putnbr(final_flow, mstr);
	ft_output_putstr("\xE2\x9C\x94\e[0m!!!", mstr);
	ft_output_putstr("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n", mstr);
}

static void		ft_passed_threshold(int o_case, t_master *mstr)
{
	t_line_info *entry;

	if (o_case == OCS_INIT)
		ft_output_putstr("\n----- Welcome on the algo clarifier -----\n", mstr);
	else if (o_case == OC_MALLOC_STORAGE)
		ft_output_putstr(
			"BASIC STRUCT AND STORAGE Mallocated \e[32m \xE2\x9C\x94", mstr);
	else if (o_case == OC_VALID_OPTIONS)
		ft_output_putstr("OPTIONS \e[32m \xE2\x9C\x94", mstr);
	else if (o_case == OC_NODES_OK)
	{
		ft_output_putstr("NODES \e[32m \xE2\x9C\x94", mstr);
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
		ft_output_putstr(
			"LINK MATRIX-PATH-QUEUE Mallocated\e[32m \xE2\x9C\x94\n", mstr);
}

static void		ft_print_path(t_master *mstr)
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
	ft_output_putstr("\e[0m", mstr);
}

static void		ft_paths_cases(t_master *mstr, int o_case)
{
	if (o_case == OC_OUTPUT_AUGMENTING_PATH)
	{
		ft_output_putstr("NEW AUGMENTING PATH : \e[34m", mstr);
		ft_print_path(mstr);
	}
	if (o_case == OC_OUTPUT_FOUND_PATH)
	{
		ft_output_putstr("NEW EXTRACTED PATHS : \e[35m", mstr);
		ft_print_path(mstr);
	}
	if (o_case == OC_OUTPUT_SHORTEN_PATH)
	{
		ft_output_putstr("SHORTENED PATHS     : \e[36m", mstr);
		ft_print_path(mstr);
	}
}

void			ft_output_explained(t_master *mstr, int o_case)
{
	if (mstr->output_type != OUTPUT_EXPLAINED)
		return ;
	ft_passed_threshold(o_case, mstr);
	if (o_case == OC_PATH_VALIDATED)
		ft_output_current_flow(mstr->final_flow, mstr);
	ft_paths_cases(mstr, o_case);
	ft_output_putstr("\e[0m\n", mstr);
	ft_output_buffer_flush(mstr);
}
