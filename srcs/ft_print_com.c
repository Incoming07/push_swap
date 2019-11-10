/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:44:27 by bglover           #+#    #+#             */
/*   Updated: 2019/11/09 21:09:46 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Поиск возможных замен и печать результатов
*/

void	ft_print_com(c_list **com_stack)
{
	c_list	*com_stack_temp;
	c_list	*com_stack_first;

	com_stack_first = (*com_stack);
	while ((*com_stack)->next)
	{
		com_stack_temp = (*com_stack);
		(*com_stack) = (*com_stack)->next;
		if (com_stack_temp->com && (!ft_strcmp(com_stack_temp->com, "ra\n") &&
		!ft_strcmp((*com_stack)->com, "rb\n")))
		{
			com_stack_temp->com = NULL;
			(*com_stack)->com = "rr\n";
		}
		if (com_stack_temp->com && (!ft_strcmp(com_stack_temp->com, "sa\n") &&
		!ft_strcmp((*com_stack)->com, "sb\n")))
		{
			com_stack_temp->com = NULL;
			(*com_stack)->com = "ss\n";
		}
	}
	(*com_stack) = com_stack_first;
	while (com_stack_first)
		if (com_stack_first->com)
		{
			write(1, com_stack_first->com, ft_strlen(com_stack_first->com));
			com_stack_first = com_stack_first->next;
		}
		else
			com_stack_first = com_stack_first->next;
}
