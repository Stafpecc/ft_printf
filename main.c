/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stafpec <stafpec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:41:41 by stafpec           #+#    #+#             */
/*   Updated: 2024/12/05 15:45:33 by stafpec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "includes/ft_printf.h"

int main(void) {
    int x;
	ft_printf("%s\n", "Hello");
	ft_printf("%s\n", NULL);

	x = 42;
	ft_printf("%p\n", &x);
	ft_printf("%p\n", NULL);

	ft_printf("%x\n", 255);
	ft_printf("%X\n", 255);
	ft_printf("%x\n", 0);
	
	ft_printf("Int: %d, Str: %s, Hex: %x\n", 42, "test", 255);

	ft_printf("0\n");
	
	return 0;
}