/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:30:00 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/09 15:24:20 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_str_isdigit(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		ft_str_cmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (TRUE);
	return (FALSE);
}

int		ft_get_index_node(t_master *mstr, char *name)
{
	int		i;

	i = 0;
	while (i < mstr->nb_nodes)
	{
		if (ft_str_cmp(mstr->nodes_array[i]->name, name) == TRUE)
			return (i);
		i++;
	}
	return (FALSE);
}

int		ft_istrstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return (FALSE);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] != '\0'
				&& needle[j] == haystack[i + j])
			j++;
		if (needle[j] == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
