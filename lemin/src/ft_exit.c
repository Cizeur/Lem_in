/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:31:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/09 12:13:30 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lem_in.h"
#include "output.h"
#include "libft/libft.h"
#include <stdlib.h>

#    include <stdio.h>

char g_error_message[26][50] = {
	{"\n-----            DONE               -----\n\n"},
	{"\n	INVALID LINE FORMAT\n\n"},
	{"\n	DOUBLE START\n\n"},
	{"\n	DOUBLE END\n\n"},
	{"\n	WRONG COMMAND POSITION \n\n"},
	{"\n	INVALID LINE\n\n"},
	{"\n	ROOM ALREADY DEFINED\n\n"},
	{"\n	DASH IN NAME\n\n"},
	{"\n	ANTS STRICTLY POSITIVE INT\n\n"},
	{"\n	ANTS NUMBER ONLY\n\n"},
	{"\n	NON EXISTING ROOM\n\n"},
	{"\n	START OR END MISSING\n\n"},
	{"\n	NO PATH FOUNDS\n\n"},
	{"\n	SOLUTION EXTRACTION FAILED\n\n"},
	{"nope11"},
	{"nope12"},
	{"nope13"},
	{"nope14"},
	{"NO FLOW"},
	{"nope16"},
	{"nope17"},
	{"nope18"},
	{"nope19"},
	{"nope20"},
	{"nope22"},
	{"\n	MALLOC DICO FAILED\n\n"},
};

void		ft_exit(t_errors error, t_master *mstr)
{
	if (error != STANDARD && error != INVALID_ARGUMENT)
		ft_putstr("ERROR\n");
	if (mstr && mstr->output_type >= OUTPUT_EXPLAINED && error < 14)
		ft_putstr(g_error_message[error]);
	if (mstr && mstr->output_type >= OUTPUT_EXPLAINED && error && error <= 11)
	{
		ft_putstr("		");
		ft_putstr(ft_storage_get_line(mstr, mstr->lines_nb)->line);
		ft_putstr("\n");
	}
	ft_free_everything(mstr);
	exit(error != STANDARD ? 1 : 0);
}
