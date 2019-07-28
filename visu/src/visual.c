/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:11:18 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/28 14:52:58 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    visual(t_master *mstr)
{
    if (vs_init(mstr) == TRUE
    && vs_load(mstr) == TRUE
    && vs_run(mstr) == TRUE)
        vs_close(mstr);
}
