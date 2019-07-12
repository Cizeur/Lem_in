/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:12:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/12 12:06:11 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_is_not_comment_2(char *line)
{
	if (line[0] != '#')
		return (1);
	return (0);
}

void	ft_get_pipes(t_master *mstr, char *line)
{
    // printf("ft_get_pipes : \"%s\"\n", line);
    if (ft_is_not_comment_2(line) == 1)
    {
        mstr->current_pipe++;
    }
    (void)line;
}