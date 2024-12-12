/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:13 by tarini            #+#    #+#             */
/*   Updated: 2024/12/12 14:40:06 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define UP_HEXA "0123456789ABCDEF"
# define LOW_HEXA "0123456789abcdef"
# define DECIMAL "0123456789"

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbrbase(long n, const char *base, int signed_flag);
int		handle_conversion(const char format, va_list args);

#endif
