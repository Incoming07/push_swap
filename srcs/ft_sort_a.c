/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:17:43 by bglover           #+#    #+#             */
/*   Updated: 2019/11/10 23:09:28 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Основная сортировка стэка а!
** Если сортируем вторую половину
*/

int		second_half(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	int i;
	int flag;
	int mid;

	i = 0;
	flag = (*stack_a)->flag;
	mid = ((*new_ps)->max - (*new_ps)->next) / 2 + (*new_ps)->next;
	while ((*stack_a)->flag == flag)
		if ((i == 0) && ((*stack_a)->order == (*new_ps)->next))
		{
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
			(*new_ps)->next++;
		}
		else if ((*stack_a)->order <= mid)
		{
			(*stack_a)->sort = 1;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pb(stack_a, stack_b)));
		}
		else if ((*stack_a)->order >= mid)
		{
			(*stack_a)->flag = (*new_ps)->flag;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
			i++;
		}
	return (i);
}

/*
** Прокрутка обратно после половины (перекрыли стек)
*/

void	wheel_of_fortune(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	while ((*new_ps)->i--)
		if ((*stack_b) && (*stack_b)->order != (*new_ps)->next)
		{
			ft_rra(stack_a);
			ft_rrb(stack_b);
			ft_lstcomadd(com_stack, ft_lstcomnew((char *)"rrr\n"));
		}
		else
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_rra(stack_a)));
	while (*stack_b && (*stack_b)->sort == 1)
	{
		(*stack_b)->sort = 0;
		ft_rb(stack_b);
	}
}

/*
** Начало сортировки и сортировка до первой половины
** (пока не перекрываем стэк снизу)
*/

void	ft_start_sort_a(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	int flag;
	int mid;

	(*new_ps)->i = 0;
	flag = (*stack_a)->flag;
	mid = ((*new_ps)->max - (*new_ps)->next) / 2 + (*new_ps)->next;
	if ((*new_ps)->next > (*new_ps)->max / 2)
	{
		(*new_ps)->flag++;
		(*new_ps)->i = second_half(stack_a, stack_b, new_ps, com_stack);
		wheel_of_fortune(stack_a, stack_b, new_ps, com_stack);
		return ;
	}
	while ((*stack_a)->flag == flag)
		if ((*stack_a)->order == (*new_ps)->next)
		{
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
			(*new_ps)->next++;
			(*new_ps)->i++;
		}
		else
		{
			(*stack_a)->sort = 0;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pb(stack_a, stack_b)));
		}
}
