/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_ants_get.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:43:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/08 14:10:33 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "utils.h"
#include "lem_in.h"

char		*ft_parser_ants_get(t_master *mstr)
{
	char *line;
	int i;

	if (get_next_line(0, &line) <= 0)
		ft_exit(EMPTY_PIPE);
	i = 0;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && ft_is_whitespace(line[i]))
		i++;
	if (line[i])
		ft_exit(ANT_NOT_NB_ONLY);
	if ((mstr->ants_nb = ft_atoi(line)) <= 0)
		ft_exit(NO_ANTS);
	return(line);
}
