/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:48:09 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/05 12:09:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*ft_find_name_end(char *name)
{
	if (!name || !*name)
		return (0);
	while (*name && !ft_is_whitespace(*name))
		name++;
	return (name);
}
