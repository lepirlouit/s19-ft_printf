/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:39:57 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 17:10:36 by bde-biol         ###   ########.fr       */
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
	unsigned int	space : 1;
	unsigned int	precision;
	unsigned int	width;
	unsigned int	length;
	va_list			args;
}	t_print;

int				ft_printf(const char *format, ...);
const char		*ft_eval_format_flags(t_print *tab, const char *format);
void			ft_print_char(t_print *tab);
void			ft_print_str(t_print *tab);
void			ft_print_ptr(t_print *tab);
void			ft_print_integer(t_print *tab);
void			ft_print_unsigned_integer(t_print *tab);
void			ft_print_hex(t_print *tab, char lower);
int				ft_putchr(int c);
int				ft_put_prefix(char lower);
void			ft_padding(t_print *tab, unsigned int min_size);
void			ft_number_padding(t_print *tab, unsigned int min_size);
int				ft_max(unsigned int a, unsigned int b);
int				ft_min(unsigned int a, unsigned int b);
unsigned int	ft_nb_len_base(unsigned long int ptr, unsigned int base);
unsigned int	ft_nbr_len(int nbr);
void			write_nbr_base(unsigned long int ptr, unsigned char base, char lower);

#endif