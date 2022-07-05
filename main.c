/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-biol <bde-biol@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:28:23 by bde-biol          #+#    #+#             */
/*   Updated: 2022/06/05 20:16:53 by bde-biol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int r1;
	int r2;
	void *ptr1;
	void *ptr2;
	void *ptr3;
	size_t val = 5;

	ptr1 = (void *)16;
	ptr2 = (void *)"Hello World !";
	ptr3 = malloc(1);

	r1 = printf("Characters -%3c- -%-3c- -%3c- -%%-\n", 'O','V', '\x7F');
	r2 = ft_printf("Characters -%3c- -%-3c- -%3c- -%%-\n", 'O', 'V', '\x7F');
	printf("%d - %d\n", r1, r2);
	r1 = printf("Pointers -%2p- -%-20p- -%20p- -%p-\n", NULL, ptr1, ptr2, ptr3);
	r2 = ft_printf("Pointers -%2p- -%-20p- -%20p- -%p-\n", NULL, ptr1, ptr2, ptr3);
	printf("%d - %d\n", r1, r2);
	r1 = printf("strings [%.s] -%2.4s- -%-20.2s- -%20s- -%s-\n", "-", NULL, ptr2, ptr2, ptr2);
	r2 = ft_printf("strings [%.s] -%2.4s- -%-20.2s- -%20s- -%s-\n", "-", NULL, ptr2, ptr2, ptr2);
	printf("%d - %d\n", r1, r2);
	ptr2 = (void *)INT_MIN;
	ptr3= (void *)INT_MAX;
	r1 = printf("Decimals [%4.2d] [%04d] [%d] -%2.4d- -%-20.4d- -%20.2d- -%d- -%d- -%d-\n", -1, 9, -10, NULL, ptr1, ptr2, ptr3, ptr2 -1, ptr3 +1);
	r2 = ft_printf("Decimals [%4.2d] [%04d] [%d] -%2.4d- -%-20.4d- -%20.2d- -%d- -%d- -%d-\n", -1, 9, -10, NULL, ptr1, ptr2, ptr3, ptr2 -1, ptr3 +1);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Decimals [%04d] -%20.2d- -%d-\n", -14, ptr2, -1);
	r2 = ft_printf("Decimals [%04d] -%20.2d- -%d-\n", -14, ptr2, -1);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Decimals -%20.2i- -%i- -%4.0i-\n", ptr2, 0, 0);
	r2 = ft_printf("Decimals -%20.2i- -%i- -%4.0i-\n", ptr2, 0, 0);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Decimals -%20.2u- -%u- -%4.0u-\n", ptr2, -1, 0);
	r2 = ft_printf("Decimals -%20.2u- -%u- -%4.0u-\n", ptr2, -1, 0);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Decimals -%2.4x- -%-20.4x- -%20.2x- -%x- -%x- -%x-\n", NULL, ptr1, ptr2, ptr3, ptr2 -1, ptr3 +1);
	r2 = ft_printf("Decimals -%2.4x- -%-20.4x- -%20.2x- -%x- -%x- -%x-\n", NULL, ptr1, ptr2, ptr3, ptr2 -1, ptr3 +1);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Decimals -%2.4X- -%-20.4X- -%20.2X- -%X- -%X- -%X-\n", NULL, ptr1, ULONG_MAX, ptr3, ptr2 -1, ptr3 +1);
	r2 = ft_printf("Decimals -%2.4X- -%-20.4X- -%20.2X- -%X- -%X- -%X-\n", NULL, ptr1, ULONG_MAX, ptr3, ptr2 -1, ptr3 +1);
	printf("%d - %d\n", r1, r2);

	r1 = printf("strings [%-2d]\n", -1);
	r2 = ft_printf("strings [%-2d]\n", -1);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Plus : %+d %+d %+d %+d %+d %+d %+d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	r2 = ft_printf("Plus : %+d %+d %+d %+d %+d %+d %+d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d - %d\n", r1, r2);

	r1 = printf("Space :  %+- d % +d % d % d % d % d % d\n", INT_MAX, 5, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	r2 = ft_printf("Space :  %+- d % +d % d % d % d % d % d\n", INT_MAX, 5, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Hash : %#20.10x %#-20.10x %#4.8x %#4.20X\n", -42, 42, 0, 6);
	r2 = ft_printf("Hash : %#20.10x %#-20.10x %#4.8x %#4.20X\n", -42, 42, 0, 6);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Hash : %#25.15p|%#-20.10p|%#10.8p|%#-8.8p|%#4.20p\n", -42, 42, 0, 0, 6);
	r2 = ft_printf("Hash : %#25.15p|%#-20.10p|%#10.8p|%#-8.8p|%#4.20p\n", -42, 42, 0, 0, 6);
	printf("%d - %d\n", r1, r2);
	r1 = printf("Hash :  %#2.0x|%2.0p|%-2p|%#-2x|%p \n", 0, 0, 1, 1, LONG_MAX);
	r2 = ft_printf("Hash :  %#2.0x|%2.0p|%-2p|%#-2x|%p \n", 0, 0, 1, 1, LONG_MAX);
	printf("%d - %d\n", r1, r2);
	r1 = printf("{%015p} {%15p} {%15.0p} {%015p} {%15p}\n", NULL, NULL, NULL, 1, 1);
	r2 = ft_printf("{%015p} {%15p} {%15.0p} {%015p} {%15p}\n", NULL, NULL, NULL, 1, 1);
	printf("%d - %d\n", r1, r2);
	r1 = printf("{%#015x} {%#15x} {%#15.0x} {%#015x} {%#15x}\n", NULL, NULL, NULL, 1, 1);
	r2 = ft_printf("{%#015x} {%#15x} {%#15.0x} {%#015x} {%#15x}\n", NULL, NULL, NULL, 1, 1);
	printf("%d - %d\n", r1, r2);
	r1 = printf("o7 : |% 10.5d|%- 10.5d|% 10.5d|%- 10.5d|\n", -42, -42, 42, 42);
	r2 = ft_printf("t7 : |% 10.5d|%- 10.5d|% 10.5d|%- 10.5d|\n", -42, -42, 42, 42);
	printf("%d - %d\n", r1, r2);
	
}
