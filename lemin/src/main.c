/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/30 13:27:49 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "stdlib.h"
#include "libft/libft.h"

int			main(int  argc, char **argv)
{
	t_master *mstr;

	argc--;
	argv++;
	if (!(mstr=(t_master *)ft_memalloc(sizeof(t_master))))
		ft_exit(FAIL_MALLOC_MSTR);
	ft_init_mstr(mstr);
	parser(mstr);
	solver(mstr);
	output(mstr);
	return(0);
}
