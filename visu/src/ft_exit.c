/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:20:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/08 18:59:02 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visu.h"
#include "error.h"

char g_error_message[10][200] = {
	{"# ERROR  1                            ERROR_MALLOC #"},
	{"# ERROR  2                            FAIL_ON_READ #"},
	{"# ERROR  3                           INVALID_INPUT #"},
	{"# ERROR  4                            INVALID_NAME #"},
	{"# ERROR  5                        OVERLAPING_ROOMS #"},
	{"# ERROR  6                               INIT_VISU #"},
	{"# ERROR  7                               LOAD_VISU #"},
	{"# ERROR  8                             RENDER_VISU #"},
	{"# ERROR  9                          CREATE_TEXTURE #"},
	{"# ERROR 10                          WRONG_ARGUMENT #"}
};

void   ft_exit(t_master *mstr, t_errors error)
{
	ft_putendl("\e[36m");
	ft_putendl("\n\n####################################################");
	ft_putendl("####################################################");
	ft_putendl(g_error_message[error]);
	ft_putendl("####################################################");
	ft_putendl("####################################################\n");
	ft_putendl("\e[0m");
    close_program(mstr, VISU_FAILED);
}