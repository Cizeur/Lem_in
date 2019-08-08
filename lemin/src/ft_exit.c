/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:31:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 17:17:58 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

char g_error_message[23][40] = {
	{"Standard"},
	{"Space before name"},
	{"Entry already in dic"},
	{"Failed dico malloc"},
	{"Repeat cell names"},
	{"Failed dico entry malloc"},
	{"GIVE ME ANTS"},
	{"DIGITS ONLY"},
	{"nope9"},
	{"nope10"},
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
	{"nope21"},
	{"nope22"},
	{"nope23"}
};

void		ft_exit(t_errors error, t_master *mstr)
{
	if (error != STANDARD && error != INVALID_ARGUMENT)
		ft_putstr("ERROR\n");
	ft_free_everything(mstr);
	exit(error != STANDARD ? 1 : 0);
}
