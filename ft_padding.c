/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:49:05 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 19:52:42 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(t_print *tab, unsigned int min_size)
{
	char	padding_char;

	padding_char = ' ';
	if (tab->zero)
		padding_char = '0';
	if (tab->hash)
		min_size += 2;
	while (min_size < tab->width)
	{
		tab->length += ft_putchr(padding_char);
		min_size++;
	}
}

void	ft_number_padding(t_print *tab, unsigned int min_size)
{
	while (min_size < tab->precision)
	{
		tab->length += ft_putchr('0');
		if (tab->width > 0)
			tab->width--;
		min_size++;
	}
}
