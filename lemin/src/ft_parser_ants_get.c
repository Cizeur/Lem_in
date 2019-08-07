/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ants_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:43:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/07 10:33:56 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft/libft.h"
#include "utils.h"
#include "lem_in.h"

void		ft_parser_ants_get(t_master *mstr, char *line, int activation)
{
	int		i;

	i = 0;
	if (!line)
		ft_exit(NO_ANTS, mstr);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i])
		ft_exit(ANT_NOT_NB_ONLY, mstr);
	if (!activation)
		return;
	if ((mstr->ants = ft_atoi(line)) <= 0)
		ft_exit(NO_ANTS, mstr);
}
