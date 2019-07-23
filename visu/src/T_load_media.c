/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T_load_media.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:10:59 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 12:59:16 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
# include "key_press.h"

int		load_media_visual(t_master *mstr)
{
    // mstr->gTexture = load_texture_visual(mstr, "srcs_TUTORIAL/texture.png");
    // if (!mstr->gTexture)
    //     return (ft_exit(LOAD_BMP));

    if (!(mstr->foo_texture = (t_texture*)ft_memalloc(sizeof(t_master))))
        return (ft_exit(ERROR_MALLOC));
    if (!(mstr->background_texture = (t_texture*)ft_memalloc(sizeof(t_master))))
        return (ft_exit(ERROR_MALLOC));
    load_texture_from_file(mstr, mstr->foo_texture, "srcs_TUTORIAL/foo.png");
    load_texture_from_file(mstr, mstr->background_texture, "srcs_TUTORIAL/background.png");
    if (!(mstr->foo_texture) || !(mstr->background_texture))
        return (ft_exit(CREATE_TEXTURE));
    return (TRUE);
}
