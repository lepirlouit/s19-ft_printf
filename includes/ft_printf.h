/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:39:57 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 10:52:37 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>
# include"../libft/libft.h"

typedef struct s_print
{
	unsigned int	zero : 1;
	unsigned int	dot : 1;
	unsigned int	dash : 1;
	unsigned int	plus : 1;
	unsigned int	hash : 1;
	unsigned int	perc : 1;
	unsigned int	space : 1;
	unsigned int	precision;
	unsigned int	width;
	unsigned int	length;
	va_list			args;
}	t_print;

int	ft_printf(const char *format, ...);

#endif