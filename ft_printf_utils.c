/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:40:25 by pduhamel          #+#    #+#             */
/*   Updated: 2022/12/11 19:40:30 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		i += ft_putchar(s[0]);
		s++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	str_put(int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += str_put((n / 10));
		i += ft_putchar((n % 10 + '0'));
	}
	if (n < 10)
		i += ft_putchar((n + '0'));
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		i++;
	}
	i += str_put(n);
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_u((n / 10));
		i += ft_putchar((n % 10 + '0'));
	}
	if (n < 10)
		i += ft_putchar((n + '0'));
	return (i);
	return (i);
}
