/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:31:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/31 14:06:35 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "lem_in.h"
#include <stdlib.h>

char g_error_message[13][40] = {
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
	{"nope13"}
};

void		ft_exit(t_errors error)
{
	/*
	printf("\e[36m");
	printf("\n\n####################################################\n");
	printf("####################################################\n");
	printf("#ERROR %3d%40s #\n", error, g_error_message[error]);
	printf("####################################################\n");
	printf("####################################################\n\n");
	printf("\e[0m");
	*/
	error = 0;
	ft_putstr(S_ERROR_OUTPUT);
	//pause();
	exit(error != STANDARD ? 1 : 0);
}
