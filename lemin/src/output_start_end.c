/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_start_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:00:32 by cesar             #+#    #+#             */
/*   Updated: 2019/08/07 17:03:55 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output.h"
#include "utils.h"
#include "libft/libft.h"

static void		ft_output_first_lines(t_master *mstr, int activation)
{
	ft_output_putnbr(mstr->ants, mstr);
	ft_output_putstr("\n", mstr);
	if (activation != OUTPUT_VISU && activation != OUTPUT_VISU_FULL)
		return ;
	ft_output_putstr(SO_NODE_NB, mstr);
	ft_output_putnbr(mstr->nodes, mstr);
	ft_output_putstr("\n", mstr);
	ft_output_putstr(SO_PIPE_NB, mstr);
	ft_output_putnbr(mstr->pipes, mstr);
	ft_output_putstr("\n", mstr);
	ft_output_putstr(SO_MVMT_NB, mstr);
	ft_output_putnbr(1, mstr);
	ft_output_putstr("\n", mstr);
	ft_output_putstr(SO_INACT_PIPE_NB, mstr);
	ft_output_putnbr(mstr->pipes - 1, mstr);
	ft_output_putstr("\n", mstr);
}

static void		ft_output_pipe(t_master *mstr, t_line_info entry)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (mstr->output_type == OUTPUT_VISU)
	{
		if ((entry.pipe[0] == mstr->start->node_number
				&& entry.pipe[1] == mstr->end->node_number)
				|| (entry.pipe[1] == mstr->start->node_number
				&& entry.pipe[0] == mstr->end->node_number))
			ft_output_putstr(SO_ACT_PIPE_MK, mstr);
		else
			ft_output_putstr(SO_INACT_PIPE_MK, mstr);
	}
	if (mstr->output_type == OUTPUT_VISU_FULL)
		ft_output_putstr(SO_ACT_PIPE_MK, mstr);
}

static void		ft_output_batch_print(t_storage *storage, t_master *mstr)
{
	int			i;
	t_line_info entry;
	int			initiated;

	i = -1;
	mstr->buffer_pos = 0;
	initiated = NOPE;
	while ((i = -1) && storage)
	{
		while (++i < BATCH_MALLOC_SIZE && (entry = storage->entry[i]).line)
		{
			if (!initiated && entry.type != COMMENT && (initiated = CERTAINLY))
			{
				ft_output_first_lines(mstr, mstr->output_type);
				continue;
			}
			if (entry.type == PIPE)
				ft_output_pipe(mstr, entry);
			ft_output_putstr(entry.line, mstr);
			ft_output_putstr("\n", mstr);
		}
		storage = storage->next;
		i = -1;
	}
	ft_output_putstr("\n", mstr);
}

static void		ft_output_solution_start_end(t_master *mstr)
{
	int			ants;
	int			**mtx;
	t_line_info	*entry;

	ants = 0;
	mtx = mstr->adjacency_mtx;
	while (++ants <= mstr->ants)
	{
		if (mstr->line_started)
			ft_output_putstr(" ", mstr);
		mstr->line_started = CERTAINLY;
		ft_output_putstr("L", mstr);
		ft_output_putnbr(ants, mstr);
		ft_output_putstr("-", mstr);
		entry = ft_storage_get_line(mstr,
			mtx[mstr->end->node_number][A_LINE_INDEX]);
		ft_output_putnstr(entry->line, entry->name_len, mstr);
	}
	ft_output_putstr("\n", mstr);
}

void			output_start_end(t_master *mstr)
{
	mstr->buffer_pos = 0;
	ft_bzero(mstr->output, BATCH_PRINT_SIZE + 1);
	if (mstr->output_type == OUTPUT_DEACTIVATED)
		return ;
	ft_output_count_inactive_pipes(mstr);
	if (mstr->output_type != OUTPUT_JUST_SOLUTION)
		ft_output_batch_print(mstr->storage_start, mstr);
	ft_output_solution_start_end(mstr);
	if (mstr->output_type == OUTPUT_JUST_SOLUTION)
	{
		ft_output_putstr(SO_MVMT_NB, mstr);
		ft_output_putnbr(mstr->turn_counter, mstr);
		ft_output_putstr("\n", mstr);
	}
	ft_output_buffer_flush(mstr);
	ft_exit(STANDARD, mstr);
}
