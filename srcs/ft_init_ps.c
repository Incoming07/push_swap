/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:57:57 by bglover           #+#    #+#             */
/*   Updated: 2019/11/11 18:37:19 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps	*ft_init_ps(t_n_list **stack_a)
{
	t_ps *new_ps;

	new_ps = (t_ps *)malloc(sizeof(t_ps));
	new_ps->next = 1;
	new_ps->max = ft_fill_order(stack_a);
	new_ps->flag = 1;
	new_ps->i = 0;
	return (new_ps);
}
