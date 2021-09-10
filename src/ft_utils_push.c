/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 14:57:00 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:32:17 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_set_new_min_max_b(t_stacks *stacks)
{
	t_stack	*temp;

	stacks->max_b = -2147483648;
	stacks->min_b = 2147483647;
	temp = stacks->stack_b;
	while (temp)
	{
		if (stacks->min_b > temp->value)
			stacks->min_b = temp->value;
		if (stacks->max_b < temp->value)
			stacks->max_b = temp->value;
		temp = temp->next_element;
	}
}

int	ft_search_top_count(t_stack *stack, int value)
{
	int	count_temp;

	count_temp = 0;
	if (stack->value == *stack->min && (value > *stack->max
			|| value < *stack->min))
		return (count_temp);
	while (stack->next_element)
	{
		count_temp++;
		if ((stack->value == *stack->max
				&& stack->next_element->value == *stack->min
				&& (value > *stack->max || value < *stack->min))
			|| (stack->value < value
				&& stack->next_element->value > value))
			return (count_temp);
		stack = stack->next_element;
	}
	if (count_temp + 1 == *stack->count)
		count_temp = 0;
	return (count_temp);
}

void	ft_move_for_push_b(t_stacks *stacks)
{
	int	count_temp;

	count_temp = ft_search_top_count(stacks->stack_b, stacks->stack_a->value);
	if (count_temp <= stacks->count_b / 2 + stacks->count_b % 2)
		while (count_temp-- > 0)
			ft_rotate_b(stacks);
	else
	{
		count_temp = stacks->count_b - count_temp;
		while (count_temp-- > 0)
			ft_reverse_rotate_b(stacks);
	}
}

void	ft_move_for_push_a(t_stacks *stacks)
{
	int	count_temp;

	count_temp = ft_search_top_count(stacks->stack_a, stacks->stack_b->value);
	if (count_temp <= stacks->count_a / 2)
		while (count_temp-- > 0)
			ft_rotate_a(stacks);
	else
	{
		count_temp = stacks->count_a - count_temp;
		while (count_temp-- > 0)
			ft_reverse_rotate_a(stacks);
	}
}
