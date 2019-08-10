/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 09:50:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 18:57:08 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"
#include "lemin_options.h"
#include "output.h"
#include "error.h"

static int	ft_visu_option_get(t_master *mstr, char **argv)
{
	if (!ft_strcmp(*argv, O_VISU))
		mstr->output_type = OUTPUT_VISU;
	else if (!ft_strcmp(*argv, O_VISU_FULL))
		mstr->output_type = OUTPUT_VISU_FULL;
	else if (!ft_strcmp(*argv, O_OUTPUT_DEACT))
		mstr->output_type = OUTPUT_DEACTIVATED;
	else if (!ft_strcmp(*argv, O_OUTPUT_JUST_SOL))
		mstr->output_type = OUTPUT_JUST_SOLUTION;
	else if (!ft_strcmp(*argv, O_OUTPUT_EXPLAINED))
		mstr->output_type = OUTPUT_EXPLAINED;
	else if (!ft_strcmp(*argv, O_OUTPUT_EXPLAINED_SHORT))
		mstr->output_type = OUTPUT_EXPLAINED_SHORT;
	else
		return (NOPE);
	return (CERTAINLY);
}

void		ft_option_get(t_master *mstr, int argc, char **argv)
{
	if (!argc)
		return ;
	while (argc--)
	{
		if (ft_visu_option_get(mstr, argv))
			;
		else if (!ft_strcmp(*argv, O_ANT_MOD) && argc)
		{
			mstr->ants_nb_modified = CERTAINLY;
			ft_parser_ants_get(mstr, argv[1], 1);
			argv++;
			argc--;
		}
		else
		{
			ft_putstr(O_USAGE1);
			ft_putstr(O_USAGE2);
			ft_exit(INVALID_ARGUMENT, mstr);
		}
		argv++;
	}
}
