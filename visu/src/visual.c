/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:11:18 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 19:08:14 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    visual(t_master *mstr)
{
    if (vs_init(mstr) == TRUE
    && vs_load(mstr) == TRUE
    && vs_run(mstr) == TRUE)
        return (TRUE);
    return (FALSE);
}
