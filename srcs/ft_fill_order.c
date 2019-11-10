/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:45:11 by bglover           #+#    #+#             */
/*   Updated: 2019/10/25 20:57:07 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Предварительная сортировка и присвоение порядковых номеров элементам
*/

int		ft_fill_order(n_list **stack_a)
{
	n_list	*temp_1;
	n_list	*tmp_2;
	int		i;

	i = 1;
	while (i <= ft_lstlens(stack_a))
	{
		tmp_2 = NULL;
		temp_1 = *stack_a;
		while (temp_1->order)
			temp_1 = temp_1->next;
		tmp_2 = temp_1;
		temp_1 = *stack_a;
		while (temp_1)
		{
			if (temp_1->order == 0 && (temp_1->value < tmp_2->value))
				tmp_2 = temp_1;
			temp_1 = temp_1->next;
		}
		tmp_2->order = i++;
	}
	return (i - 1);
}
