/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:00:32 by cesar             #+#    #+#             */
/*   Updated: 2019/08/07 08:41:54 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output.h"
#include "utils.h"
#include "libft/libft.h"

static void		ft_output_first_lines(t_master *mstr, int activation)
{
	ft_putstr(mstr->storage_start->entry[0].line);
	ft_putchar('\n');
	if (activation != OUTPUT_VISU)
		return ;
	ft_putstr(SO_NODE_NB);
	ft_putnbr(mstr->nodes);
	ft_putchar('\n');
	ft_putstr(SO_PIPE_NB);
	ft_putnbr(mstr->pipes);
	ft_putchar('\n');
	ft_putstr(SO_MVMT_NB);
	ft_putnbr(mstr->turn_counter);
	ft_putchar('\n');
	ft_putstr(SO_INACT_PIPE_NB);
	ft_putnbr(mstr->inactives_pipes_nb);
	ft_putchar('\n');
}

static int		ft_is_path_start(int node, t_master *mstr)
{
	int i;
	int *solution_start;
	int flow;

	i = -1;
	solution_start = mstr->stored_solution;
	flow = mstr->final_flow;
	while (++i < flow)
	{
		if (solution_start[i] == node)
			return (1);
	}
	return (0);
}

static void		ft_output_pipe(t_master *mstr, t_line_info entry)
{
	int **mtx;

	mtx = mstr->adjacency_mtx;
	if (!(entry.pipe[0] == mstr->start->node_number)
			&& !(entry.pipe[1] == mstr->start->node_number))
	{
		if (mtx[entry.pipe[0]][A_STORED_SOLUTION] != entry.pipe[1]
			&& mtx[entry.pipe[1]][A_STORED_SOLUTION] != entry.pipe[0])
			ft_output_putstr(SO_INACT_PIPE_MK, mstr);
		else
			ft_output_putstr(SO_ACT_PIPE_MK, mstr);
	}
	else if (!ft_is_path_start(entry.pipe[1], mstr)
			&& !ft_is_path_start(entry.pipe[0], mstr))
		ft_output_putstr(SO_INACT_PIPE_MK, mstr);
	else
		ft_output_putstr(SO_ACT_PIPE_MK, mstr);
}

static void		ft_output_batch_print(t_storage *storage, t_master *mstr,
							int activ_visu)
{
	int			i;
	t_line_info entry;

	i = 0;
	mstr->buffer_pos = 0;
	while (storage)
	{
		while (++i < BATCH_MALLOC_SIZE && (entry = storage->entry[i]).line)
		{
			if (entry.type == PIPE && activ_visu == OUTPUT_VISU)
				ft_output_pipe(mstr, entry);
			ft_output_putstr(storage->entry[i].line, mstr);
			ft_output_putstr("\n", mstr);
		}
		storage = storage->next;
		i = -1;
	}
}

void			output(t_master *mstr)
{
	mstr->buffer_pos = 0;
	ft_bzero(mstr->output, BATCH_PRINT_SIZE + 1);
	if (mstr->output_type == OUTPUT_DEACTIVATED)
		return ;
	ft_output_count_inactive_pipes(mstr);
	ft_output_first_lines(mstr, mstr->output_type);
	ft_output_batch_print(mstr->storage_start, mstr, mstr->output_type);
	ft_output_buffer_flush(mstr);
	ft_output_solution(mstr);
	ft_output_buffer_flush(mstr);
}
