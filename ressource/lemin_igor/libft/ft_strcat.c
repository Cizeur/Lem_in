/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <ibaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:11:12 by igarbuz           #+#    #+#             */
/*   Updated: 2019/06/27 11:44:10 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char	*tmp;

	tmp = s1;
	while (*tmp)
		tmp++;
	while (*s2)
	{
		*tmp = *s2;
		s2++;
		tmp++;
	}
	*tmp = '\0';
	return (s1);
}
