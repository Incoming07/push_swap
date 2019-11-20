/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:51:36 by bglover           #+#    #+#             */
/*   Updated: 2019/11/19 22:25:26 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Если один элемент
*/

void	ft_if_one(t_n_list **stack_a, t_n_list **stack_b, t_c_list **com_stack,
		t_ps **new_ps)
{
	if (ft_lstlens(stack_b) == 1)
	{
		(*stack_b)->flag = (*new_ps)->flag;
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		ft_vis(stack_a, stack_b, new_ps);
	}
}

/*
**  Сортировка двух элементов
*/

void	ft_two_two(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	(*stack_b) = (*stack_b)->previous;
	ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
	ft_vis(stack_a, stack_b, new_ps);
	ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
	(*new_ps)->next++;
	ft_vis(stack_a, stack_b, new_ps);
}

/*
** Основная сортировка стка б!
** Сортировка остатков стэка
*/

void	ft_last_three(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	if (ft_lstlens(stack_b) <= 3)
	{
		ft_if_one(stack_a, stack_b, com_stack, new_ps);
		if (ft_lstlens(stack_b) == 2)
		{
			(*new_ps)->i = (*stack_b)->order;
			(*stack_b) = (*stack_b)->next;
			if ((*new_ps)->i < (*stack_b)->order)
				ft_two_two(stack_a, stack_b, new_ps, com_stack);
			else
				(*stack_b) = (*stack_b)->previous;
		}
		else if (ft_lstlens(stack_b) == 3)
			ft_for_three(stack_b, com_stack);
		while (*stack_b)
		{
			(*stack_b)->flag = (*new_ps)->flag;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
			ft_vis(stack_a, stack_b, new_ps);
		}
	}
}

/*
** Либо скидываем в стэк а либо прокручиваем
*/

void	ft_push_rotate(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	if ((*stack_b)->order == (*new_ps)->next)
	{
		(*stack_b)->flag = (*new_ps)->flag;
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
		ft_vis(stack_a, stack_b, new_ps);
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
		(*new_ps)->next++;
		ft_vis(stack_a, stack_b, new_ps);
	}
	else
	{
		(*stack_b)->sort = 1;
		ft_lstcomadd(com_stack, ft_lstcomnew(ft_rb(stack_b)));
		ft_vis(stack_a, stack_b, new_ps);
	}
}

/*
** Начало основной сортировки стэка б
*/

void	ft_start_sort_b(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	int mid;
	int max;

	max = ft_calc_max(stack_b);
	mid = (max - (*new_ps)->next) / 2 + (*new_ps)->next;
	(*new_ps)->flag++;
	while (*stack_b && (*stack_b)->sort == 0 && ft_lstlens(stack_b) >
	(ft_calc_max(stack_a) > 100 ? 3 : 2))
		if ((*stack_b)->order <= mid && ft_lstlens(stack_b) > 2)
			ft_push_rotate(stack_a, stack_b, new_ps, com_stack);
		else if ((*stack_b)->order > mid && ft_lstlens(stack_b) > 2)
		{
			(*stack_b)->flag = (*new_ps)->flag;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
			ft_vis(stack_a, stack_b, new_ps);
		}
	ft_last_three(stack_a, stack_b, new_ps, com_stack);
	ft_vis(stack_a, stack_b, new_ps);
	return ;
}
