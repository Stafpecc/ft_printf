/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:12:35 by tarini            #+#    #+#             */
/*   Updated: 2024/11/27 18:30:31 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, unsigned int *i)
{
	unsigned int	count;
	
	if (!s)
	{
		ft_putstr("null", i);
		return (6);
	}
	count = 0;
	while (s[count++])
		ft_putchar(s[count], i);
	return (i);
}