/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:04:13 by tarini            #+#    #+#             */
/*   Updated: 2024/11/27 16:50:55 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>

int	ft_putchar(char s);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int ft_putprct();
int ft_putnbr(int n);


#endif