/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:06:28 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 17:06:57 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->width && !tab->dash)
		ft_padding(tab, 1);
	tab->length += ft_putchr(a);
	if (tab->width && tab->dash)
		ft_padding(tab, 1);
}

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		length;

	str = va_arg(tab->args, char *);
	if (!str)
	{
		if (tab->dot && tab->precision < 6)
			length = 0;
		else
			length = 6;
	}
	else if (tab->dot)
		length = ft_min(ft_strlen(str), tab->precision);
	else
		length = ft_strlen(str);
	if (tab->width && !tab->dash)
		ft_padding(tab, length);
	if (!str)
		tab->length += write(1, "(null)", length);
	else
		tab->length += write(1, str, length);
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}
