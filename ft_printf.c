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

// void	ft_print_char(t_print *tab)
// {
// 	char	a;

// 	a = va_arg(tab->args, int);
//     ft_update_tab(tab, 1);      # calculate special cases and length                      
//     if (tab->wdt && !tab->dash)  # if width and not - flag
//         ft_right_cs(tab, 0);     # handle right alignment
//     tab->tl += write(1, &a, 1);  # print char
//     if (tab->wdt && tab->dash)   # if width and - flag      
//         ft_left_cs(tab, 0); 
// }

// void	ft_print_percent(t_print *tab)
// {

// }

int	ft_putchr(int c)
{
	write(1, &c, 1);
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
		ft_putchr('%');
	else if (*format == 'c')
		ft_putchr(va_arg(tab->args, int));
	tab->length++;
	return (format + 1);
}

// char	*ft_eval_format(t_print tab, char *format)
// {

// }

int	ft_printf(const char *format, ...)
{
	t_print	tab;

	ft_initialise_tab(&tab);
	va_start(tab.args, format);
	while (*format)
	{
		// printf("%d\n", tab.length);
		if (*format == '%')
			format = ft_eval_format(&tab, format + 1);
		else
			tab.length += write(1, format++, 1);
	}
	va_end(tab.args);
	return (tab.length);
}
