/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:27:16 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/22 03:14:48 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_xtrem(t_list **lst)
{
	t_list	*temp;
	int		*xtrem;
	int		min;
	int		max;

	temp = *lst;
	min = temp->content;
	max = min;
	xtrem = malloc(sizeof(int) * 2);
	while (temp != NULL)
	{
		if (temp->content > max)
			max = temp->content;
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	xtrem[0] = min;
	xtrem[1] = max;
	return (xtrem);
}

int	ft_sort(t_list **lst)
{
	t_list	*temp;
	int		current;

	temp = *lst;
	current = temp->content;
	temp = temp->next;
	if (!(*lst))
		return (1);
	while (temp != NULL)
	{
		if (temp->content < current)
			return (0);
		current = temp->content;
		temp = temp->next;
	}
	return (1);
}

void	ft_clean_rot(t_list **lsta, t_list **lstb)
{
	int	*xtrem;
	int	xrk[2];

	// t_list	*temp;
	if (ft_sort(lsta) == 1)
		return ;
	xtrem = ft_xtrem(lsta);
	xrk[0] = get_rank(lsta, xtrem[0], xtrem);
	xrk[1] = get_rank(lsta, xtrem[1], xtrem);
	if (*xrk > (len_lst(lsta) / 2))
	{
		while (ft_sort(lsta) == 0)
			ft_act(8, lsta, lstb);
	}
	else
	{
		while (ft_sort(lsta) == 0)
		{
			// temp = *lsta;
			// while (temp != NULL)
			// {
			// 	ft_printf("%d |", temp->content);
			// 	temp = temp->next;
			// }
			// ft_printf("\n");
			ft_act(5, lsta, lstb);
		}
	}
	free(xtrem);
}
