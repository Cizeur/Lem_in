/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:46:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/08/06 17:04:52 by crfernan         ###   ########.fr       */
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
	if (parser(mstr) == FALSE)
		return (FALSE);
	if (visual(mstr) == FALSE)
		return (FALSE);
	// if (print(mstr, ac, av) == FALSE)
	// 	return (FALSE);
	if (close_program(mstr) == FALSE)
		return (FALSE);
	return (TRUE);
}
