/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:46:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 12:30:42 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     main(int ac, char **av)
{
    t_master    *mstr;

    if (!(mstr = (t_master*)ft_memalloc(sizeof(t_master))))
        ft_exit(ERROR_MALLOC);
    if (parser(mstr) != FALSE && visual(mstr) != FALSE
    && print(mstr, ac, av) != FALSE && close(mstr) != FALSE)
        return (TRUE);
    return (FALSE);
}
