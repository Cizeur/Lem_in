/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:07:41 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/29 18:55:10 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum	e_errors
{
	ERROR_MALLOC,
	FAIL_ON_READ,
	INVALID_INPUT,
	INVALID_NAME,
	OVERLAPING_ROOMS,

	INIT_VISU,
	LOAD_VISU,
	RENDER_VISU,

	CREATE_TEXTURE,

	WRONG_ARGUENT
}				t_errors;

#endif
