/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ants_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:43:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/06 16:10:34 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft/libft.h"
#include "utils.h"
#include "lem_in.h"

void		ft_parser_ants_get(t_master *mstr, char *line)
{
	int		i;

	i = 0;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i])
		ft_exit(ANT_NOT_NB_ONLY, mstr);
	if ((mstr->ants = ft_atoi(line)) <= 0)
		ft_exit(NO_ANTS, mstr);
}
