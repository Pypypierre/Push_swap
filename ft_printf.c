/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:29:32 by pduhamel          #+#    #+#             */
/*   Updated: 2022/12/11 19:50:08 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list argptr, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(argptr, int));
	else if (c == 's')
		i = ft_putstr(va_arg(argptr, char *));
	else if (c == 'p')
		i = print_hex_l((unsigned long)va_arg(argptr, void *), 1);
	else if (c == 'd')
		i = ft_putnbr(va_arg(argptr, int));
	else if (c == 'i')
		i = ft_putnbr(va_arg(argptr, int));
	else if (c == 'u')
		i = ft_putnbr_u(va_arg(argptr, unsigned int));
	else if (c == 'x')
		i = print_hex_m(va_arg(argptr, unsigned int));
	else if (c == 'X')
		i = print_hex(va_arg(argptr, unsigned int));
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;

	i = 0;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += ft_type(argptr, str[1]);
			str = str + 2;
		}
		else
		{
			write(1, &(*str), 1);
			str++;
			i++;
		}
	}
	va_end(argptr);
	return (i);
}

// int	main(void)
// {
// 	int i;
// 	char *c = NULL;

// 	i = ft_printf("%s", c);
// 	return (0);
// }