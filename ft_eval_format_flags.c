/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:39:46 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 16:42:03 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_flags(t_print *tab)
{
	tab->dot = 0;
	tab->dash = 0;
	tab->width = 0;
	tab->zero = 0;
	tab->precision = 0;
	tab->plus = 0;
	tab->hash = 0;
	tab->space = 0;
}

static const char	*ft_eval_format(t_print	*tab, const char *format)
{
	if (*format == '%')
		tab->length += ft_putchr('%');
	else if (*format == 'c')
		ft_print_char(tab);
	else if (*format == 's')
		ft_print_str(tab);
	else if (*format == 'p')
		ft_print_ptr(tab);
	else if (*format == 'd' || *format == 'i')
		ft_print_integer(tab);
	else if (*format == 'u')
		ft_print_unsigned_integer(tab);
	else if (*format == 'x')
		ft_print_hex(tab, 1);
	else if (*format == 'X')
		ft_print_hex(tab, 0);
	return (format + 1);
}

static char	is_format(char c)
{
	char	*formats;

	formats = "cspdiuxX%";
	while (*formats)
	{
		if (*formats == c)
			return (1);
		formats++;
	}
	return (0);
}

static const char	*ft_handle_digit_flag(t_print *tab, const char *format)
{
	if (tab->dot)
		tab->precision = ft_atoi(format);
	else
		tab->width = ft_atoi(format);
	while (format[1] && ft_isdigit(format[1]))
		format++;
	return (format);
}

const char	*ft_eval_format_flags(t_print *tab, const char *format)
{
	ft_init_flags(tab);
	while (*format && !is_format(*format))
	{
		if (*format == '.')
			tab->dot = 1;
		else if (*format == '-')
			tab->dash = 1;
		else if (*format == '+')
			tab->plus = 1;
		else if (*format == '#')
			tab->hash = 1;
		else if (*format == ' ')
			tab->space = 1;
		else if (*format == '0' && !tab->dot)
			tab->zero = 1;
		else if (ft_isdigit(*format))
			format = ft_handle_digit_flag(tab, format);
		format++;
	}
	return (ft_eval_format(tab, format));
}
