/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:07:46 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/11 16:35:29 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "visu.h"

void    ft_print_parameters(t_master *mstr)
{
    printf("NB ANTS             = %d\n", mstr->nb_ants);
    printf("NB NODES            = %d\n", mstr->nb_nodes);
    printf("NB PIPES            = %d\n", mstr->nb_pipes);
    printf("NB INACTIVE PIPES   = %d\n", mstr->nb_inactive);
    printf("NB MOVEMENTS        = %d\n", mstr->nb_movements);
    printf("START INDEX         = %d\n", mstr->start_index);
    printf("END INDEX           = %d\n", mstr->end_index);
}