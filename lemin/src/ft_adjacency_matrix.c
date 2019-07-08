/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjacency_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:29:07 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/08 17:58:19 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "error.h"

void    ft_alloc_adjancency_matrix(t_master *mstr)
{
    int     i;

    i = 0;
    if (!(mstr->adjacency_mtx = (int**)ft_memalloc(sizeof(int*) * mstr->nodes_nb)))
        ft_exit(ADJACENCY_MTX);
    while (i < mstr->nodes_nb)
    {
        if (!(mstr->adjacency_mtx[i] = (int*)ft_memalloc(sizeof(int) * (mstr->nodes_nb + 3))))
            ft_exit(ADJACENCY_MTX);
        i++;
    }
}

void    ft_put_line_index_to_adjancency_matrix(t_master *mstr, int line_index, int node_number)
{
    if (!(mstr->adjacency_mtx[node_number][mstr->nodes_nb]))
        mstr->adjacency_mtx[node_number][mstr->nodes_nb] = line_index;
    else if (mstr->adjacency_mtx[node_number][mstr->nodes_nb] != line_index)
        ft_exit(ADJACENCY_MTX);
}

void    ft_calculate_start_end_adjancency_matrix(t_master *mstr)
{
    int     i;
    int     j;

    i = -1;
    while (++i < mstr->nodes_nb)
    {
        j = 0;
        while (++j < mstr->nodes_nb && mstr->adjacency_mtx[i][j] == 0)
            j++;
        if (!(j == mstr->nodes_nb))
        {
            mstr->adjacency_mtx[i][mstr->nodes_nb + 1] = j;
            j = mstr->nodes_nb - 1;
            while (j >= 0 && mstr->adjacency_mtx[i][j] == 0)
                j--;
            mstr->adjacency_mtx[i][mstr->nodes_nb + 2] = j;
        }
    }
}

void    ft_put_pipe_in_adjancency_matrix(t_master *mstr, int node1, int node2)
{
        mstr->adjacency_mtx[node1][node2] = 1;
        mstr->adjacency_mtx[node2][node1] = 1;
}

void    ft_adjacency_matrix(t_master *mstr)
{
    int     i;

    i = 0;
    if (!(mstr->adjacency_mtx))
        ft_alloc_adjancency_matrix(mstr);
    
}