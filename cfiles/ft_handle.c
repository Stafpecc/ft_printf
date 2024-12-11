/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:42:50 by stafpec           #+#    #+#             */
/*   Updated: 2024/12/11 13:45:26 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_pointer(void *ptr)
{
	int	tmp_count;

	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	tmp_count = 2 + ft_putnbrbase((unsigned long)ptr, LOW_HEXA, 0);
	return (tmp_count);
}

int	handle_conversion(const char format, va_list args)
{
	int		tmp_count;
	char	*str;

	tmp_count = 0;
	if (format == 'd' || format == 'i')
		tmp_count += ft_putnbrbase(va_arg(args, int), DECIMAL, 1);
	else if (format == 'u')
		tmp_count += ft_putnbrbase(va_arg(args, unsigned int), DECIMAL, 0);
	else if (format == 'x')
		tmp_count += ft_putnbrbase(va_arg(args, unsigned int), LOW_HEXA, 0);
	else if (format == 'X')
		tmp_count += ft_putnbrbase(va_arg(args, unsigned int), UP_HEXA, 0);
	else if (format == 'p')
		tmp_count += handle_pointer(va_arg(args, void *));
	else if (format == '%')
		tmp_count += ft_putchar('%');
	else if (format == 'c')
		tmp_count += ft_putchar(va_arg(args, int));
	else if (format == 's')
	{
		str = va_arg(args, char *);
		tmp_count += ft_putstr(str);
	}
	return (tmp_count);
}
