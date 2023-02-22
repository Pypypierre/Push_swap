/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:46:21 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/07 15:27:04 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_s(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
}

void	inst_ss(t_list **lsta, t_list **lstb)
{
	t_list	*temp;
	t_list	*tempb;

	if (*lsta == NULL || (*lsta)->next == NULL || *lstb == NULL
		|| (*lstb)->next == NULL)
		return ;
	temp = *lsta;
	tempb = *lstb;
	*lstb = (*lstb)->next;
	*lsta = (*lsta)->next;
	tempb->next = (*lstb)->next;
	temp->next = (*lsta)->next;
	(*lstb)->next = tempb;
	(*lsta)->next = temp;
}

void	inst_pa(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (*lstb == NULL)
		return ;
	temp = *lstb;
	*lstb = (*lstb)->next;
	if (ft_lstadd_front(lsta, temp) == 1)
		ft_error(lsta, lstb);
}

void	inst_pb(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (*lsta == NULL)
		return ;
	temp = *lsta;
	*lsta = (*lsta)->next;
	if (ft_lstadd_front(lstb, temp) == 1)
		ft_error(lsta, lstb);
}

void	inst_r(t_list **lst)
{
	t_list	*temp;
	t_list	*end;

	temp = *lst;
	end = *lst;
	while (end->next != NULL)
		end = end->next;
	*lst = (*lst)->next;
	end->next = temp;
	temp->next = NULL;
}
