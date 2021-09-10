/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 23:15:50 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:28:58 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_minusbase(t_stacks *stacks)
{
	t_stack	*temp;
	int		count;

	count = 0;
	temp = stacks->stack_a;
	while (temp)
	{
		if (temp->is_base == stacks->base)
			count++;
		temp = temp->next_element;
	}
	if (!count)
		stacks->base--;
}

int	ft_base_sort(t_stacks *stacks)
{
	t_stack	*temp;
	int		count;

	temp = stacks->stack_a;
	count = 0;
	while (count / 2 < stacks->count_a && temp->next_element)
	{
		if (stacks->stack_a->is_base < stacks->base / 2)
			return (count);
		temp = temp->next_element;
		count++;
	}
	return (-1);
}

void	ft_set_med(t_stacks *stacks)
{
	int		med_inc;
	int		med_dec;
	int		med;
	t_stack	*temp;

	temp = stacks->stack_a;
	if (!temp)
		return ;
	ft_set_new_min_max_a(stacks);
	med = ((stacks->max + stacks->min) / 2) - 1;
	med_dec = stacks->min;
	med_inc = stacks->max;
	while (temp->next_element)
	{
		if (temp->value <= med_inc && temp->value >= med)
			med_inc = temp->value;
		if (temp->value >= med_dec && temp->value <= med)
			med_dec = temp->value;
		temp = temp->next_element;
	}
	if (med - med_dec < med - med_inc)
		stacks->med = med_dec;
	else
		stacks->med = med_inc;
}
