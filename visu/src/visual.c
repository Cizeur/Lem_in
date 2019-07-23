/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:11:18 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 16:57:57 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void    visual(t_master *mstr)
{
    if (vs_init(mstr) == TRUE)
    {
        if (vs_load(mstr) == TRUE)
            vs_run(mstr);
        vs_close(mstr);
    }
}

// void    visual(t_master *mstr)
// {
//     if (init_visual(mstr) == TRUE)
//     {
//         if (load_media_visual(mstr) == TRUE)
//             run_visual(mstr);
//         close_visual(mstr);
//     }
// }