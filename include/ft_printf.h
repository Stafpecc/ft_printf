/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:13 by tarini            #+#    #+#             */
/*   Updated: 2024/11/27 18:34:11 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

# define L_HEXA "0123456789ABCDEF"
# define U_HEXA "0123456789abcdef"

int	ft_putchar(char s, unsigned int *i);
int	ft_putstr(char *s, unsigned int *i);
int	ft_putptr(void *ptr, unsigned int *i);
int ft_putprct(unsigned int *i);
int ft_putnbr(int n, unsigned int *i);


#endif