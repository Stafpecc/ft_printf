/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:33:41 by tarini            #+#    #+#             */
/*   Updated: 2024/11/27 16:51:41 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putnbr(int n)
{
	unsigned int	size;
	char	*num;

	size = 0;
	num = ft_itoa(n) ;
	size = ft_putstr(num) ;
	free (num) ;
	return (size);
}