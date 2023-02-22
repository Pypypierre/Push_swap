/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:34:41 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/12 14:55:18 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return (1);
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (0);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

long long int	ft_atol(const char *nptr)
{
	long long int	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*nptr)
	{
		if ((*nptr >= 48 && *nptr <= 57) || (*nptr == 32 || (*nptr >= 8
					&& *nptr <= 13)) || (*nptr == '-' || *nptr == '+'))
		{
			if (*nptr >= 48 && *nptr <= 57)
				nb = nb * 10 + (*nptr - 48);
			if (*nptr == '-')
				sign *= -1;
			nptr++;
		}
		else
			return (42000000000);
	}
	return (nb * sign);
}

void	ft_error(t_list **lsta, t_list **ft_lstb)
{
	ft_lstclear(lsta);
	ft_lstclear(ft_lstb);
	write(2, "Error\n", 6);
	exit(0);
}
