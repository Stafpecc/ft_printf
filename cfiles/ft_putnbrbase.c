/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:43:26 by stafpec           #+#    #+#             */
/*   Updated: 2024/11/29 15:09:51 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbrbase(long n, const char *base, int signed_flag)
{
	int				count = 0;
	unsigned long	nb;
	int				base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	if (signed_flag && n < 0)
	{
		count += ft_putchar('-');
		nb = -n;
	}
	else
		nb = (unsigned long)n;
	if (nb >= (unsigned long)base_len)
		count += ft_putnbr_base(nb / base_len, base, 0);
	count += ft_putchar(base[nb % base_len]);
	return (count);
}
