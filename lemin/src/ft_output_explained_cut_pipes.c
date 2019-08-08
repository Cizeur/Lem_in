/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_explained_cut_pipes.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 13:40:54 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 18:45:59 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output.h"

void		ft_output_explained_cut_pipes(t_master *mstr, int node1, int node2)
{
	t_line_info *entry1;
	t_line_info *entry2;
	int			**mtx;

	if (mstr->output_type != OUTPUT_EXPLAINED
		&& mstr->output_type != OUTPUT_EXPLAINED_SHORT)
		return ;
	mtx = mstr->adjacency_mtx;
	entry1 = ft_storage_get_line(mstr, mtx[node1][A_LINE_INDEX]);
	entry2 = ft_storage_get_line(mstr, mtx[node2][A_LINE_INDEX]);
	ft_output_putstr("\e[33m	Cut edge : ", mstr);
	ft_output_putnstr(entry1->line, entry1->name_len, mstr);
	ft_output_putstr(" - ", mstr);
	ft_output_putnstr(entry2->line, entry2->name_len, mstr);
	ft_output_putstr("\n\e[0m", mstr);
}
