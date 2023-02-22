/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:31:32 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/15 11:43:41 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_content(t_list **lst, int indice)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *lst;
	while (temp != NULL)
	{
		if (i == indice)
			return (temp->content);
		i++;
		temp = temp->next;
	}
	return (-1);
}

void	ft_loop(int *len, t_list *tempbis, int *ref)
{
	while (tempbis != 0)
	{
		if (tempbis->content > *ref)
		{
			(*len)++;
			*ref = tempbis->content;
		}
		tempbis = tempbis->next;
	}
}

void	ft_action(int *len, int *i, t_list **lst, t_list *temp)
{
	if (len[0] > len[1])
	{
		i[1] = i[0];
		len[1] = len[0];
	}
	else if (len[0] == len[1])
	{
		if (temp->content < ft_content(lst, i[1]))
		{
			i[1] = i[0];
			len[1] = len[0];
		}
	}
}

int	ft_lis(t_list **lst)
{
	t_list	*temp;
	int		len[2];
	int		i[2];
	int		ref;

	temp = *lst;
	i[1] = -1;
	i[0] = -1;
	len[1] = 0;
	while (temp != NULL)
	{
		len[0] = 1;
		i[0]++;
		ref = temp->content;
		ft_loop(&(len[0]), temp, &ref);
		ft_action(len, i, lst, temp);
		temp = temp->next;
	}
	return (i[1]);
}

void	ft_clean_lis(t_list **lsta, t_list **lstb)
{
	int	i;
	int	start;
	int	lis;

	i = 0;
	lis = ft_lis(lsta);
	while (i != lis)
	{
		ft_act(4, lsta, lstb);
		i++;
	}
	start = (*lsta)->content;
	i = start;
	ft_act(5, lsta, lstb);
	while ((*lsta)->content != start)
	{
		if ((*lsta)->content >= i)
		{
			i = (*lsta)->content;
			ft_act(5, lsta, lstb);
		}
		else
			ft_act(4, lsta, lstb);
	}
}

//TODO faire un test pour savoir s'il faut faire un r ou un rr