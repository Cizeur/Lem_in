/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_apply_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 08:34:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/12 14:41:45 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_parser_apply_command(t_master *mstr, t_line_info *entry)
{
	if (entry->type == START)
		mstr->command_line = COM_START;
	else if (entry->type == END)
		mstr->command_line = COM_END;
	else if (mstr->command_line == COM_START && entry->type == NODE)
		mstr->start = entry;
	else if (mstr->command_line == COM_END && entry->type == NODE)
		mstr->end = entry;
	else if ((mstr->command_line == COM_START || mstr->command_line == COM_END)
			&& entry->type != NODE)
			ft_exit(WRONG_POSITION_FOR_START_END);
	if (entry->type != START && entry->type != END)
		mstr->command_line = COM_DEFAULT;
}
