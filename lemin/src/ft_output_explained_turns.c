/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_explained_turns.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:49:41 by cgiron            #+#    #+#             */
/*   Updated: 2019/08/08 18:28:35 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "output.h"
#include "output_explained.h"
#include "libft/libft.h"

void			ft_check_enough_ants(t_master *mstr, int ants)
{
	if (!ants)
		ft_output_putstr(
			"\n\e[33mNOT ENOUGH ANTS FOR ACTIVATION\e[0m\n\n", mstr);
	else if (ants > 0)
	{
		ft_output_putstr("\n\e[33mENOUGH ANTS\e[0m : ", mstr);
		ft_output_putnbr(mstr->ants,mstr);
		ft_output_putstr("\e[33m out of \e[0m", mstr);
		ft_output_putnbr(
			ft_max((mstr->ants - ants + 1), mstr->final_flow + 1), mstr);
		ft_output_putstr("\e[33m REQUIRED \e[0m\n", mstr);
	}
}

void			ft_output_explained_turns(t_master *mstr, int ants, int turns)
{
	if (mstr->output_type != OUTPUT_EXPLAINED_SHORT
		&& mstr->output_type != OUTPUT_EXPLAINED)
		return ;
	ft_check_enough_ants(mstr, ants);
	if (ants == -1 && !mstr->final_flow)
	{
		ft_output_putstr("SOLUTION in : \e[32m", mstr);
		ft_output_putnbr(turns, mstr);
		ft_output_putstr("\e[0m turns\n", mstr);
	}
	else if (ants == -1 && mstr->final_flow && turns > mstr->turn_counter)
	{
		ft_output_putstr("SOLUTION SAVED : \e[32m", mstr);
		ft_output_putnbr(turns + 1, mstr);
		ft_output_putstr("\e[0m TURNS vs \e[32m", mstr);
		ft_output_putnbr(mstr->turn_counter, mstr);
		ft_output_putstr("\e[0m FOR PREVIOUS \e[0m\n", mstr);
	}
	else if (ants == -1 && mstr->final_flow && turns <= mstr->turn_counter)
	{
		ft_output_putstr("SOLUTION TRASHED : \e[32m", mstr);
		ft_output_putnbr(turns, mstr);
		ft_output_putstr("\e[0m TURNS vs \e[32m", mstr);
		ft_output_putnbr(mstr->turn_counter, mstr);
		ft_output_putstr("\e[0m FOR PREVIOUS \e[0m\n", mstr);
	}
	ft_output_buffer_flush(mstr);
}
