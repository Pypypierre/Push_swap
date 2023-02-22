/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertsort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:27:49 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/22 03:40:20 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(t_list **lst, int nb, int *xtrem)
{
	t_list	*temp;
	int		i;
	int		delta;
	int		n;

	i = 0;
	if (!(*lst))
		return (0);
	temp = *lst;
	n = -1;
	delta = 2147483647;
	while (temp != NULL)
	{
		if (temp->content >= nb && (temp->content - nb) < delta)
		{
			n = i;
			delta = (temp->content - nb);
		}
		temp = temp->next;
		i++;
	}
	if (delta == 2147483647)
		return (get_rank(lst, *xtrem, xtrem));
	return (n);
}

int	ft_last(t_list **lsta)
{
	t_list	*temp;

	temp = *lsta;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->content);
}

void	ft_insersort(t_list **lsta, t_list **lstb)
{
	int	rk;
	int	*xtrem;

	// t_list	*temp;
	while (*lstb != NULL)
	{
		xtrem = ft_xtrem(lsta);
		rk = get_rank(lsta, (*lstb)->content, xtrem);
		// ft_printf("%d\n", rk);
		if (rk > (len_lst(lsta) / 2) || rk == -1)
		{
			rk = ((len_lst(lsta)) - rk);
			while (rk > 0)
			{
				ft_act(8, lsta, lstb);
				rk--;
			}
			ft_act(3, lsta, lstb);
		}
		else
		{
			while (rk > 0)
			{
				rk--;
				ft_act(5, lsta, lstb);
			}
			ft_act(3, lsta, lstb);
		}
		// temp = *lsta;
		// ft_printf("lsta : ");
		// while (temp != NULL)
		// {
		// 	ft_printf("%d | ", temp->content);
		// 	temp = temp->next;
		// }
		// temp = *lstb;
		// ft_printf("\nlstb : ");
		// while (temp != NULL)
		// {
		// 	ft_printf("%d | ", temp->content);
		// 	temp = temp->next;
		// }
		// ft_printf("\n");
	}
	free(xtrem);
}
