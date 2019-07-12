/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:24:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/12 14:41:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum	e_errors
{
		STANDARD, NAME_EMPTY_OR_SPACE,
		ALLREADY_IN_DIC,
		FAIL_MALLOC_DIC,
		FAIL_REPEAT_ENTRY,
		FAILED_DICO_ENTRY_CREATION,
		NO_ANTS,
		ANT_NOT_NB_ONLY,
		EMPTY_PIPE,
		FAIL_MALLOC_STORAGE,
		FAIL_ON_READ,
		FAIL_LINE_GRAB,
		ADJACENCY_MTX,
		ERROR_STORAGE,
		NOT_CONNECTED,
		NODE_STACK_MTX,
		FAILED_ALLOC_SOLUTIONS,
		MAX_NUMBER_OF_SOLUTIONS_REACHED,
		START_OR_END_MISSING,
		WRONG_POSITION_FOR_START_END,
}				t_errors;

#endif
