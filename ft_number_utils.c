/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:54:52 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 19:31:44 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_nb_len_base(unsigned long ptr, unsigned int base)
{
	unsigned int	len;

	if (ptr == 0)
		return (1);
	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / base;
		len++;
	}
	return (len);
}

unsigned int	ft_nbr_len(int nbr)
{
	if (nbr <= -10)
		return (1 + ft_nb_len_base(-(nbr / 10), 10));
	if (nbr < 0)
		return (0 + ft_nb_len_base(-nbr, 10));
	return (ft_nb_len_base(nbr, 10));
}

static int	ft_write_digit(char val, char lower)
{
	if (val >= 10)
		return (ft_putchr((val) + (lower * ('a' - 'A')) + 'A' - 10));
	return (ft_putchr((val) + '0'));
}

void	ft_write_nbr_base(unsigned long ptr, unsigned char base, char lower)
{
	if (ptr >= base)
		ft_write_nbr_base(ptr / base, base, lower);
	ft_write_digit(ptr % base, lower);
}
