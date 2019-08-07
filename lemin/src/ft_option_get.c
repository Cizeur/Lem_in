/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 09:50:05 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/07 11:16:23 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"
#include "lemin_options.h"
#include "output.h"

void		ft_option_get(t_master *mstr, int argc, char **argv)
{
	if (!argc)
		return ;
	while (argc--)
	{
		if(!ft_strcmp(*argv, O_VISU))
			mstr->output_type = OUTPUT_VISU;
		else if(!ft_strcmp(*argv, O_VISU_FULL))
			mstr->output_type = OUTPUT_VISU_FULL;
		else if(!ft_strcmp(*argv, O_OUTPUT_DEACT))
			mstr->output_type = OUTPUT_DEACTIVATED;
		else if(!ft_strcmp(*argv, O_OUTPUT_JUST_SOL))
			mstr->output_type = OUTPUT_JUST_SOLUTION;
		else if(!ft_strcmp(*argv, O_ANT_MOD) && argc)
		{
			mstr->ants_nb_modified = CERTAINLY;
			ft_parser_ants_get(mstr, argv[1], 1);
			argv++;
			argc--;
		}
		else
		{
			ft_putstr(O_USAGE);
			ft_exit(INVALID_ARGUMENT, mstr);
		}
		argv++;
	}
}
