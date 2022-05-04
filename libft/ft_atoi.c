/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:15:16 by bde-biol          #+#    #+#             */
/*   Updated: 2022/04/09 14:47:31 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\r' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\t' || c == ' ' );
}

int	ft_atoi(const char *nptr)
{
	unsigned long	result;
	char			neg;

	result = 0;
	neg = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if ((*nptr == '-'))
			neg = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		if (((result * 10) + *nptr - '0') < result)
			return ((neg / -2.0) - 1);
		result = (result * 10) + *nptr - '0';
		nptr++;
	}
	return (neg * result);
}
