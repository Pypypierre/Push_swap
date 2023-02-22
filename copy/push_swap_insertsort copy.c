/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_insertsort copy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:27:49 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/21 17:36:59 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_list **lst, int nb)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *lst;
	while (temp->content < nb && temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

static int	get_rot(int nb, t_list **lsta, int rot)
{
	t_list	*temp;

	temp = *lsta;
	if (rot)
	{
	}
}

void	ft_insersort(t_list **lsta, t_list **lstb)
{
	int	n;

	n = 0;
	while (*lstb != NULL)
	{
		if ((*lstb)->content < (*lsta)->content)
			ft_act(3, lsta, lstb);
		else if (get_rank(lsta, (*lstb)->content) > (len_lst(lsta) / 2))
		{
			n = get_rot((*lstb)->content, lsta, 0);
			while (n >= 0)
			{
				ft_act(8, lsta, lstb);
				n--;
			}
			ft_act(3, lsta, lstb);
		}
		else
		{
			n = get_rot((*lstb)->content, lsta, 1);
			while (n >= 0)
			{
				ft_act(5, lsta, lstb);
				n--;
			}
			ft_act(3, lsta, lstb);
		}
	}
}
