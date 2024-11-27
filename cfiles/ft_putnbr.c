/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:33:41 by tarini            #+#    #+#             */
/*   Updated: 2024/11/27 18:30:31 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_putnbr(int n, unsigned int *i)
{
	unsigned int	size;
	char	*num;

	size = 0;
	num = ft_itoa(n) ;
	size = ft_putstr(num, i) ;
	free (num) ;
	return (size);
}