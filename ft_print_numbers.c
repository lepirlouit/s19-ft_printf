/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:07:41 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 17:12:19 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(t_print *tab)
{
	void			*ptr;
	unsigned int	length;

	ptr = va_arg(tab->args, void *);
	if (ptr == 0 && tab->dot && tab->precision == 0)
		length = 0;
	else
		length = ft_nb_len_base((unsigned long) ptr, 16);
	tab->hash = 1;
	if (tab->width && !tab->dash)
		ft_padding(tab, ft_max(length, tab->precision));
	tab->length += ft_put_prefix(1);
	ft_number_padding(tab, length);
	if (length)
		write_nbr_base((unsigned long) ptr, 16, 1);
	tab->length += length;
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}

void	print_sign(t_print *tab, int nbr, int padding_length)
{
	if (!tab->zero && tab->width && !tab->dash)
		ft_padding(tab, padding_length);
	if (nbr < 0)
		ft_putchr('-');
	else if (tab->plus)
		tab->length += ft_putchr('+');
	else if (tab->space)
		tab->length += ft_putchr(' ');
	if (tab->zero && tab->width && !tab->dash)
		ft_padding(tab, padding_length);
}

void	ft_print_integer(t_print *tab)
{
	int				nbr;
	unsigned int	length;

	nbr = va_arg(tab->args, int);
	if (nbr == 0 && tab->dot && tab->precision == 0)
		length = 0;
	else
		length = ft_nbr_len(nbr);
	print_sign(tab, nbr, length);
	if (nbr < 0)
	{
		ft_number_padding(tab, length - 1);
		if (nbr <= -10)
			write_nbr_base(-(nbr / 10), 10, 0);
		write_nbr_base(-(nbr % 10), 10, 0);
	}
	else if (length)
	{
		ft_number_padding(tab, length);
		write_nbr_base(nbr, 10, 0);
	}
	tab->length += length;
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}

void	ft_print_unsigned_integer(t_print *tab)
{
	unsigned int	nbr;
	unsigned int	length;

	nbr = va_arg(tab->args, unsigned int);
	if (nbr == 0 && tab->dot && tab->precision == 0)
		length = 0;
	else
		length = ft_nb_len_base(nbr, 10);
	if (tab->width && !tab->dash)
		ft_padding(tab, ft_max(length, tab->precision));
	ft_number_padding(tab, length);
	if (length)
		write_nbr_base(nbr, 10, 0);
	tab->length += length;
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}

void	ft_print_hex(t_print *tab, char lower)
{
	unsigned int	nbr;
	unsigned int	length;

	nbr = va_arg(tab->args, unsigned int);
	if (nbr == 0 && tab->dot && tab->precision == 0)
	{
		tab->hash = 0;
		length = 0;
	}
	else
		length = ft_nb_len_base(nbr, 16);
	if (tab->width && !tab->dash)
		ft_padding(tab, ft_max(length, tab->precision));
	if (tab->hash && nbr != 0)
		tab->length += ft_put_prefix(lower);
	ft_number_padding(tab, length);
	if (length)
		write_nbr_base(nbr, 16, lower);
	tab->length += length;
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}
