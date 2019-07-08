/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:35:44 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/02 11:39:47 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft/libft.h"

int			main(int  argc, char **argv)
{
	t_master *mstr;

	argc--;
	argv++;
	if (!(mstr=(t_master *)ft_memalloc(sizeof(t_master))))
		return(1);
	ft_init_mstr(mstr);
	if (argc != 1)
		printf("nope\n");
	else
	{
		printf("string : \"%s\" and %d\n", argv[0],
		ft_dico_hasher_djb2(argv[0],0, HASH_SIZE));
	}
	parser(mstr);
	return (0);
}
