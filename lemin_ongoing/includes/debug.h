/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:55:55 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/02 16:18:02 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H


#define DEBUG_PRINT_PATH_LEN 0
#define DEBUG_PRINT_MATRIX 0
#define DEBUG_TRUNC_MATRIX 0
#define DEBUG_PRINT_TEST_RESULT 0
#define DEBUG_PRINT_STORAGE 0

#include "lem_in.h"
void    ft_print_matrix(t_master *mstr, int activation);
void 	ft_debug_storage_print(t_storage *storage, int ind_max, int activation);
void    ft_print_test(t_master *mstr, int activation);
#endif
