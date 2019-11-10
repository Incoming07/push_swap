/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:09:02 by bglover           #+#    #+#             */
/*   Updated: 2019/11/01 18:44:23 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Продолжаем искать совпадение команды
*/

void	gnl_end(n_list **stack_a, n_list **stack_b, char **line)
{
	if (!ft_strcmp(*line, "rr"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(*line, "rrb"))
		ft_rrb(stack_b);
	else if (!ft_strcmp(*line, "rra"))
		ft_rra(stack_a);
	else if (!ft_strcmp(*line, "rrr"))
		ft_rrr(stack_a, stack_b);
	else
		write(1, "Error\n", 6);
}

/*
** Раскидываем действия относительно поданной команды
*/

void	gnl_begin(n_list **stack_a, n_list **stack_b)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp(line, "pb"))
			ft_pb(stack_a, stack_b);
		else if (!ft_strcmp(line, "pa"))
			ft_pa(stack_a, stack_b);
		else if (!ft_strcmp(line, "sb"))
			ft_sb(stack_b);
		else if (!ft_strcmp(line, "sa"))
			ft_sa(stack_a);
		else if (!ft_strcmp(line, "ra"))
			ft_ra(stack_a);
		else if (!ft_strcmp(line, "rb"))
			ft_rb(stack_b);
		else
			gnl_end(stack_a, stack_b, &line);
		free(line);
	}
}

/*
** обрабатываем аргументы и применяем команды на стеке
** с помощью гнл
*/

int		main(int argc, char **argv)
{
	n_list	*stack_a;
	n_list	*stack_b;
	c_list	*com_stack;
	ps		*new_ps;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_parse(argv, argc, &stack_a))
	{
		ft_free_all(&stack_a, &stack_b, &new_ps, &com_stack);
		return (write(1, "Error\n", 6));
	}
	new_ps = ft_init_ps(&stack_a);
	gnl_begin(&stack_a, &stack_b);
	if (!ft_check_sort(&stack_a, &new_ps))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_all(&stack_a, &stack_b, &new_ps, &com_stack);
	return (0);
}
