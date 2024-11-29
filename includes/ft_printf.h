/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:13 by tarini            #+#    #+#             */
/*   Updated: 2024/11/29 15:56:55 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

# define LOW_HEXA "0123456789ABCDEF"
# define UP_HEXA "0123456789abcdef"

int	ft_putchar(char s);
int	ft_putstr(char *str);
int	ft_putnbrbase(long n, const char *base, int signed_flag);
int	ft_printf(const char *format, ...);

#endif
