/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:17 by tarini            #+#    #+#             */
/*   Updated: 2024/12/05 15:41:34 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		tmp_count;
	int		i;
	void	*ptr;
	char	*str;

	count = 0;
	tmp_count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				tmp_count = ft_putnbrbase(va_arg(args, int), DECIMAL, 1);
			else if (format[i] == 'u')
				tmp_count = ft_putnbrbase(va_arg(args, unsigned int), DECIMAL, 0);
			else if (format[i] == 'x')
				tmp_count = ft_putnbrbase(va_arg(args, unsigned int), LOW_HEXA, 0);
			else if (format[i] == 'X')
				tmp_count = ft_putnbrbase(va_arg(args, unsigned int), UP_HEXA, 0);
			else if (format[i] == 'p')
			{
				ptr = va_arg(args, void *);
				if (ptr == NULL)
				{
					if (write(1, "(nil)", 5) == -1)
						return (-1);
					tmp_count = 5;
				}
				else
				{
					if (write(1, "0x", 2) == -1)
						return (-1);
					tmp_count = 2 + ft_putnbrbase((unsigned long)ptr, LOW_HEXA, 0);
				}
			}
			else if (format[i] == '%')
				tmp_count = ft_putchar('%');
			else if (format[i] == 'c')
				tmp_count = ft_putchar(va_arg(args, int));
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				tmp_count = ft_putstr(str);
			}
		}
		else
			tmp_count = ft_putchar(format[i]);
		if (tmp_count == -1)
			return (-1);
		count += tmp_count;
		i++;
	}
	va_end(args);
	return (count);
}
