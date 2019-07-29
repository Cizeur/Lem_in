/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:42:24 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 18:26:41 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft/get_next_line.h"

int     parameters_visual(t_master *mstr)
{
    // int     ret;
    // char    *line;

    // ft_putendl("Please introduce the number of your coalition:");
    // ft_putendl("1. The Assembly");
    // ft_putendl("2. The Order");
    // ft_putendl("3. The Alliance");
    // ft_putendl("4. The Federation");
    // if ((ret = get_next_line(0, &line)) > 0)
    // {
    //     if (ft_str_cmp(line, "1\n") == TRUE)
    //         mstr->background_path = ft_strdup("resources_visual/assembly.jpg");
    //     else if (ft_str_cmp(line, "2\n") == TRUE)
    //         mstr->background_path = ft_strdup("resources_visual/order.jpg");
    //     else if (ft_str_cmp(line, "3\n") == TRUE)
    //         mstr->background_path = ft_strdup("resources_visual/alliance.jpg");
    //     else if (ft_str_cmp(line, "4\n") == TRUE)
    //         mstr->background_path = ft_strdup("resources_visual/federation.jpg");
    //     else
    //         return (ft_exit(INVALID_INPUT));
    // }
    // if (ret == FALSE)
    //     return (ft_exit(FAIL_ON_READ));
    mstr->background_path = ft_strdup("resources_visual/assembly.jpg");
    return (TRUE);
}