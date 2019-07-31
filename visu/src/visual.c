/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:11:18 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/30 19:11:34 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int    visual(t_master *mstr)
{
    if (vs_init(mstr) == TRUE)
    {
        if (vs_load(mstr) == TRUE)
        {
            if (vs_run(mstr) == TRUE)
                return (TRUE);
            else
                return (FALSE);
        }
        else
            return (FALSE);
        return(TRUE);
    }
    return (FALSE);
}
