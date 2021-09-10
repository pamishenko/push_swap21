/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:27:30 by ttanja            #+#    #+#             */
/*   Updated: 2021/08/29 11:02:43 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	ft_print_stack(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (!stack->previous_element)
			ft_putstr_fd("head ->", 1);
		if (!stack->next_element)
			ft_putstr_fd("tail ->", 1);
		ft_putnbr_fd(stack->value, 1);
		write(1, "\n", 1);
		stack = stack->next_element;
	}
	return (0);
}
