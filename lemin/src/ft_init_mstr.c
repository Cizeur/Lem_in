/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:24:57 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/06 10:59:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output.h"
#include "error.h"
#include "libft/libft.h"

void		ft_init_mstr(t_master *mstr)
{
	mstr->output_type = DEFAULT_OUTPUT;
	mstr->piping = NOPE;
	mstr->graph_explored = NOPE;
	mstr->command_line = COM_DEFAULT;
	if (!(mstr->dico = (t_hash_dico *)ft_memalloc(sizeof(t_hash_dico))))
		ft_exit(FAIL_MALLOC_DIC, mstr);
	if (!(mstr->storage = (t_storage *)ft_memalloc(sizeof(t_storage))))
		ft_exit(FAIL_MALLOC_DIC, mstr);
}
