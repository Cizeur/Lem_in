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

int 		ft_explained_get(int argc, char **argv)
{
	if (!argc)
		return (0);
	while (argc--)
	{
		if (!ft_strcmp(*argv, O_OUTPUT_EXPLAINED)
			|| !ft_strcmp(*argv, O_OUTPUT_EXPLAINED_SHORT))
		{
			ft_putstr("\n----- Welcome on the algo clarifier -----\n\n");
			return (CERTAINLY);
		}
		argv++;
	}
	return (NOPE);
}
