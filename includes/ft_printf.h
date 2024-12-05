/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:13 by tarini            #+#    #+#             */
/*   Updated: 2024/12/05 14:48:48 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

# define UP_HEXA "0123456789ABCDEF"
# define LOW_HEXA "0123456789abcdef"
# define DECIMAL "0123456789"

int	ft_putchar(char s);
int	ft_putstr(char *str);
int	ft_putnbrbase(long n, const char *base, int signed_flag);
int	ft_printf(const char *format, ...);
int	ft_putnbrbase_sign(int signed_flag, unsigned long *nb, int *count, long n);

#endif
