/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_inst1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:26:46 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/22 03:05:45 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inst_rrab(t_list **lsta, t_list **lstb)
{
	t_list	*tempa;
	t_list	*enda;
	t_list	*tempb;
	t_list	*endb;

	tempa = *lsta;
	enda = *lsta;
	tempb = *lstb;
	endb = *lstb;
	while (enda->next != NULL)
		enda = enda->next;
	while (endb->next != NULL)
		endb = endb->next;
	*lsta = (*lsta)->next;
	enda->next = tempa;
	*lstb = (*lstb)->next;
	endb->next = tempb;
	tempb->next = NULL;
	tempa->next = NULL;
}

void	inst_rr(t_list **lst)
{
	t_list	*temp;
	t_list	*end;

	temp = *lst;
	end = *lst;
	while ((end->next)->next != NULL)
		end = end->next;
	*lst = end->next;
	(end->next)->next = temp;
	end->next = NULL;
}

void	inst_rrr(t_list **lsta, t_list **lstb)
{
	t_list	*tempa;
	t_list	*enda;
	t_list	*tempb;
	t_list	*endb;

	tempa = *lsta;
	enda = *lsta;
	tempb = *lstb;
	endb = *lstb;
	while ((enda->next)->next != NULL)
		enda = enda->next;
	while ((endb->next)->next != NULL)
		endb = endb->next;
	*lsta = enda->next;
	(enda->next)->next = tempa;
	*lstb = endb->next;
	(endb->next)->next = tempb;
	enda->next = NULL;
	endb->next = NULL;
}

int	ft_act(int selection, t_list **lsta, t_list **lstb)
{
	if (selection == 0)
		return (ft_printf("sa\n"), inst_s(lsta), 1);
	if (selection == 1)
		return (ft_printf("sb\n"), inst_s(lstb), 1);
	if (selection == 2)
		return (ft_printf("ss\n"), inst_ss(lsta, lstb), 1);
	if (selection == 3)
		return (ft_printf("pa\n"), inst_pa(lsta, lstb), 1);
	if (selection == 4)
		return (ft_printf("pb\n"), inst_pb(lsta, lstb), 1);
	if (selection == 5)
		return (ft_printf("ra\n"), inst_r(lsta), 1);
	if (selection == 6) // rajouter && !ft_check_rr(lsta, lstb)
		return (ft_printf("rb\n"), inst_r(lstb), 1);
	if (selection == 7)
		return (ft_printf("rr\n"), inst_rrab(lsta, lstb), 1);
	if (selection == 8)
		return (ft_printf("rra\n"), inst_rr(lsta), 1);
	if (selection == 9)
		return (ft_printf("rrb\n"), inst_rr(lstb), 1);
	if (selection == 10)
		return (ft_printf("rrr\n"), inst_rrr(lsta, lstb), 1);
	return (0);
}
