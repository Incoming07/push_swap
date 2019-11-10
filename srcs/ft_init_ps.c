/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:57:57 by bglover           #+#    #+#             */
/*   Updated: 2019/10/27 18:10:39 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

ps	*ft_init_ps(n_list **stack_a)
{
	ps *new_ps;

	new_ps = (ps *)malloc(sizeof(ps));
	new_ps->next = 1;
	new_ps->max = ft_fill_order(stack_a);
	new_ps->flag = 1;
	new_ps->i = 0;
	return (new_ps);
}
