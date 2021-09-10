/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:23:07 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:06:13 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_stack	*ft_get_first_element_stack(t_stack *stack)
{
	while (stack->previous_element)
		stack = stack->previous_element;
	return (stack);
}

t_stack	*ft_get_last_element_stack(t_stack *stack)
{
	while (stack->next_element)
		stack = stack->next_element;
	return (stack);
}

t_stack	*ft_get_last_element(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next_element)
		temp = temp->next_element;
	return (temp);
}

void	ft_init_base(t_stacks *stacks)
{
	if (!stacks->stack_a)
		return ;
	if (stacks->count_a > 0 && stacks->count_a <= 30)
		stacks->base = 1;
	if (stacks->count_a > 30 && stacks->count_a <= 70 )
		stacks->base = 2;
	if (stacks->count_a > 70 && stacks->count_a <= 120)
		stacks->base = 3;
	if (stacks->count_a > 120 && stacks->count_a <= 250)
		stacks->base = 5;
	if (stacks->count_a > 250 && stacks->count_a <= 700)
		stacks->base = 4;
	if (stacks->count_a > 700)
		stacks->base = 15;
}

void	ft_set_base(t_stacks *stacks)
{
	t_stack	*temp;
	int		base_step;
	long	somenumber;

	if (stacks->min < 0)
		somenumber = stacks->min * -1;
	else
		somenumber = 0;
	base_step = (stacks->max + somenumber) / stacks->base;
	temp = stacks->stack_a;
	while (temp)
	{
		temp->is_base = (temp->value + somenumber) / base_step;
		temp = temp->next_element;
	}
}
