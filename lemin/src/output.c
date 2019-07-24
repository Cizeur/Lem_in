/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:00:32 by cesar             #+#    #+#             */
/*   Updated: 2019/07/23 14:03:47 by cesar            ###   ########.fr       */
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
}

static void		ft_output_entry_add_buffer(t_line_info *entry, char *buffer, int *buffer_pos)
{
	int i;

	i = 0;
	while (entry->line[i])
	{
		if (*buffer_pos + i >= BATCH_PRINT_SIZE)
		{
			write(1, buffer, BATCH_PRINT_SIZE);
			ft_bzero(buffer, BATCH_PRINT_SIZE + 1);
			*buffer_pos = -i;
		}
		buffer[*buffer_pos + i] = entry->line[i];
		i++;
	}
	*buffer_pos = *buffer_pos + i + 1;
	if (*buffer_pos + i >= BATCH_PRINT_SIZE)
	{
		write(1, buffer, BATCH_PRINT_SIZE);
		ft_bzero(buffer, BATCH_PRINT_SIZE + 1);
		ft_putchar('\n');
		*buffer_pos = 0;
	}
	else
		buffer[*buffer_pos - 1] = '\n';
}

static void		ft_output_batch_print(t_storage *storage, char *buffer)
{
	int i;
	int buffer_pos;

	ft_bzero(buffer, BATCH_PRINT_SIZE + 1);
	i = 0;
	buffer_pos = 0;
	while (storage)
	{
		while(++i < BATCH_MALLOC_SIZE && storage->entry[i].line)
			ft_output_entry_add_buffer(&(storage->entry[i]), buffer, &buffer_pos);
		if (buffer_pos)
			write(1, buffer, buffer_pos);
		storage = storage->next;
		i = -1;
	}
}
void			output(t_master *mstr)
{
	if (!OUTPUT_ACTIVATED)
		return;
	ft_output_first_lines(mstr);
	ft_output_batch_print(mstr->storage_start, mstr->output);
}
