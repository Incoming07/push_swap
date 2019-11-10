/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:42:51 by bglover           #+#    #+#             */
/*   Updated: 2019/10/25 20:56:54 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Нахождение максимального элемента стэка
*/

int		ft_calc_max(n_list **stack)
{
	n_list	*temp;
	int		i;

	i = 0;
	temp = (*stack);
	while (temp)
	{
		if (temp->order > i)
			i = temp->order;
		temp = temp->next;
	}
	return (i);
}
