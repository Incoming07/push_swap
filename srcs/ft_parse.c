/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:38:14 by bglover           #+#    #+#             */
/*   Updated: 2019/11/11 18:38:10 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Проверка на корректность вовда цифр
*/

int		ft_check_words(char *word)
{
	int i;

	i = 0;
	while (word[i] != '\0')
		if (word[i] == '-' && i == 0 && ft_strlen(word) > 1)
			i++;
		else if (!ft_isdigit(word[i++]))
			return (1);
	return (0);
}

/*
** Проверка на одинаковые вхождения
*/

int		ft_check_dup(t_n_list **stack_a, int nmb)
{
	t_n_list *tmp;

	tmp = (*stack_a);
	while ((*stack_a))
	{
		if (nmb == (*stack_a)->value)
		{
			(*stack_a) = tmp;
			return (0);
		}
		(*stack_a) = (*stack_a)->next;
	}
	(*stack_a) = tmp;
	return (1);
}

/*
** Парсер значений
*/

int		not_string(char **argv, int argc, t_n_list **stack_a)
{
	int i;

	i = 0;
	while (i++ < argc - 1)
	{
		if (ft_strlen(argv[i]) > 12 || ft_check_words(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) < -2147483649)
			return (0);
		if (ft_atoi(argv[i]) > 2147483648)
			return (0);
		if (i == 1)
			*stack_a = ft_lstnews(ft_atoi(argv[i]));
		else
		{
			if (!ft_check_dup(stack_a, ft_atoi(argv[i])))
				return (0);
			ft_lstadds(stack_a, ft_lstnews(ft_atoi(argv[i])));
		}
	}
	return (1);
}

/*
** Проверки строки
*/

int		ft_check_str(t_n_list **stack_a, char **temp, int i, char **argv)
{
	if (argv[1][ft_strlen(argv[1]) - 1] == ' ')
		return (0);
	temp = ft_strsplit(argv[1], ' ');
	while (temp[i])
	{
		if (ft_check_words(temp[i]))
			return (ft_free_temp(temp, i));
		if (ft_strlen(temp[i]) > 12)
			return (ft_free_temp(temp, i));
		if (ft_atoi(temp[i]) < -2147483649)
			return (ft_free_temp(temp, i));
		if (ft_atoi(temp[i]) > 2147483648)
			return (ft_free_temp(temp, i));
		if (i == 0)
			(*stack_a) = ft_lstnews(ft_atoi(&temp[i][0]));
		else
		{
			if (!ft_check_dup(stack_a, ft_atoi(temp[i])))
				return (ft_free_temp(temp, i));
			ft_lstadds(stack_a, ft_lstnews(ft_atoi(&temp[i][0])));
		}
		free(temp[i++]);
	}
	free(temp);
	return (i);
}

/*
** Парсер строки
*/

int		ft_parse(char **argv, int argc, t_n_list **stack_a)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	if (argc == 2)
	{
		i = ft_check_str(stack_a, temp, i, argv) - 1;
		if (i < 1)
			return (0);
	}
	else
		return (not_string(argv, argc, stack_a));
	return (1);
}
