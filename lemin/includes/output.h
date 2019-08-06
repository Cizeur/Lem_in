/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 10:58:52 by cesar             #+#    #+#             */
/*   Updated: 2019/08/06 11:18:00 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

/*
** OUTPUT_TYPES
*/

# define DEFAULT_OUTPUT 1
# define OUTPUT_STANDARD 0
# define OUTPUT_VISU 1
# define OUTPUT_DEACTIVATED 2

/*
** VISU_STRING
*/

# define SO_NODE_NB "# number of nodes            = "
# define SO_PIPE_NB "# number of pipes            = "
# define SO_INACT_PIPE_NB "# number of inactive pipes   = "
# define SO_MVMT_NB "# number of movements        = "
# define SO_INACT_PIPE_MK "#inactive\n"
# define SO_ACT_PIPE_MK "#active\n"

#endif
