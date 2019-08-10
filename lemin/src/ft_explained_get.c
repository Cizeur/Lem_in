/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explained_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 09:50:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/09 13:20:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"
#include "lemin_options.h"
#include "output_explained.h"
#include "error.h"
#include <stdlib.h>


static int	ft_check_visu_option(char **argv)
{
	if (!ft_strcmp(*argv, O_VISU)
		|| !ft_strcmp(*argv, O_VISU_FULL)
		|| !ft_strcmp(*argv, O_OUTPUT_DEACT)
		|| !ft_strcmp(*argv, O_OUTPUT_JUST_SOL))
		return(CERTAINLY);
	return (NOPE);
}

int 		ft_explained_get(int argc, char **argv)
{
	int explained;


	if (!(explained = 0) && !argc)
		return (0);
	while (argc--)
	{

		if (!ft_strcmp(*argv, O_OUTPUT_EXPLAINED)
			|| !ft_strcmp(*argv, O_OUTPUT_EXPLAINED_SHORT))
			explained = 1;
		else if (!ft_strcmp(*argv, O_ANT_MOD) && --argc)
			argv++;
		else if (argc && !ft_check_visu_option(argv))
		{
			ft_putstr(O_USAGE1);
			ft_putstr(O_USAGE2);
			exit(1);
		}
		argv++;
	}
	if (!explained)
		return (NOPE);
	ft_putstr("\n----- Welcome on the algo clarifier -----\n\n");
	return (CERTAINLY);
}
