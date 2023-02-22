/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:52:45 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/20 15:18:59 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_xtrem(t_list **lst)
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

void	ft_bubble(t_list **lsta, t_list **lstb)
{
	int	*xtrem;

	if (*lstb == NULL || (*lstb)->next == NULL)
		return ;
	xtrem = ft_xtrem(lstb);
	// ft_printf("min %d | max %d\n", *xtrem, xtrem[1]);
	while (ft_sort(lstb) == 0)
	{
		if ((*lstb)->content > (*lstb)->next->content
			&& !((*lstb)->content == xtrem[1]
				&& (*lstb)->next->content == xtrem[0]))
			ft_act(1, lsta, lstb);
		else
			ft_act(6, lsta, lstb);
	}
	free(xtrem);
}
