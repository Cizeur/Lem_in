/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:34:54 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 18:46:55 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_push_one_ant_forward(t_master *mstr, int *cur_cell)
{
	int			**mtx;
	t_line_info	*entry;

	mtx = mstr->adjacency_mtx;
	if (mtx[cur_cell[A_STORED_SOLUTION]][A_ANT_HIST] != DISCONNECTED
		&& cur_cell[A_STORED_SOLUTION] != mstr->end->node_number)
		ft_push_one_ant_forward(mstr, mtx[cur_cell[A_STORED_SOLUTION]]);
	if (mstr->line_started)
		ft_output_putstr(" ", mstr);
	mstr->line_started = CERTAINLY;
	ft_output_putstr("L", mstr);
	ft_output_putnbr(cur_cell[A_ANT_HIST], mstr);
	ft_output_putstr("-", mstr);
	entry = ft_storage_get_line(mstr,
			mtx[cur_cell[A_STORED_SOLUTION]][A_LINE_INDEX]);
	ft_output_putnstr(entry->line, entry->name_len, mstr);
	mtx[cur_cell[A_STORED_SOLUTION]][A_ANT] = cur_cell[A_ANT_HIST];
	cur_cell[A_ANT_HIST] = DISCONNECTED;
}

static void		ft_push_ants_forward(t_master *mstr, int max_node)
{
	int **mtx;
	int i;
	int *cur_cell;

	i = -1;
	mtx = mstr->adjacency_mtx;
	while (++i < max_node)
	{
		if (mtx[i][A_ANT_HIST] == DISCONNECTED || i == mstr->end->node_number
			|| i == mstr->start->node_number)
			continue;
		cur_cell = mtx[i];
		ft_push_one_ant_forward(mstr, cur_cell);
	}
}

static void		ft_update_history(t_master *mstr, int max_node)
{
	int i;
	int **mtx;

	i = -1;
	mtx = mstr->adjacency_mtx;
	while (++i < max_node)
	{
		mtx[i][A_ANT_HIST] = mtx[i][A_ANT];
		mtx[i][A_ANT] = -1;
	}
}

static int		ft_load_new_ants(t_master *mstr, int ants, int turns)
{
	int			i;
	int			**mtx;
	int			cur_cell;
	t_line_info	*entry;

	i = -1;
	mtx = mstr->adjacency_mtx;
	while (ants <= mstr->ants && ++i < mstr->final_flow)
	{
		cur_cell = mstr->stored_solution[i];
		if (i && mtx[cur_cell][A_STORED_PATH_LEN] > turns)
			break ;
		mtx[cur_cell][A_ANT] = ants;
		if (mstr->line_started)
			ft_output_putstr(" ", mstr);
		mstr->line_started = CERTAINLY;
		ft_output_putstr("L", mstr);
		ft_output_putnbr(ants, mstr);
		ft_output_putstr("-", mstr);
		entry = ft_storage_get_line(mstr,
			mtx[cur_cell][A_LINE_INDEX]);
		ft_output_putnstr(entry->line, entry->name_len, mstr);
		ants++;
	}
	return (ants);
}

void			ft_output_solution(t_master *mstr)
{
	int max_node;
	int turns;
	int ants;
	int i;

	ft_output_explained_string(mstr,
		"\n-----          SOLUTION             -----\n\n");
	ants = 1;
	max_node = mstr->nodes;
	turns = mstr->turn_counter;
	i = -1;
	while (turns--)
	{
		mstr->line_started = NOPE;
		ft_output_explained_string(mstr,
			"\e[33mPUSHING ANTS FORWARD:\n	\e[36m[");
		ft_push_ants_forward(mstr, max_node);
		ft_output_explained_string(mstr,
			"]\e[31m\n	THEN LOADING NEW ANTS:\n	\e[36m[");
		ants = ft_load_new_ants(mstr, ants, turns);
		ft_output_explained_string(mstr, "]\e[33m\nEND OF TURN\n");
		ft_update_history(mstr, max_node);
		ft_output_putstr("\n", mstr);
	}
}
