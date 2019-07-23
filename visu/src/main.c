/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:46:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/23 17:17:12 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     main(void)
{
    t_master    *mstr;

    if (!(mstr = (t_master*)ft_memalloc(sizeof(t_master))))
        ft_exit(ERROR_MALLOC);
    if (parser(mstr) == -1)
         return(FALSE);
    visual(mstr);
    return (0);
}
