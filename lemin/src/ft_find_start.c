/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:48:09 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/08 13:42:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_find_name_start(char *name)
{
	if (!name || !*name)
		return (0);
	while (*name && ft_is_whitespace(*name))
		name++;
	return (name);
}

