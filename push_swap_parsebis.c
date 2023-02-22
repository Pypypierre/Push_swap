/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsebis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:38:11 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/15 10:58:19 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_wsp(char c)
{
	if (c == 32 || (c <= 13 && c >= 8))
		return (1);
	return (0);
}

static long long int	ft_atolbis(const char *nptr, int *nb, int len)
{
	int	sign;
	int	i;

	*nb = 0;
	i = 0;
	sign = 1;
	while (*nptr && i < len)
	{
		if ((*nptr >= 48 && *nptr <= 57) || (*nptr == '-' || *nptr == '+'))
		{
			if (*nptr >= 48 && *nptr <= 57)
				*nb = *nb * 10 + (*nptr - 48);
			if (*nptr == '-')
				sign *= -1;
			nptr++;
		}
		else
			return (42000000000);
		i++;
	}
	*nb *= sign;
	return (*nb);
}

void	ft_parsebis(char *av, t_list **nba_lst, t_list **nbb_lst)
{
	int len;
	int nb;

	while (*av)
	{
		len = 0;
		while (is_wsp(*av) == 1 && *av)
			av++;
		while (is_wsp(*av) == 0 && *av)
		{
			av++;
			len++;
		}
		if (len && (ft_atolbis(av - len, &nb, len) == 42000000000
				|| ft_nbnew(nb, nba_lst) == 0))
			ft_error(nba_lst, nbb_lst);
		if (!*av && !len)
			break ;
		if (ft_lstadd_back(nba_lst, ft_lstnew(nb)) == 1)
			ft_error(nba_lst, nbb_lst);
	}
}