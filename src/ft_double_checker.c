/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 20:46:39 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/05 09:51:17 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	ft_set_new_min_max_a(t_stacks *stacks)
{
	t_stack	*temp;

	stacks->max = -2147483648;
	stacks->min = 2147483647;
	temp = stacks->stack_a;
	while (temp)
	{
		temp->max_b = &(stacks->max_b);
		temp->min_b = &(stacks->min_b);
		temp->max = &(stacks->max);
		temp->min = &(stacks->min);
		if (stacks->min > temp->value)
			stacks->min = temp->value;
		if (stacks->max < temp->value)
			stacks->max = temp->value;
		temp = temp->next_element;
	}
}

int	ft_double_checker(int count, char *arr[])
{
	int	i;
	int	j;
	int	arr_temp[99999];

	i = 0;
	while (i < count - 1)
	{
		arr_temp[i] = ft_atoi(arr[i + 1]);
		i++;
	}
	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count - 1)
		{
			if (arr_temp[i] == arr_temp[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
