/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:43:51 by bglover           #+#    #+#             */
/*   Updated: 2019/11/08 21:56:32 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Проверка правильности сортировки
*/

int		ft_check_sort(n_list **stack_a, ps **new_ps)
{
	int		i;
	n_list	*stack_temp;

	i = 0;
	if (!(*stack_a))
		return (1);
	stack_temp = (*stack_a);
	while (++i == stack_temp->order && (*new_ps)->max != i)
		stack_temp = stack_temp->next;
	return (i == (*new_ps)->max ? 0 : 1);
}
