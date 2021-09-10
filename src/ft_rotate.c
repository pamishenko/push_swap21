/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:09:36 by ttanja            #+#    #+#             */
/*   Updated: 2021/08/29 11:02:43 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_stack	*ft_rotate(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next_element)
		temp = temp->next_element;
	temp->next_element = stack;
	stack->previous_element = temp;
	stack = stack->next_element;
	stack->previous_element = NULL;
	temp->next_element->next_element = NULL;
	return (stack);
}

int	ft_rotate_a(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (stacks->count_a < 2)
		return (1);
	stacks->stack_a = ft_rotate(stacks->stack_a);
	ft_set_instruction(stacks, "ra");
	return (0);
}

int	ft_rotate_b(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (stacks->count_b < 2)
		return (1);
	stacks->stack_b = ft_rotate(stacks->stack_b);
	ft_set_instruction(stacks, "rb");
	return (0);
}

int	ft_rotate_ab(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (stacks->count_a > 1)
		stacks->stack_a = ft_rotate(stacks->stack_a);
	if (stacks->count_b > 1)
		stacks->stack_b = ft_rotate(stacks->stack_b);
	ft_set_instruction(stacks, "rr");
	return (0);
}
