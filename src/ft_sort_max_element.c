/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_max_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:41:12 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:25:56 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	ft_steps2a(t_stacks *stacks, int value)
{
	int		count;
	t_stack	*temp_a;

	count = 0;
	temp_a = stacks->stack_a;
	while (temp_a->next_element)
	{
		if (temp_a->value < value && temp_a->next_element->value > value)
			break ;
		if (!count && temp_a->value > value
			&& ft_get_last_element_stack(temp_a)->value < value)
			break ;
		count++;
		temp_a = temp_a->next_element;
	}
	if (count <= stacks->count_a / 2)
		return (count);
	else
		return (stacks->count_a - count);
}

void	ft_set_steps(t_stacks *stacks)
{
	int		i;
	t_stack	*temp_b;

	temp_b = stacks->stack_b;
	i = 0;
	while (i < stacks->count_b)
	{
		if (i <= stacks->count_b / 2)
			temp_b->step = ft_steps2a(stacks, temp_b->value) + i;
		else
			temp_b->step = ft_steps2a(stacks, temp_b->value)
				+ stacks->count_b - i;
		temp_b = temp_b->next_element;
		i++;
	}
}

int	ft_found_min_step(t_stacks *stacks)
{
	t_stack	*temp;
	int		count;
	int		position;
	int		min;

	ft_set_steps(stacks);
	temp = stacks->stack_b;
	position = 0;
	count = 0;
	min = 999999;
	while (temp)
	{
		if (temp->step < min)
		{
			position = count;
			min = temp->step;
		}
		temp = temp->next_element;
		count++;
	}
	return (position);
}

void	ft_move_2a(t_stacks *stacks)
{
	int	steps;

	steps = 0;
	while (stacks->count_b)
	{
		steps = ft_found_min_step(stacks);
		if (steps <= stacks->count_b / 2)
			while (steps-- > 0)
				ft_rotate_b(stacks);
		else
		{
			steps = stacks->count_b - steps;
			while (steps-- > 0)
				ft_reverse_rotate_b(stacks);
		}
		ft_push_a2(stacks);
	}
}

void	ft_move_a2b_element(t_stacks *stacks)
{
	ft_set_med(stacks);
	while (stacks->count_a > 2)
	{
		if (stacks->stack_a->value != stacks->min && stacks->stack_a->value
			!= stacks->max)
		{
			ft_push_b2(stacks);
			if (stacks->stack_b->value > stacks->med)
				ft_rotate_b(stacks);
		}
		else
			ft_rotate_a(stacks);
	}
	if (stacks->stack_a->value < stacks->stack_a->next_element->value)
		ft_swap_a(stacks);
	ft_move_2a(stacks);
}
