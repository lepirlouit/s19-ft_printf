/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:24:19 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 17:07:32 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_print	tab;

	tab.length = 0;
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
