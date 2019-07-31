/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:11:18 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/31 14:24:04 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    visual(t_master *mstr)
{
    if (vs_init(mstr) == FALSE)
        return (FALSE);
    if (vs_load(mstr) == FALSE)
        return (FALSE);
    if (vs_run(mstr) == FALSE)
        return (FALSE);
    return(TRUE);
}
