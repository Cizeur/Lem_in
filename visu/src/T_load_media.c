/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_load_media.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:10:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/22 15:47:11 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
# include "key_press.h"

int		load_media_visual(t_master *mstr)
{
    mstr->gTexture = load_texture_visual(mstr, "srcs_TUTORIAL/texture.png");
    if (!mstr->gTexture)
        return (ft_exit(LOAD_BMP));
    return (TRUE);
}

// int		load_media_visual(t_master *mstr)
// {
//     mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] =
//         load_surface_visual(mstr, "srcs_TUTORIAL/press.bmp");
//     mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] =
//         load_surface_visual(mstr, "srcs_TUTORIAL/up.bmp");
//     mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] =
//         load_surface_visual(mstr, "srcs_TUTORIAL/down.bmp");
//     mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] =
//         load_surface_visual(mstr, "srcs_TUTORIAL/left.bmp");
//     mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] =
//         load_surface_visual(mstr, "srcs_TUTORIAL/right.bmp");
//     mstr->gStretchedSurface = load_surface_visual(mstr, "srcs_TUTORIAL/stretch.bmp");
//     if (!mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT]
//         || !mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_UP]
//         || !mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN]
//         || !mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT]
//         || !mstr->gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT]
//         || !mstr->gStretchedSurface)
//         return (ft_exit(LOAD_BMP));
//     return (TRUE);
// }
