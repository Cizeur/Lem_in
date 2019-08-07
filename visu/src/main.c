/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:46:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/07 15:31:48 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		main(void)
{
	t_master	*mstr;

	if (!(mstr = (t_master*)ft_memalloc(sizeof(t_master))))
		ft_exit(mstr, ERROR_MALLOC);
	parser(mstr);
	vs_init(mstr);
	vs_load(mstr);
	vs_run(mstr);
	close_program(mstr, VISU_FINISHED);
	return (0);
}

