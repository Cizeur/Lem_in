/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:00:32 by cesar             #+#    #+#             */
/*   Updated: 2019/07/29 17:32:03 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include "output.h"
#include "libft/libft.h"

static void		ft_output_first_lines(t_master *mstr)
{
	ft_putstr(mstr->storage_start->entry[0].line);
	ft_putchar('\n');
	ft_putstr(SO_NODE_NB);
	ft_putnbr(mstr->nodes_nb);
	ft_putchar('\n');
	ft_putstr(SO_PIPE_NB);
	ft_putnbr(mstr->pipes_nb);
	ft_putchar('\n');
	ft_putstr(SO_MVMT_NB);
	ft_putnbr(mstr->turn_counter);
	ft_putchar('\n');
}

static void		ft_output_batch_print(t_storage *storage, t_master *mstr)
{
	int i;


	i = 0;
	mstr->buffer_pos = 0;
	while (storage)
	{
		while(++i < BATCH_MALLOC_SIZE && storage->entry[i].line)
		{
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
	if (OUTPUT_ACTIVATED)
	{
		ft_output_first_lines(mstr);
		ft_output_batch_print(mstr->storage_start, mstr);
	}
	ft_output_buffer_flush(mstr);
	ft_putstr(SO_MVMT_NB);
	ft_putnbr(mstr->turn_counter);
	ft_putchar('\n');
	ft_output_solution(mstr);
	ft_output_buffer_flush(mstr);
	ft_putstr(SO_MVMT_NB);
	ft_putnbr(mstr->turn_counter);
	ft_putchar('\n');
}
