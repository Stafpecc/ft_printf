/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:12:35 by tarini            #+#    #+#             */
/*   Updated: 2024/11/27 16:49:35 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	unsigned int	i;
	
	if (!s)
	{
		ft_putstr(("null"));
		return (6);
	}
	i = 0;
	while (s[i++])
		ft_putchar(s[i]);
	return (i);
}