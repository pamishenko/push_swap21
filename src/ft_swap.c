/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:08:04 by ttanja            #+#    #+#             */
/*   Updated: 2021/08/29 11:02:43 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_stack	*ft_swap(t_stack *stack)
{
	t_stack	*temp;

	temp = (stack)->next_element;
	if ((stack)->next_element->next_element)
	{
		(stack)->next_element = (stack)->next_element->next_element;
		(stack)->next_element->previous_element = (stack);
	}
	else
		(stack)->next_element = NULL;
	temp->next_element = (stack);
	(stack)->previous_element = temp;
	temp->previous_element = NULL;
	return (temp);
}

int	ft_swap_a(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (stacks->count_a > 1)
		stacks->stack_a = ft_swap(stacks->stack_a);
	ft_set_instruction(stacks, "sa");
	return (0);
}

int	ft_swap_b(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (stacks->count_b > 1)
		stacks->stack_b = ft_swap(stacks->stack_b);
	ft_set_instruction(stacks, "sb");
	return (0);
}

int	ft_swab_ab(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (stacks->count_a > 1)
		stacks->stack_a = ft_swap(stacks->stack_a);
	if (stacks->count_b > 1)
		stacks->stack_b = ft_swap(stacks->stack_b);
	ft_set_instruction(stacks, "ss");
	return (0);
}
