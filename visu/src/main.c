/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:46:26 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/30 22:04:01 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int     main(int ac, char **av)
{
    t_master    *mstr;

    if (!(mstr = (t_master*)ft_memalloc(sizeof(t_master))))
        ft_exit(mstr, ERROR_MALLOC);
    if (parser(mstr) == FALSE)
        return (FALSE);
    if (visual(mstr) == FALSE)
        return (FALSE);
    if (print(mstr, ac, av) == FALSE)
        return (FALSE);
    if (close_program(mstr) == FALSE)
        return (FALSE);
    return (TRUE);
}
