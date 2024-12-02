/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:17 by tarini            #+#    #+#             */
/*   Updated: 2024/12/01 15:46:22 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count = 0;
	int		i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbrbase(va_arg(args, int), "0123456789", 1);
			else if (format[i] == 'u')
				count += ft_putnbrbase(va_arg(args, unsigned int), "0123456789", 0);
			else if (format[i] == 'x')
				count += ft_putnbrbase(va_arg(args, unsigned int), LOW_HEXA, 0);
			else if (format[i] == 'X')
				count += ft_putnbrbase(va_arg(args, unsigned int), UP_HEXA, 0);
			else if (format[i] == 'p')
			{
    			count += write(1, "0x", 2);
    			count += ft_putnbrbase((unsigned long)va_arg(args, void *), LOW_HEXA, 0);
			}
			else if (format[i] == '%')
				count += ft_putchar('%');
			else if (format[i] == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				count += ft_putstr(str);
			}
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main(void) {
    ft_printf("%s\n", "Hello");
	ft_printf("%s\n", NULL);

	int x = 42;
	ft_printf("%p\n", &x);
	ft_printf("%p\n", NULL);

	ft_printf("%x\n", 255);
	ft_printf("%X\n", 255);
	ft_printf("%x\n", 0);
	
	ft_printf("Int: %d, Str: %s, Hex: %x\n", 42, "test", 255);

    return 0;
}
*/