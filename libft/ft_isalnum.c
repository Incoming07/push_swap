/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:46:57 by bglover           #+#    #+#             */
/*   Updated: 2019/05/04 17:46:59 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	return (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
	(c >= '0' && c <= '9')) ? 1 : 0);
}