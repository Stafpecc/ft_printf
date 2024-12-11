/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:17 by tarini            #+#    #+#             */
/*   Updated: 2024/12/11 14:05:14 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	process_format(const char *format, va_list args, int *count)
{
	int	i;

	i = 0;
	if (!format || !format[i + 1])
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			*count += handle_conversion(format[i + 1], args);
			i++;
		}
		else
			*count += ft_putchar(format[i]);
		if (*count == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	if (process_format(format, args, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}
