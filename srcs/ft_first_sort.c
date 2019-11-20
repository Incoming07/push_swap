/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:39:47 by bglover           #+#    #+#             */
/*   Updated: 2019/11/20 16:30:51 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Если встретили в стеке б next
*/

void	ft_push_next(t_n_list **stack_a, t_n_list **stack_b, t_ps **new_ps,
		t_c_list **com_stack)
{
	(*stack_b)->flag = (*new_ps)->flag;
	ft_lstcomadd(com_stack, ft_lstcomnew(ft_pa(stack_a, stack_b)));
	ft_lstcomadd(com_stack, ft_lstcomnew(ft_ra(stack_a)));
	(*new_ps)->next++;
	ft_vis(stack_a, stack_b, new_ps);
}
