/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:04:31 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 17:09:12 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
