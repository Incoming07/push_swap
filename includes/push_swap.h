/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:06:39 by bglover           #+#    #+#             */
/*   Updated: 2019/11/01 18:09:38 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef	struct		for_ps
{
	int				next;
	int				max;
	int				flag;
	int				i;
}					ps;

typedef	struct		com_list
{
	char			*com;
	struct com_list	*next;
}					c_list;

typedef	struct		num_list
{
	struct num_list	*previous;
	long long		value;
	int				order;
	int				sort;
	int				flag;
	struct num_list	*next;
}					n_list;

char				*ft_pa(n_list **stack_a, n_list **stack_b);
char				*ft_pb(n_list **stack_a, n_list **stack_b);
char				*ft_ra(n_list **stack_a);
char				*ft_rb(n_list **stack_b);
char				*ft_rr(n_list **stack_a, n_list **stack_b);
char				*ft_rra(n_list **stack_a);
char				*ft_rrb(n_list **stack_b);
char				*ft_rrr(n_list **stack_a, n_list **stack_b);
char				*ft_sa(n_list **stack_a);
char				*ft_sb(n_list **stack_b);
c_list				*ft_lstcomnew(char *com);
n_list				*ft_lstnews(long long value);
int					ft_lstlens(n_list **lst);
void				ft_lstadds(n_list **first, n_list *second);
void				ft_lstcomadd(c_list **com_list_old, c_list *com_list_new);
void				ft_for_three(n_list **stack_b, c_list **com_stack);
int					ft_fill_order(n_list **stack_a);
int					ft_calc_max(n_list **stack);
int					ft_check_sort(n_list **stack_a, ps **new_ps);
int					ft_parse(char **argv, int argc, n_list **stack_a);
int					ft_free_temp(char **temp, int i);
void				ft_start_sort_a(n_list **stack_a, n_list **stack_b,
					ps **new_ps,
					c_list **com_stack);
void				ft_start_sort_b(n_list **stack_a, n_list **stack_b,
					ps **new_ps,
					c_list **com_stack);
void				ft_print_com(c_list **com_stack);
void				ft_free_all(n_list **stack_a, n_list **stack_b, ps **new_ps,
					c_list **com_stack);
void				ft_for_five(n_list **stack_a, n_list **stack_b,
					c_list **com_stack);
ps					*ft_init_ps(n_list **stack_a);

#endif
