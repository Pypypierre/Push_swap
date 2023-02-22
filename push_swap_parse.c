/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:50:50 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/12 22:24:36 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbnew(long long int nb, t_list **nba_lst)
{
	t_list	*temp;

	temp = *nba_lst;
	while (temp != NULL)
	{
		if (temp->content == nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_parse(int ac, char **av, t_list **nba_lst, t_list **nbb_lst)
{
	int				i;
	long long int	nb;

	i = 1;
	while (ac > i)
	{
		nb = ft_atol(av[i]);
		if (nb == 42000000000 || !(nb >= -2147483648 && nb <= 2147483647)
			|| ft_nbnew(nb, nba_lst) == 0)
			ft_error(nba_lst, nbb_lst);
		if (ft_lstadd_back(nba_lst, ft_lstnew(nb)) == 1)
			ft_error(nba_lst, nbb_lst);
		i++;
	}
}
