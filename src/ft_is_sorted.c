/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 07:45:57 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:26:07 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	ft_is_sorted(t_stacks *stacks)
{
	t_stack	*temp;

	temp = stacks->stack_a;
	while (temp->next_element)
	{
		if (temp->value > temp->next_element->value)
			return (0);
		temp = temp->next_element;
	}
	return (1);
}
