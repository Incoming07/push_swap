/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:15:58 by bglover           #+#    #+#             */
/*   Updated: 2019/11/08 22:28:24 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Если элемент выше цента, то делаем rra
*/

void	ft_part_1_1(n_list **stack_a, n_list **stack_b, c_list **com_stack)
{
	while (ft_calc_max(stack_a) != (*stack_a)->order)
		if (!*com_stack)
			*com_stack = ft_lstcomnew(ft_rra(stack_a));
		else
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_rra(stack_a)));
	if (!*com_stack)
		*com_stack = ft_lstcomnew(ft_pb(stack_a, stack_b));
	else
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_pb(stack_a, stack_b)));
}

/*
** Ищем два максимальных элемента и отпарвляем в стэк б
*/

void	ft_part_1(n_list **stack_a, n_list **stack_b, c_list **com_stack)
{
	while (ft_lstlens(stack_a) > 3)
	{
		if (ft_calc_max(stack_a) - 1 == (*stack_a)->order && (!*com_stack)
		&& ft_lstlens(stack_a) == 5)
			*com_stack = ft_lstcomnew(ft_pb(stack_a, stack_b));
		else if (ft_calc_max(stack_a) - 1 == (*stack_a)->order
		&& ft_lstlens(stack_a) == 5)
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pb(stack_a, stack_b)));
		else if (ft_calc_max(stack_a) == (*stack_a)->order && (!*com_stack))
			*com_stack = ft_lstcomnew(ft_pb(stack_a, stack_b));
		else if (ft_calc_max(stack_a) == (*stack_a)->order)
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pb(stack_a, stack_b)));
		else if (!*com_stack)
			*com_stack = ft_lstcomnew(ft_ra(stack_a));
		else
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
	}
}

/*
** Если числа не стоят по порядку, переставляем их
*/

void	ft_part_2(n_list **stack_a, c_list **com_stack)
{
	n_list	*t2;
	n_list	*t3;

	if (!*com_stack)
		*com_stack = ft_lstcomnew(NULL);
	t2 = (*stack_a)->next;
	t3 = t2->next;
	if ((*stack_a)->order > t2->order && (*stack_a)->order < t3->order)
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_sa(stack_a)));
	else if ((*stack_a)->order > t2->order && t2->order > t3->order)
	{
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_sa(stack_a)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_rra(stack_a)));
	}
	else if ((*stack_a)->order > t3->order && t2->order < t3->order)
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
	else if ((*stack_a)->order < t2->order && (*stack_a)->order < t3->order)
	{
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_sa(stack_a)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
	}
	else if ((*stack_a)->order < t2->order && (*stack_a)->order > t3->order)
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_rra(stack_a)));
}

/*
** Для двух чисел
*/

void		ft_for_two(n_list **stack_a, c_list **com_stack)
{
	n_list *t1;

	t1 = (*stack_a)->next;
	if ((*stack_a)->order > t1->order)
		*com_stack = ft_lstcomnew(ft_sa(stack_a));
}

/*
** Для 5 чисел и меньше
*/

void	ft_for_five(n_list **stack_a, n_list **stack_b, c_list **com_stack)
{
	n_list	*t2;
	n_list	*t3;

	if (ft_lstlens(stack_a) == 2)
		return (ft_for_two(stack_a, com_stack));
	ft_part_1(stack_a, stack_b, com_stack);
	t2 = (*stack_a)->next;
	t3 = t2->next;
	if (!((*stack_a)->order < t2->order && t2->order < t3->order))
		ft_part_2(stack_a, com_stack);
	if (*stack_b && ft_lstlens(stack_b) == 2)
	{
		t2 = (*stack_b)->next;
		if (t2->order > (*stack_b)->order)
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_rb(stack_b)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
	}
	else
	{
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
	}
}
