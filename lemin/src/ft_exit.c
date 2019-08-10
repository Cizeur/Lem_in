/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:31:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/09 15:52:39 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lem_in.h"
#include "output.h"
#include "libft/libft.h"
#include <stdlib.h>

char g_error_message[16][50] = {
	{"\n-----            DONE               -----\n\n"},
	{"\n	EMPTY FILE\n\n"},
	{"\n	INCOMPLETE FILE\n\n"},
	{"\n	INVALID LINE FORMAT\n\n"},
	{"\n	DOUBLE START\n\n"},
	{"\n	DOUBLE END\n\n"},
	{"\n	WRONG COMMAND POSITION : NODE EXPECTED \n\n"},
	{"\n	ROOM ALREADY DEFINED\n\n"},
	{"\n	DASH IN NAME\n\n"},
	{"\n	ANTS STRICTLY POSITIVE INT\n\n"},
	{"\n	ANTS NUMBER ONLY\n\n"},
	{"\n	NON EXISTING ROOM\n\n"},
	{"\n	START OR END MISSING\n\n"},
	{"\n	NO PATH FOUNDS\n\n"},
	{"\n	SOLUTION EXTRACTION FAILED\n\n"},
	{"\n	FAILED MALLOC\n\n"},
};

void		ft_exit(t_errors error, t_master *mstr)
{
	t_line_info *entry;

	if (error != STANDARD && error != INVALID_ARGUMENT)
		ft_putstr("ERROR\n");
	if (mstr && mstr->output_type >= OUTPUT_EXPLAINED && error)
		ft_putstr(g_error_message[ft_min(error, 15)]);
	if (mstr && mstr->output_type >= OUTPUT_EXPLAINED && error && error <= 11)
	{
		entry = ft_storage_get_line(mstr, mstr->lines_nb) ;
		if (entry && entry->line)
		{
			ft_putstr("		-|-");
			ft_putstr(entry->line);
			ft_putstr("-|-\n");
		}
	}
	ft_free_everything(mstr);
	exit(error != STANDARD ? 1 : 0);
}
