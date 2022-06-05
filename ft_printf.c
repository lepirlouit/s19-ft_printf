/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:24:19 by                   #+#    #+#             */
/*   Updated: 2022/06/05 11:47:16 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

static int	ft_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	ft_update_tab(t_print *tab, unsigned int content_length)
{
	tab->length += ft_max(tab->width, content_length);
}

int	ft_putchr(int c)
{
	return (write(1, &c, 1));
}

int	ft_put_prefix(char lower)
{
	if (lower)
		return (write(1, "0x", 2));
	return (write(1, "0X", 2));
}

void	ft_padding(t_print *tab, unsigned int min_size)
{
	char padding_char;

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
		tab->width--;
		min_size++;
	}
}

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

unsigned int	ft_nb_len_base(unsigned long int ptr, unsigned int base)
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
		return (2 + ft_nb_len_base(-(nbr / 10), 10));
	if (nbr < 0)
		return (1 + ft_nb_len_base(-nbr, 10));
	return (ft_nb_len_base(nbr, 10));
}

int	write_digit(char val, char lower)
{
	if (val >= 10)
		return (ft_putchr((val) + ( lower * ('a' - 'A'))+'A' - 10));
	return (ft_putchr((val) + '0'));
}

void	write_nbr_base(unsigned long int ptr, unsigned char base, char lower)
{
	if (ptr >= base)
		write_nbr_base(ptr / base, base, lower);
	write_digit(ptr % base, lower);
}

void	write_hex_nbr(unsigned long int ptr, char lower)
{
	return (write_nbr_base(ptr, 16, lower));
}

void	write_nbr(unsigned long int ptr)
{
	return (write_nbr_base(ptr, 10, 0));
}

void	ft_print_ptr(t_print *tab)
{
	void			*ptr;
	unsigned int	length;

	ptr = va_arg(tab->args, void *);
	if (!ptr)
		length = 5;
	else
		length = ft_nb_len_base((unsigned long int) ptr, 16) + 2;
	if (tab->width && !tab->dash)
		ft_padding(tab, length);
	if (!ptr)
		tab->length += write(1, "(nil)", length);
	else
	{
		ft_put_prefix(1);
		ft_number_padding(tab, length - 2);
		write_hex_nbr((unsigned long int) ptr, 1);
		tab->length += length;
	}
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}

void	print_sign(t_print *tab, int nbr)
{
	if (nbr < 0)
		ft_putchr('-');
	else if (tab->plus)
		tab->length += ft_putchr('+');
	else if (tab->space)
		tab->length += ft_putchr(' ');
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
	if (tab->zero)
		print_sign(tab, nbr);
	if (tab->width && !tab->dash)
		ft_padding(tab, length);
	if (!tab->zero)
		print_sign(tab, nbr);
	if (nbr < 0)
	{
		ft_number_padding(tab, length - 1);
		if (nbr <= -10)
			write_nbr(-(nbr / 10));
		write_nbr(-(nbr % 10));
	}
	else if (length)
	{
		ft_number_padding(tab, length);
		write_nbr(nbr);
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
		write_nbr(nbr);
	tab->length += length;
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}

void	ft_print_hex(t_print *tab, char lower)
{
	unsigned long	nbr;
	unsigned int	length;

	nbr = va_arg(tab->args, unsigned int);
	if (nbr == 0 && tab->dot && tab->precision == 0)
		length = 0;
	else
		length = ft_nb_len_base(nbr, 16);
	if (tab->width && !tab->dash)
		ft_padding(tab, ft_max(length, tab->precision));
	if (tab->hash && nbr != 0)
		tab->length += ft_put_prefix(lower);
	ft_number_padding(tab, length);
	if (length)
		write_hex_nbr(nbr, lower);
	tab->length += length;
	if (tab->width && tab->dash)
		ft_padding(tab, length);
}

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->width = 0;
	tab->perc = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->plus = 0;
	tab->length = 0;
	tab->hash = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->space = 0;
	return (tab);
}

//cspdiuxX%
const char	*ft_eval_format(t_print	*tab, const char *format)
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

char	is_format(char c)
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

const char	*ft_eval_format_flags(t_print *tab, const char *format)
{
	tab->dot = 0;
	tab->dash = 0;
	tab->width = 0;
	tab->zero = 0;
	tab->precision = 0;
	tab->plus = 0;
	tab->hash = 0;
	tab->space = 0;
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
		{
			if (tab->dot)
				tab->precision = ft_atoi(format);
			else
				tab->width = ft_atoi(format);
			while (format[1] && ft_isdigit(format[1]))
				format++;
		}
		format++;
	}
	return (ft_eval_format(tab, format));
}

int	ft_printf(const char *format, ...)
{
	t_print	tab;

	ft_initialise_tab(&tab);
	va_start(tab.args, format);
	while (*format)
	{
		if (*format == '%')
			format = ft_eval_format_flags(&tab, format + 1);
		else
			tab.length += ft_putchr(*(format++));
	}
	va_end(tab.args);
	return (tab.length);
}
