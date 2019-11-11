/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:43:51 by bglover           #+#    #+#             */
/*   Updated: 2019/11/11 19:27:24 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Проверка правильности сортировки
*/

int		ft_check_sort(t_n_list **stack_a, t_ps **new_ps)
{
	int			i;
	t_n_list	*stack_temp;

	i = 0;
	if (!(*stack_a))
		return (1);
	stack_temp = (*stack_a);
	while (++i == stack_temp->order && (*new_ps)->max != i)
		stack_temp = stack_temp->next;
	return (i == (*new_ps)->max ? 0 : 1);
}
