/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:46:24 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/29 17:07:20 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_output_putstr(char *str, t_master *mstr)
{
	int i;
	int buffer_pos;
	char *buffer;

	buffer = mstr->output;
	buffer_pos = mstr->buffer_pos;
	i = 0;
	while (str[i])
	{
		if (buffer_pos + i >= BATCH_PRINT_SIZE)
		{
			write(1, buffer, BATCH_PRINT_SIZE);
			ft_bzero(buffer, BATCH_PRINT_SIZE + 1);
			buffer_pos = -i;
		}
		buffer[buffer_pos + i] = str[i];
		i++;
	}
	mstr->buffer_pos = buffer_pos + i;
}

void		ft_output_putnstr(char *str, int n ,t_master *mstr)
{
	int i;
	int buffer_pos;
	char *buffer;

	buffer = mstr->output;
	buffer_pos = mstr->buffer_pos;
	i = 0;
	while (str[i] && i < n)
	{
		if (buffer_pos + i >= BATCH_PRINT_SIZE)
		{
			write(1, buffer, BATCH_PRINT_SIZE);
			ft_bzero(buffer, BATCH_PRINT_SIZE + 1);
			buffer_pos = -i;
		}
		buffer[buffer_pos + i] = str[i];
		i++;
	}
	mstr->buffer_pos = buffer_pos + i;
}

void		ft_output_buffer_flush(t_master *mstr)
{
	if (mstr->buffer_pos)
		write(1, mstr->output, mstr->buffer_pos);
	ft_bzero(mstr->output, BATCH_PRINT_SIZE + 1);
	mstr->buffer_pos = 0;
}

void    ft_output_putnbr(int n, t_master *mstr)
{
        long int ns;
		long int ten_power;
		char s[2];

		s[1] = 0;
        ns = n;
		if (!ns)
			ft_output_putstr("0", mstr);
        if (ns < 0)
        {
                ns = -ns;
				s[0] = '-';
                ft_output_putstr(s, mstr);
        }
		ten_power = 1;
		while (ns >= ten_power)
			ten_power *= 10;
		ten_power /= 10;
		while (ten_power > 0)
		{
			 s[0] = '0' + ns / ten_power ;
			 ns = ns % ten_power;
			 ft_output_putstr(s, mstr);
			 ten_power /= 10;
		}
}
