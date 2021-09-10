/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 22:08:58 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:27:20 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>
#include <stdio.h>

int	ft_new_init_a(t_stacks *stacks)
{
	if (!stacks->stack_b)
		return (1);
	stacks->stack_a = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next_element;
	if (stacks->stack_b)
		stacks->stack_b->previous_element = NULL;
	stacks->stack_a->next_element = NULL;
	stacks->count_a++;
	stacks->count_b--;
	return (0);
}

int	ft_push_a(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (!stacks->count_b)
		return (1);
	if (!stacks->count_a)
	{
		ft_new_init_a(stacks);
		return (0);
	}
	stacks->stack_a->previous_element = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next_element;
	if (stacks->stack_b)
		stacks->stack_b->previous_element = NULL;
	stacks->stack_a->previous_element->next_element = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->previous_element;
	stacks->stack_a->count = &stacks->count_a;
	stacks->count_a++;
	stacks->count_b--;
	ft_set_instruction(stacks, "pa");
	return (0);
}

int	ft_push_a2(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (!stacks->count_b)
		return (1);
	if (!stacks->count_a)
	{
		ft_new_init_a(stacks);
		return (0);
	}
	if (stacks->count_a > 1)
		ft_move_for_push_a(stacks);
	stacks->stack_a->previous_element = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next_element;
	if (stacks->stack_b)
		stacks->stack_b->previous_element = NULL;
	stacks->stack_a->previous_element->next_element = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->previous_element;
	stacks->stack_a->count = &stacks->count_a;
	stacks->count_a++;
	stacks->count_b--;
	ft_set_new_min_max_a(stacks);
	ft_set_instruction(stacks, "pa");
	return (0);
}

int	ft_push_b2(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (!stacks->count_a)
		return (1);
	if (!stacks->stack_b)
		ft_init_stack_b(stacks);
	else
	{
		stacks->stack_b->previous_element = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next_element;
		if (stacks->stack_a)
			stacks->stack_a->previous_element = NULL;
		stacks->stack_b->previous_element->next_element = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->previous_element;
	}
	stacks->stack_b->count = &stacks->count_b;
	stacks->count_b++;
	stacks->count_a--;
	ft_set_instruction(stacks, "pb");
	ft_set_new_min_max_b(stacks);
	return (0);
}

int	ft_push_b(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	if (!stacks->count_a)
		return (1);
	if (!stacks->stack_b)
		ft_init_stack_b(stacks);
	else
	{
		ft_move_for_push_b(stacks);
		stacks->stack_b->previous_element = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next_element;
		if (stacks->stack_a)
			stacks->stack_a->previous_element = NULL;
		stacks->stack_b->previous_element->next_element = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->previous_element;
	}
	stacks->stack_b->count = &stacks->count_b;
	stacks->count_b++;
	stacks->count_a--;
	ft_set_instruction(stacks, "pb");
	ft_set_new_min_max_b(stacks);
	return (0);
}
