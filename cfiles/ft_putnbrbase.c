/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:43:26 by stafpec           #+#    #+#             */
/*   Updated: 2024/12/05 15:33:46 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_putnbrbase_sign(int signed_flag, unsigned long *nb, int *count, long n)
{
	if (signed_flag && n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*count)++;
		*nb = -n;
	}
	else
		*nb = (unsigned long)n;
	return (0);
}

int	ft_putnbrbase(long n, const char *base, int signed_flag)
{
	int				count;
	unsigned long	nb;
	int				base_len;
	int				tmp;

	count = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (-1);
	if (ft_putnbrbase_sign(signed_flag, &nb, &count, n) == -1)
		return (-1);
	if (nb >= (unsigned long)base_len)
	{
		tmp = ft_putnbrbase(nb / base_len, base, 0);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	if (write(1, &base[nb % base_len], 1) == -1)
		return (-1);
	return (++count);
}
