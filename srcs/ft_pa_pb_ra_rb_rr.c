/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb_ra_rb_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:06:38 by bglover           #+#    #+#             */
/*   Updated: 2019/11/08 22:00:01 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Переносит первый э-т stack_a в stack_b
*/

char	*ft_pa(n_list **stack_a, n_list **stack_b)
{
	n_list	*temp_1;
	
	if (!(*stack_b))
		return (NULL);
	if (!*stack_a)
	{
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->previous = NULL;
		(*stack_a)->next = NULL;
	}
	else
	{
		temp_1 = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		if (*stack_b)
			(*stack_b)->previous = NULL;
		(*stack_a)->next = temp_1;
		temp_1->previous = *stack_a;
	}
	return ((char *)"pa\n");
}

/*
** Переносит первый э-т stack_b в stack_a
*/

char	*ft_pb(n_list **stack_a, n_list **stack_b)
{
	n_list	*temp_1;

	if (!(*stack_a))
		return (NULL);
	if (!*stack_b)
	{
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_a)->previous = NULL;
		(*stack_b)->next = NULL;
	}
	else
	{
		temp_1 = *stack_b;
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_a)
			(*stack_a)->previous = NULL;
		(*stack_b)->next = temp_1;
		temp_1->previous = *stack_b;
	}
	return ((char *)"pb\n");
}

/*
** Ставит первый эл-т в конец списка a
*/

char	*ft_ra(n_list **stack_a)
{
	n_list	*temp_1;
	n_list	*temp_2;
	
	if (ft_lstlens(stack_a) < 2)
		return (NULL);
	temp_1 = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	temp_2 = *stack_a;
	while (temp_2->next != NULL)
		temp_2 = temp_2->next;
	temp_2->next = temp_1;
	temp_1->previous = temp_2;
	temp_1->next = NULL;
	return ((char *)"ra\n");
}

/*
** Ставит первый эл-т в конец списка б
*/

char	*ft_rb(n_list **stack_b)
{
	n_list	*temp_1;
	n_list	*temp_2;

	if (ft_lstlens(stack_b) < 2)
		return (NULL);
	temp_1 = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->previous = NULL;
	temp_2 = *stack_b;
	while (temp_2->next != NULL)
		temp_2 = temp_2->next;
	temp_2->next = temp_1;
	temp_1->previous = temp_2;
	temp_1->next = NULL;
	return ((char *)"rb\n");
}

/*
** Ставит первый эл-т в конец списка одновременно в двух стэках
*/

char	*ft_rr(n_list **stack_a, n_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	return ((char *)"rr\n");
}
