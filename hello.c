/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:24:19 by bde-biol          #+#    #+#             */
/*   Updated: 2022/04/18 22:29:38 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include<unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

//cspdiuxX%
int	ft_put_fmt(va_list args, const char format)
{
	int	length;

	if (format == '%')
		length = ft_putchr('%');
	else if (format == 'c')
		length = ft_putchr(va_arg(args, int));
	return (length);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			length += ft_put_fmt(args, *(fmt + 1));
			fmt++;
		}
		else
		{
			ft_putchr(*fmt);
			length++;
		}
		fmt++;
	}
	va_end(args);
	return (length);
}
