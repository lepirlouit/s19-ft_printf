/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:24:19 by                   #+#    #+#             */
/*   Updated: 2022/05/27 23:43:24 by bde-biol         ###   ########.fr       */
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

// void	ft_right_cs(t_print *tab, int tbd){
// 	unsigned int i;

// 	(void)tbd;
// 	i = 0;
// 	while (i < tab->width - 1)
// 		ft_putchar_fd(' ', 1);
// }
// void	ft_left_cs(t_print *tab, int tbd){
// 	unsigned int i;

// 	(void)tbd;
// 	i = 0;
// 	while (i < tab->width - 1)
// 		ft_putchar_fd(' ', 1);

// }
void	ft_padding(t_print *tab, char padding_char, unsigned int min_size)
{
	while (min_size < tab->width)
	{
		tab->length += write(1, &padding_char, 1);
		min_size++;
	}
}

void	ft_number_padding(t_print *tab, unsigned int min_size)
{
	while (min_size < tab->precision)
	{
		tab->length += write(1, "0", 1);
		tab->width--;
		min_size++;
	}
}

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->width && !tab->dash)
		ft_padding(tab, ' ', 1);
	tab->length += write(1, &a, 1);
	if (tab->width && tab->dash)
		ft_padding(tab, ' ', 1);
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
		ft_padding(tab, ' ', length);
	if (!str)
		tab->length += write(1, "(null)", length);
	else
		tab->length += write(1, str, length);
	if (tab->width && tab->dash)
		ft_padding(tab, ' ', length);
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
	if (nbr < -10)
		return (2 + ft_nb_len_base(-(nbr / 10), 10));
	if (nbr < -0)
		return (1 + ft_nb_len_base(-nbr, 10));
	return (ft_nb_len_base(nbr, 10));
}

unsigned int	ft_ptr_len(unsigned long int ptr)
{
	return (ft_nb_len_base(ptr, 16));
}

int	write_hex_lower(char val)
{
	if (val >= 10)
		return (ft_putchr((val) + 'a' - 10));
	return (ft_putchr((val) + '0'));
}

void	write_nbr_base(unsigned long int ptr, unsigned char base)
{
	if (ptr > base)
		write_nbr_base(ptr / base, base);
	write_hex_lower(ptr % base);
}

void	write_ptr(unsigned long int ptr)
{
	return (write_nbr_base(ptr, 16));
}

void	write_nbr(unsigned long int ptr)
{
	return (write_nbr_base(ptr, 10));
}

void	ft_print_ptr(t_print *tab)
{
	void			*ptr;
	unsigned int	length;

	ptr = va_arg(tab->args, void *);
	if (!ptr)
		length = 5;
	else
		length = ft_ptr_len((unsigned long int) ptr) + 2;
	if (tab->width && !tab->dash)
		ft_padding(tab, ' ', length);
	if (!ptr)
		tab->length += write(1, "(nil)", length);
	else
	{
		write(1, "0x", 2);
		write_ptr((unsigned long int) ptr);
		tab->length += length;
	}
	if (tab->width && tab->dash)
		ft_padding(tab, ' ', length);
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
	if (tab->width && !tab->dash)
		ft_padding(tab, ' ', ft_max(length, tab->precision));
	ft_number_padding(tab, length);
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr < -10)
			write_nbr(-(nbr / 10));
		write_nbr(-(nbr % 10));
	}
	else if (length)
		write_nbr(nbr);
	tab->length += length;
	if (tab->width && tab->dash)
		ft_padding(tab, ' ', length);
}

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->width = 0;
	tab->perc = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->sign = 0;
	tab->length = 0;
	tab->is_zero = 0;
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
		ft_print_integer(tab);	// ft_print_ptr(tab);
	// ft_print_ptr(tab);
	else if (*format == 'u')
		;
	// ft_print_ptr(tab);
	else if (*format == 'x')
		;
	// ft_print_ptr(tab);
	else if (*format == 'X')
{}		;
	// ft_print_ptr(tab);
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
	tab->precision = 1;
	//TODO : init flags
	while (*format && !is_format(*format))
	{
		if (*format == '.')
			tab->dot = 1;
		else if (*format == '-')
			tab->dash = 1;
		else if (ft_isdigit(*format))
		{
			if (tab->dot)
				tab->precision = ft_atoi(format);
			else
				tab->width = ft_atoi(format);
			while (format[1] && ft_isdigit(format[1]))
				format++;
		}
		//TODO : eval other flags
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
			tab.length += write(1, format++, 1);
	}
	va_end(tab.args);
	return (tab.length);
}
