/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:49:02 by bglover           #+#    #+#             */
/*   Updated: 2019/08/29 19:30:03 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;

	if (!alst)
		return ;
	if (!del)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		temp = (*alst)->next;
		free(*alst);
		(*alst)->content = NULL;
		*alst = temp;
	}
}
