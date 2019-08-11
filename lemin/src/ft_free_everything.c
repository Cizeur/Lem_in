/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_everything.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:56:28 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/11 15:46:02 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft/libft.h"

static void	ft_free_storage(t_master *mstr)
{
	t_storage	*storage;
	t_storage	*stock;
	int			i;

	storage = mstr->storage_start;
	while ((i = -1) && storage)
	{
		stock = storage->next;
		while (++i < BATCH_MALLOC_SIZE && storage)
		{
			if (storage->entry[i].line)
				free(storage->entry[i].line);
			ft_bzero(&(storage->entry[i]), sizeof(t_line_info));
		}
		free(storage);
		storage = stock;
	}
}

static void	ft_free_dico(t_master *mstr)
{
	t_hash_dico *dico;
	t_bucket	*bucket;
	t_bucket	*temp;
	int			i;

	i = -1;
	dico = mstr->dico;
	while (++i < HASH_SIZE && dico)
	{
		temp = &dico->dico_list[i];
		if (temp->next)
		{
			temp = temp->next;
			while (temp)
			{
				bucket = temp->next;
				temp->line_index = 0;
				free(temp);
				temp = bucket;
			}
		}
	}
	if (dico)
		free(dico);
	dico = 0;
}

static void	ft_free_matrix(t_master *mstr)
{
	int **mtx;
	int i;

	i = -1;
	mtx = mstr->adjacency_mtx;
	if (mstr->adjacency_mtx)
	{
		while (++i < mstr->nodes)
		{
			if (mtx[i])
				free(mtx[i]);
			mtx[i] = 0;
		}
		free(mstr->adjacency_mtx);
		mstr->adjacency_mtx = 0;
	}
}

static void	ft_free_paths(t_master *mstr)
{
	if (mstr->node_parents)
		free(mstr->node_parents);
	if (mstr->node_path)
		free(mstr->node_path);
	if (mstr->node_queue)
		free(mstr->node_queue);
	if (mstr->stored_solution)
		free(mstr->stored_solution);
	mstr->node_parents = 0;
	mstr->node_path = 0;
	mstr->stored_solution = 0;
	mstr->node_queue = 0;
}

void		ft_free_everything(t_master *mstr)
{
	if (mstr)
	{
		if (mstr->adjacency_mtx)
			ft_free_matrix(mstr);
		if (mstr->storage_start)
			ft_free_storage(mstr);
		if (mstr->dico)
			ft_free_dico(mstr);
		ft_free_paths(mstr);
		ft_bzero(mstr, sizeof(t_master));
		free(mstr);
	}
	mstr = 0;
}
