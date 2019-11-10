/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:51:36 by bglover           #+#    #+#             */
/*   Updated: 2019/11/08 20:26:04 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Основная сортировка стка б!
** Сортировка остатков стэка
*/

void	ft_last_three(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	if (ft_lstlens(stack_b) <= 3)
	{
		if (ft_lstlens(stack_b) == 2)
		{
			(*new_ps)->i = (*stack_b)->order;
			(*stack_b) = (*stack_b)->next;
			if ((*new_ps)->i < (*stack_b)->order)
			{
				(*stack_b) = (*stack_b)->previous;
				ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
				ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
				(*new_ps)->next++;
			}
			else
				(*stack_b) = (*stack_b)->previous;
		}
		else if (ft_lstlens(stack_b) == 3)
			ft_for_three(stack_b, com_stack);
		while (*stack_b)
		{
			(*stack_b)->flag = (*new_ps)->flag;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		}
	}
}

/*
** Либо скидываем в стэк а либо прокручиваем
*/

void	ft_push_rotate(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	if ((*stack_b)->order == (*new_ps)->next)
	{
		(*stack_b)->flag = (*new_ps)->flag;
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
		(*new_ps)->next++;
	}
	else
	{
		(*stack_b)->sort = 1;
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_rb(stack_b)));
	}
}

/*
** Начало основной сортировки стэка б
*/

void	ft_start_sort_b(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	int mid;
	int max;

	max = ft_calc_max(stack_b);
	mid = (max - (*new_ps)->next) / 2 + (*new_ps)->next;
	(*new_ps)->flag++;
	while (*stack_b && (*stack_b)->sort == 0 && ft_lstlens(stack_b) > 3)
	{
		if ((*stack_b)->order <= mid && ft_lstlens(stack_b) > 2)
			ft_push_rotate(stack_a, stack_b, new_ps, com_stack);
		else if ((*stack_b)->order >= mid && ft_lstlens(stack_b) > 2)
		{
			(*stack_b)->flag = (*new_ps)->flag;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		}
	}
	ft_last_three(stack_a, stack_b, new_ps, com_stack);
	return ;
}
