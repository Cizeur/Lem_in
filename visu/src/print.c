/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:07:46 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 13:00:34 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visu.h"

void    ft_print_parameters(t_master *mstr)
{
    printf("NB ANTS           = %d\n", mstr->nb_ants);
    printf("NB NODES          = %d\n", mstr->nb_nodes);
    printf("NB PIPES          = %d\n", mstr->nb_pipes);
    printf("NB INACTIVE PIPES = %d\n", mstr->nb_inactive);
    printf("NB MOVEMENTS      = %d\n", mstr->nb_movements);
    printf("START INDEX       = %d\n", mstr->start_index);
    printf("START NAME        = %s\n", mstr->start_name);
    printf("END INDEX         = %d\n", mstr->end_index);
    printf("END NAME          = %s\n", mstr->end_name);
    printf("POS MAX X         = %d\n", mstr->max_x);
    printf("POS MIN X         = %d\n", mstr->min_x);
    printf("POS MAX Y         = %d\n", mstr->max_y);
    printf("POS MIN Y         = %d\n\n\n", mstr->min_y);
    
}

void    ft_print_nodes(t_master *mstr)
{
    int     i;
    int     j;

    i = 0;
    while (i < mstr->nb_nodes)
    {
        j = 0;
		printf("NODE INDEX        = %d\n", mstr->nodes_array[i]->node_index);
		printf("NODE NAME         = %s\n", mstr->nodes_array[i]->name);
		printf("NODE NAME LEN     = %d\n", mstr->nodes_array[i]->len_name);
		printf("NODE X POS        = %d\n", mstr->nodes_array[i]->x);
		printf("NODE Y POS        = %d\n", mstr->nodes_array[i]->y);
		printf("NODE NB PIPES     = %d\n", mstr->nodes_array[i]->nb_pipes);
		printf("NODE PIPES        =\n");
        while (j < mstr->nodes_array[i]->nb_pipes)
        {
            printf("NODE Pipe [%d]     : %d\n", j, mstr->nodes_array[i]->pipes[j]);
            j++;
        }
		printf("NODE FLAG         = %d\n\n", mstr->nodes_array[i]->flag);
        i++;
    }
}

void    ft_print_pipes(t_master *mstr)
{
    int     i;

    i = 0;
    while (i < mstr->nb_pipes)
    {
        printf("PIPE INDEX       = %d\n", mstr->pipes_array[i]->pipe_index);
		printf("PIPE ACTIVE      = %d\n", mstr->pipes_array[i]->active);
		printf("NODE INDEX 1     = %d\n", mstr->pipes_array[i]->node1_index);
		printf("NODE NAME  1     = %s\n", mstr->pipes_array[i]->node1_name);
		printf("NODE INDEX 2     = %d\n", mstr->pipes_array[i]->node2_index);
		printf("NODE NAME  2     = %s\n\n", mstr->pipes_array[i]->node2_name);
        i++;
    }
}


void    ft_print_moves(t_master *mstr)
{
    int     i;

    i = 0;
    (void)mstr;
    // printf("mstr->current_move = %d\n", mstr->current_move);
    // printf("mstr->moves_array[]->current_index = %d\n", mstr->moves_array[mstr->current_move]->current_index);
    // printf("mstr->moves_array[]->ant_index = %d\n", mstr->moves_array[mstr->current_move]->ant_index);
    // printf("mstr->moves_array[]->node1_index = %d\n", mstr->moves_array[mstr->current_move]->node1_index);
    // printf("mstr->moves_array[]->node2_index = %d\n", mstr->moves_array[mstr->current_move]->node2_index);
}

int    print(t_master *mstr, int ac, char **av)
{
    int     i;

    i = 1;
    while (i < ac)
    {
        if (ft_str_cmp(av[i], "-dParameters") == TRUE)
            ft_print_parameters(mstr);
        if (ft_str_cmp(av[i], "-dNodes") == TRUE)
            ft_print_nodes(mstr);
        if (ft_str_cmp(av[i], "-dPipes") == TRUE)
            ft_print_pipes(mstr);
        if (ft_str_cmp(av[i], "-dMoves") == TRUE)
            ft_print_moves(mstr);
        if (ft_str_cmp(av[i], "-dAll") == TRUE)
        {
            ft_print_parameters(mstr);
            ft_print_nodes(mstr);
            ft_print_pipes(mstr);
            ft_print_moves(mstr);
        }
        else
            return (ft_exit(WRONG_ARGUENT));
        return (TRUE);
    }
}