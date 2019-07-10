/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:56:12 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/10 11:22:11 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "utils.h"

void	ft_alloc_solutions(t_master *mstr)
{
	int		i;

	i = mstr->nb_solutions;
	if (!(mstr->solutions))
	{
		if (!(mstr->solutions =
			(t_solution **)ft_memalloc(sizeof(t_solution) * i)))
			ft_exit(FAILED_ALLOC_SOLUTIONS);
		i = 0;
		while (i < mstr->nb_solutions)
		{
			if (!(mstr->solutions[i] =
				(t_solution *)ft_memalloc(sizeof(t_solution))))
				ft_exit(FAILED_ALLOC_SOLUTIONS);
			i++;
		}
	}
}

void	ft_add_solution(t_master *mstr, int *path, int len_path)
{
	int		i;
	int		j;

	i = 0;
	ft_alloc_solutions(mstr);
	while (i < mstr->nb_solutions && mstr->solutions[i])
		i++;
	if (i == mstr->nb_solutions)
		ft_exit(MAX_NUMBER_OF_SOLUTIONS_REACHED);
	if (!(mstr->solutions[i]->path))
		if (!(mstr->solutions[i]->path =
			(int *)ft_memalloc(sizeof(int) * len_path)))
			ft_exit(FAILED_ALLOC_SOLUTIONS);
	j = 0;
	mstr->solutions[i]->fixed = len_path;
	while (j < len_path)
	{
		mstr->solutions[i]->path[j] = path[j];
		j++;
	}
}

/*
***		These funtions may not be useful if we just call
***		ft_add_solution when a valid soltion is reached
*/

void	ft_replace_solution(t_master *mstr, int *new_path, int len_path)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < mstr->nb_solutions && mstr->solutions[i])
		i++;
	i--;
	while (j < len_path)
	{
		mstr->solutions[i]->path[j] = new_path[j];
		j++;
	}
	mstr->solutions[i]->fixed = len_path;
}

void	ft_erase_last_solution(t_master *mstr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < mstr->nb_solutions && mstr->solutions[i])
		i++;
	i--;
	free(mstr->solutions[i]->path);
	mstr->solutions[i]->fixed = 0;
}
