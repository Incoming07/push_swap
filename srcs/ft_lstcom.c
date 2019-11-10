/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:41:10 by bglover           #+#    #+#             */
/*   Updated: 2019/10/31 21:07:16 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Добавление листа с командой в конец списка
*/

void	ft_lstcomadd(c_list **com_list_old, c_list *com_list_new)
{
	c_list *temp;

	if (!(*com_list_old))
		return ;
	else
	{
		temp = (*com_list_old);
		while ((*com_list_old)->next != NULL)
			(*com_list_old) = (*com_list_old)->next;
		(*com_list_old)->next = com_list_new;
		(*com_list_old) = temp;
	}
}

/*
** Создание листа с командой
*/

c_list	*ft_lstcomnew(char *com)
{
	c_list *com_lst;

	com_lst = (c_list *)malloc(sizeof(c_list));
	com_lst->com = com;
	com_lst->next = NULL;
	return (com_lst);
}

/*
** Длинна двусвязанного списка
*/

int		ft_lstlens(n_list **stack_a)
{
	n_list	*temp;
	int		i;

	i = 0;
	if (!(*stack_a))
		return (-1);
	temp = *stack_a;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

/*
** Создание двусвязанного листа
*/

n_list	*ft_lstnews(long long value)
{
	n_list *n_list_1;

	n_list_1 = (n_list *)malloc(sizeof(n_list));
	if (!n_list_1)
		return (NULL);
	n_list_1->value = value;
	n_list_1->order = 0;
	n_list_1->flag = 0;
	n_list_1->sort = 0;
	n_list_1->next = NULL;
	n_list_1->previous = NULL;
	return (n_list_1);
}

/*
** Создание двусвязаного списка
*/

void	ft_lstadds(n_list **first, n_list *second)
{
	n_list *temp_1;
	n_list *temp_2;

	if (!first)
		return ;
	if (!second)
		return ;
	temp_1 = *first;
	while (temp_1->next)
		temp_1 = temp_1->next;
	temp_2 = temp_1;
	temp_2->next = second;
	temp_2 = temp_2->next;
	temp_2->previous = temp_1;
	temp_2->next = NULL;
}
