/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crfernan <crfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:07:41 by crfernan          #+#    #+#             */
/*   Updated: 2019/07/16 17:11:13 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum	e_errors
{
		ERROR_MALLOC, FAIL_ON_READ, INVALID_NAME, INIT_SDL, CREATE_SDL, LOAD_BMP
}				t_errors;

#endif