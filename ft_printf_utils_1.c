/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:02:12 by pduhamel          #+#    #+#             */
/*   Updated: 2022/12/11 19:07:04 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_m(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += print_hex_m(nb / 16);
		i += ft_putchar(HEX[nb % 16]);
	}
	if (nb < 16)
		i += ft_putchar(HEX[nb]);
	return (i);
}

int	print_hex(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += print_hex(nb / 16);
		i += ft_putchar(HEX_M[nb % 16]);
	}
	if (nb < 16)
		i += ft_putchar(HEX_M[nb]);
	return (i);
}

int	print_hex_l(unsigned long nb, int x)
{
	int	i;

	i = 0;
	if (nb == 0 && x == 1)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (x == 1)
	{
		ft_putstr("0x");
		i += 2;
	}
	if (nb >= 16)
	{
		i += print_hex_l(nb / 16, 0);
		i += ft_putchar(HEX[nb % 16]);
	}
	if (nb < 16)
		i += ft_putchar(HEX[nb]);
	return (i);
}
