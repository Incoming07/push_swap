/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:16:12 by bglover           #+#    #+#             */
/*   Updated: 2019/11/10 23:08:42 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <float.h>

/*
** Первая сортировка стэка_а
*/

int		ft_first_sort_a(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	int i;
	int mid;

	i = 0;
	mid = ((*new_ps)->max - (*new_ps)->next) / 2 + (*new_ps)->next;
	(*new_ps)->flag++;
	while (++i <= (*new_ps)->max && (ft_lstlens(stack_b) < mid))
		if ((*stack_a)->order <= mid)
		{
			if (!*com_stack)
				*com_stack = ft_lstcomnew(ft_pb(stack_a, stack_b));
			else
				ft_lstcomadd(com_stack, ft_lstcomnew(ft_pb(stack_a, stack_b)));
		}
		else if ((*new_ps)->next == 1)
		{
			if (!*com_stack)
				*com_stack = ft_lstcomnew(ft_ra(stack_a));
			else
				ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
		}
	return (0);
}

/*
** Начало сортировки
*/

void	ft_start_sort(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	while (ft_check_sort(stack_a, new_ps))
	{
		while ((*stack_b) && (*stack_b)->sort == 1)
		{
			(*stack_b)->sort = 0;
			ft_rb(stack_b);
		}
		if (!*stack_b)
			ft_start_sort_a(stack_a, stack_b, new_ps, com_stack);
		while (*stack_b && (*stack_b)->order == (*new_ps)->next)
		{
			(*stack_b)->flag = (*new_ps)->flag;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
			(*new_ps)->next++;
		}
		ft_start_sort_b(stack_a, stack_b, new_ps, com_stack);
		while ((*stack_a)->order == (*new_ps)->next)
		{
			(*stack_a)->flag = (*new_ps)->flag;
			ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
			(*new_ps)->next++;
		}
	}
}

/*
** начало главная сортировки
*/

void	ft_main_sort(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	ft_first_sort_a(stack_a, stack_b, new_ps, com_stack);
	ft_start_sort(stack_a, stack_b, new_ps, com_stack);
	ft_print_com(com_stack);
	ft_free_all(stack_a, stack_b, new_ps, com_stack);
}

/*
** Для пяти чисел
*/

void	ft_five(n_list **stack_a, n_list **stack_b, ps **new_ps,
		c_list **com_stack)
{
	ft_for_five(stack_a, stack_b, com_stack);
	ft_print_com(com_stack);
	ft_free_all(stack_a, stack_b, new_ps, com_stack);
}

/*
** Заполнение двусвязаного списка
*/

int		main(int argc, char **argv)
{
	n_list	*stack_a;
	n_list	*stack_b;
	c_list	*com_stack;
	ps		*new_ps;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (write(1, "\n", 1));
	if (!ft_parse(argv, argc, &stack_a))
	{
		ft_free_all(&stack_a, &stack_b, &new_ps, &com_stack);
		if (ft_lstlens(&stack_a) == 1)
			return (0);
		return (write(1, "Error\n", 6));
	}
	new_ps = ft_init_ps(&stack_a);
	if (!ft_check_sort(&stack_a, &new_ps))
		return (0);
	if (ft_lstlens(&stack_a) <= 5)
		ft_five(&stack_a, &stack_b, &new_ps, &com_stack);
	ft_main_sort(&stack_a, &stack_b, &new_ps, &com_stack);
	return (0);
}
