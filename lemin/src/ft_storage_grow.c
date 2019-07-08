/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grow_storage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:20:58 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/05 10:20:59 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lem_in.h"
#include "error.h"

void		ft_storage_grow(t_master *mstr)
{
//	printf("buffer %p \n" ,mstr->storage );
	if (!mstr)
		return;
	mstr->storage->next = (t_storage *)ft_memalloc(sizeof(t_storage));
	mstr->storage = mstr->storage->next;
	if (!mstr->storage)
		ft_exit(FAIL_MALLOC_STORAGE);
}
