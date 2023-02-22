/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:13:44 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/20 18:47:29 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return (1);
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
	return (0);
}

void	ft_join(t_list **lsta, t_list **lstb)
{
	while (*lstb != NULL)
	{
		if ((*lstb)->content > (*lsta)->content)
			ft_act(5, lsta, lstb);
		else
			ft_act(3, lsta, lstb);
	}
	while (ft_sort(lsta) == 0)
		ft_act(5, lsta, lstb);
}

int	len_lst(t_list **lst)
{
	t_list *temp;
	int nb;

	temp = *lst;
	nb = 0;
	while (temp != NULL)
	{
		nb++;
		temp = temp->next;
	}
	return (nb);
}