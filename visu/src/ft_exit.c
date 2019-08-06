/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:20:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 19:13:34 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visu.h"
#include "error.h"

char g_error_message[13][40] = {
	{"ERROR_MALLOC"},
	{"FAIL_ON_READ"},
	{"INVALID_INPUT"},
	{"INVALID_NAME"},
	{"OVERLAPING_ROOMS"},
	{"INIT_SDL"},
	{"LOAD_VISU"},
	{"RENDER_VISU"},

	{"LOAD_IMG"},
	{"RENDER_VISU"},
	{"WRONG_ARGUENT"},
	{"nope12"},
	{"nope13"}
};

int    ft_exit(t_master *mstr, t_errors error)
{
	printf("\e[36m");
	printf("\n\n####################################################\n");
	printf("####################################################\n");
	printf("# ERROR %3d%39s #\n", error, g_error_message[error]);
	printf("####################################################\n");
	printf("####################################################\n\n");
	printf("\e[0m");
    close_program(mstr, VISU_FAILED);
    return(FALSE);
}