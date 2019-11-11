/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:37:27 by bglover           #+#    #+#             */
/*   Updated: 2019/11/11 18:37:06 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Чистим список команд
*/

void	ft_free_com(t_c_list **com_stack)
{
	t_c_list	*temp_1;

	while ((*com_stack)->next)
	{
		(temp_1) = (*com_stack);
		(*com_stack) = (*com_stack)->next;
		free(temp_1);
	}
	free(*com_stack);
}

/*
** чистка стэка б
*/

void	ft_free_stack_b(t_n_list **stack_b)
{
	t_n_list	*temp_2;

	while ((*stack_b)->next)
	{
		temp_2 = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp_2);
	}
	free(*stack_b);
}

/*
** Финальная очистка
*/

int		ft_free_all(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	free(*new_ps);
	if (*stack_b)
		ft_free_stack_b(stack_b);
	if (*stack_a)
	{
		while ((*stack_a)->next)
		{
			*stack_b = *stack_a;
			*stack_a = (*stack_a)->next;
			free(*stack_b);
		}
		free(*stack_a);
	}
	if (*com_stack)
		ft_free_com(com_stack);
	return (0);
}

/*
** Чистка temp от splita при вводе некорректных данных
** в строке
*/

int		ft_free_temp(char **temp, int i)
{
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (0);
}
