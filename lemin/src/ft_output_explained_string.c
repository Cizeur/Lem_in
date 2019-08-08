/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_explained_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 15:55:40 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 18:45:01 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output.h"

void		ft_output_explained_string(t_master *mstr, char *str)
{
	if ((mstr->output_type != OUTPUT_EXPLAINED_SHORT
		&& mstr->output_type != OUTPUT_EXPLAINED) || !str)
		return ;
	ft_output_putstr(str, mstr);
}
