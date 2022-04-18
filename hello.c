#include<stdio.h>
#include <stdarg.h>
#include<unistd.h>

int ft_printf(const char* format, ...);

int	ft_putchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int main(void)
{
	int r1;
	int r2;
	r1 = printf("Hello World ! -%c- -%%-\n", 'V');
	r2 = ft_printf("Hello World ! -%c- -%%-\n", 'V');
	printf("%d - %d\n", r1, r2);
}

int ft_put_fmt(va_list args, const char format)
{
	int	length;
	if (format == '%')
		length = ft_putchr('%');
	else if (format == 'c')
		length = ft_putchr(va_arg(args, int));

	return (length);
}

int ft_printf(const char *fmt, ...)
{
	va_list args;
	int	length;

	length = 0;
	va_start(args, fmt);
	while (*fmt != '\0') {
		if (*fmt == '%')
		{
			length += ft_put_fmt(args, *(fmt+1));
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

