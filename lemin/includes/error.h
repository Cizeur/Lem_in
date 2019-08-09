/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:24:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/09 10:49:08 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "lem_in.h"

# define S_ERROR_OUTPUT "ERROR\n"

typedef enum	e_errors
{
	STANDARD,
	EMPTY_FILE,
	DOUBLE_START,
	DOUBLE_END,
	WRONG_POSITION_FOR_START_END,
	INVALID_LINE,
	FAIL_REPEAT_ENTRY,
	DASH_IN_NAME,
	NO_ANTS,
	ANT_NOT_NB_ONLY,
	NON_EXISTING_ROOM,
	START_OR_END_MISSING,
	NOT_CONNECTED,
	DEAD_END_ON_SOLUTION,
	FAILED_DICO_ENTRY_CREATION,
	FAIL_MALLOC_STORAGE,
	FAIL_MALLOC_DIC,
	FAIL_ON_READ,
	FAIL_LINE_GRAB,
	ADJACENCY_MTX,
	NODE_STACK_MTX,
	ERROR_STORAGE,
	FAIL_MALLOC_MSTR,
	INVALID_ARGUMENT
}				t_errors;

void			ft_exit(t_errors error, t_master *mstr);

#endif
