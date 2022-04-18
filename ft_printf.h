/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:39:57 by bde-biol          #+#    #+#             */
/*   Updated: 2022/04/18 23:48:38 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>

typedef struct s_print
{
	va_list			args;
	unsigned int	precision : 1;
	unsigned int	zero : 1;
	unsigned int	dot : 1;
	unsigned int	dash : 1;
	unsigned int	sign : 1;
	unsigned int	is_zero : 1;
	unsigned int	perc : 1;
	unsigned int	space : 1;
	unsigned int	width;
	unsigned int	length;
}	t_print;

int	ft_printf(const char *format, ...);

#endif