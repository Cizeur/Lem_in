/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dico_hasher_djb2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:29:04 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/03 14:05:49 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_dico_hasher_djb2(char *str, char *end, int amplitude)
{
	long int hash;

	hash = 5381;
	if (!str)
		return (0);
	while (!end ? *str : str != end)
		hash = ((hash << 5) ^ (*str++));
	hash = hash < 0 ? -hash : hash;
	return ((int)(hash % amplitude));
}
