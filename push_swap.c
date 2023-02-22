/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:21:23 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/22 03:41:27 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_aclen(char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tab[i] != NULL)
	{
		i++;
		len++;
	}
	return (len);
}

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;

	// t_list	*temp;
	lsta = NULL;
	lstb = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
		ft_parsebis(av[1], &lsta, &lstb);
	else
		ft_parse(ac, av, &lsta, &lstb);
	// temp = lsta;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d |", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	ft_clean_lis(&lsta, &lstb);
	// temp = lsta;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d |", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	ft_insersort(&lsta, &lstb);
	// temp = lsta;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d |", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	// temp = lstb;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d |", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	ft_clean_rot(&lsta, &lstb);
	// temp = lsta;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d |", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	// ft_bubble(&lstb, &lsta);
	// ft_join(&lsta, &lstb);
	// temp = lsta;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d |", temp->content);
	// 	temp = temp->next;
	// }
	// ft_printf("\n");
	// temp = lstb;
	// while (temp != NULL)
	// {
	// 	ft_printf("%d |", temp->content);
	// 	temp = temp->next;
	// }
	ft_lstclear(&lsta);
	ft_lstclear(&lstb);
	return (0);
}
