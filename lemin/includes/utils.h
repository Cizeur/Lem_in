/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:03:51 by cgiron            #+#    #+#             */
/*   Updated: 2019/07/10 07:50:11 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				ft_is_whitespace(int c);
char			*ft_find_name_start(char *name);
char			*ft_find_name_end(char *name);
void			ft_intset(int *tab, int size, int nb);

#endif
