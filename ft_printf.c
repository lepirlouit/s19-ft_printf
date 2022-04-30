/* ************************************************************************** */
/*       */
/*          :::      ::::::::   */
/*   ft_printf.c                 :+:      :+:    :+:   */
/*      +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*  +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:24:19 by bde-biol          #+#    #+#             */
/*   Updated: 2022/04/18 22:46:36 by bde-biol         ###   ########.fr       */
/*       */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
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
		tab->length+= write(1, &padding_char, 1);
		min_size++;
	}
}

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
    // ft_update_tab(tab, 1);      //# calculate special cases and length                      
    if (tab->width && !tab->dash) // # if width and not - flag
        ft_padding(tab, ' ', 1);    // # handle right alignment
    tab->length += write(1, &a, 1); // # print char
    if (tab->width && tab->dash)  // # if width and - flag      
        ft_padding(tab, ' ', 1); 
}

// void	ft_print_percent(t_print *tab)
// {

// }

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	length;

	length = ft_strlen(str);
	write(1, str, length);
	return (1);
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
		tab->length+=ft_putchr('%');
	else if (*format == 'c')
		ft_print_char(tab);
	// tab->length += ft_putchr(va_arg(tab->args, int));
	else if (*format == 's')
		tab->length+=ft_putstr(va_arg(tab->args, char*));
	return (format + 1);
}

char	is_format(char c)
{
	char	*formats;

	formats = "udcsupxX%";
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
	//TODO : init flags
	while (*format && !is_format(*format))
	{
		if (*format == '.')
			tab->dot = 1;
		else if (*format == '-')
			tab->dash = 1;
		else if (ft_isdigit(*format))
			tab->width = tab->width * 10 + (*format - '0');
		//TODO : eval other flags
		format++;
	}
	return ft_eval_format(tab, format);
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
