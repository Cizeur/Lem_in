/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_apply_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 08:34:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/09 09:58:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error.h"

void		ft_parser_apply_command(t_master *mstr, t_line_info *entry)
{
	if ((mstr->command_line == COM_START || mstr->command_line == COM_END)
				&& (entry->type == START || entry->type == END))
		ft_exit(WRONG_POSITION_FOR_START_END, mstr);
	if (entry->type == START)
		mstr->command_line = COM_START;
	else if (entry->type == END)
		mstr->command_line = COM_END;
	else if (mstr->command_line == COM_START && entry->type == NODE)
	{
		if (mstr->start)
			ft_exit(DOUBLE_START, mstr);
		mstr->start = entry;
	}
	else if (mstr->command_line == COM_END && entry->type == NODE)
	{
		if (mstr->end)
			ft_exit(DOUBLE_END, mstr);
		mstr->end = entry;
	}
	else if ((mstr->command_line == COM_START || mstr->command_line == COM_END)
				&& entry->type != NODE)
		ft_exit(WRONG_POSITION_FOR_START_END, mstr);
	if (entry->type != START && entry->type != END)
		mstr->command_line = COM_DEFAULT;
}
