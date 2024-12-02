/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:43:26 by stafpec           #+#    #+#             */
/*   Updated: 2024/12/01 15:45:25 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_putnbrbase(long n, const char *base, int signed_flag)
{
	int				count;
	unsigned long	nb;
	int				base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	count = 0;
	if (signed_flag && n < 0)
	{
		count += ft_putchar('-');
		nb = -n;
	}
	else
		nb = (unsigned long)n;
	if (nb >= (unsigned long)base_len)
		count += ft_putnbrbase(nb / base_len, base, 0);
	count += ft_putchar(base[nb % base_len]);
	return (count);
}
