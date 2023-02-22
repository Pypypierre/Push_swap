/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:29:25 by pduhamel          #+#    #+#             */
/*   Updated: 2022/12/11 19:48:59 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX "0123456789abcdef"
# define HEX_M "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	print_hex_l(unsigned long nb, int x);
int	print_hex(unsigned int nb);
int	print_hex_m(unsigned int nb);
int	ft_putnbr_u(unsigned int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);

#endif