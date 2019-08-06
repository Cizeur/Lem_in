/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:46:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 20:10:37 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		main(int ac, char **av)
{
	t_master	*mstr;

	(void)ac;
	(void)av;
	if (!(mstr = (t_master*)ft_memalloc(sizeof(t_master))))
		ft_exit(mstr, ERROR_MALLOC);
	parser(mstr);
	vs_init(mstr);
	vs_load(mstr);
	vs_run(mstr);
	close_program(mstr, VISU_FINISHED);
}

	// if (print(mstr, ac, av) == FALSE)
	// 	return (FALSE);
