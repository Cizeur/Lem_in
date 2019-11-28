/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_path_splitter_init_stacks.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:26:29 by cgiron            #+#    #+#             */
/*   Updated: 2019/11/28 15:10:37 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"
#include "libft/libft.h"

void			ft_init_stack(t_master *mstr, int start_node)
{
	int i;

	i = -1;
	while (++i < mstr->nodes)
		mstr->cells[i].last_visit = 0;
	ft_bzero((void *)mstr->stack, sizeof(mstr->stack));
	mstr->stack[0].cell = start_node;
	mstr->stack[0].visite_type = V_START;
	mstr->cells[start_node].last_visit = V_START;
}
