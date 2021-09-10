/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:53:13 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:27:48 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	ft_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next_element;
	}
	return (max);
}

void	ft_sort_3_element(t_stacks *stacks)
{
	int	max;

	max = ft_max(stacks->stack_a);
	if (stacks->count_a == 1)
		return ;
	else if (stacks->count_a == 2)
	{
		if (stacks->stack_a->value > stacks->stack_a->next_element->value)
			ft_swap_a(stacks);
		return ;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->stack_a->value == max)
			ft_rotate_a(stacks);
		if (stacks->stack_a->next_element->value == max)
			ft_reverse_rotate_a(stacks);
		if (stacks->stack_a->value > stacks->stack_a->next_element->value)
			ft_swap_a(stacks);
	}
}

void	ft_sort_5_element(t_stacks *stacks)
{
	while (stacks->count_b < 2)
	{
		if (stacks->stack_a->value == stacks->min || stacks->stack_a->value
			== stacks->max)
			ft_push_b2(stacks);
		else
			ft_rotate_a(stacks);
	}
	ft_sort_3_element(stacks);
	ft_push_a(stacks);
	ft_push_a(stacks);
	if (stacks->stack_a->value == stacks->max)
		ft_rotate_a(stacks);
	else
	{
		ft_swap_a(stacks);
		ft_rotate_a(stacks);
	}
}

void	ft_normalize_a(t_stacks *stacks)
{
	t_stack	*temp;
	int		count;

	count = 0;
	temp = stacks->stack_a;
	while (temp->value != stacks->min && temp->next_element)
	{
		count++;
		temp = temp->next_element;
	}
	if (count <= stacks->count_a / 2)
		while (count--)
			ft_rotate_a(stacks);
	else
	{
		count = stacks->count_a - count;
		while (count--)
			ft_reverse_rotate_a(stacks);
	}
}

int	ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		ft_sort_3_element(stacks);
	else if (stacks->count_a > 3 && stacks->count_a <= 5)
		ft_sort_5_element(stacks);
	else
	{
		ft_move_a2b_element(stacks);
		while (stacks->stack_b)
			ft_push_a(stacks);
	}
	ft_normalize_a(stacks);
	return (0);
}
