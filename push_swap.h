/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pduhamel <pduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:49:35 by pduhamel          #+#    #+#             */
/*   Updated: 2023/02/22 03:14:28 by pduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int					ft_lstadd_back(t_list **lst, t_list *new);

int					ft_lstadd_front(t_list **lst, t_list *new);

void				ft_lstclear(t_list **lst);

void				ft_parse(int ac, char **av, t_list **nba_lst,
						t_list **nbb_lst);

void				ft_parsebis(char *av, t_list **nba_lst, t_list **nbb_lst);

void				inst_s(t_list **lst);

void				inst_ss(t_list **lsta, t_list **lstb);

void				inst_pa(t_list **lsta, t_list **lstb);

void				inst_pb(t_list **lsta, t_list **lstb);

void				inst_r(t_list **lst);

void				inst_rrab(t_list **lsta, t_list **lstb);

void				inst_rr(t_list **lst);

void				inst_rrr(t_list **lsta, t_list **lstb);

void				ft_error(t_list **lsta, t_list **ft_lstb);

void				ft_clean_lis(t_list **lsta, t_list **lstb);

void				ft_bubble(t_list **lsta, t_list **lstb);

void				ft_join(t_list **lsta, t_list **lstb);

t_list				*ft_lstnew(int content);

int					ft_printf(const char *str, ...);

int					ft_act(int selection, t_list **lsta, t_list **lstb);

int					ft_lis(t_list **lst);

int					ft_sort(t_list **lst);

int					ft_nbnew(long long int nb, t_list **nba_lst);

long long int		ft_atol(const char *nptr);

void				inst_sa(t_list **list);

char				**ft_split(char const *s);

int					len_lst(t_list **lst);

int					get_rank(t_list **lst, int nb, int *ft_xtrem);

int					*ft_xtrem(t_list **lst);

void				ft_insersort(t_list **lsta, t_list **lstb);

void				ft_clean_rot(t_list **lsta, t_list **lstb);
#endif