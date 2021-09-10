/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stack_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:16:21 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/10 23:29:21 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

t_stacks	*ft_init_stacks(int argc, char *argv[])
{
	t_stacks	*stacks;

	stacks = ft_calloc(1, sizeof(t_stacks));
	stacks->max = -2147483648;
	stacks->min = 2147483647;
	stacks->max_b = -2147483648;
	stacks->min_b = 2147483647;
	stacks->stack_a = ft_calloc(1, sizeof(t_stack));
	ft_fill_stack_a(stacks, argc, argv);
	ft_init_base(stacks);
	ft_set_base(stacks);
	return (stacks);
}

int	ft_close_stacks(t_stacks *stacks)
{
	ft_close_stack(stacks->stack_a);
	ft_close_stack(stacks->stack_b);
	ft_close_instructions(stacks->instruct);
	return (0);
}

void	ft_fill_stack_a(t_stacks *stacks, int argc, char *argv[])
{
	t_stack	*stack;
	int		number_elenent;

	if (argc < 2)
		return ;
	number_elenent = 1;
	stack = stacks->stack_a;
	stack->value = atoi(argv[number_elenent]);
	stacks->count_a++;
	stacks->stack_a->count = &(stacks->count_a);
	ft_set_new_min_max_a(stacks);
	while (++number_elenent < argc)
	{
		stack->next_element = ft_calloc(1, sizeof(t_stack));
		stack->next_element->previous_element = stack;
		stack->next_element->value = atoi(argv[number_elenent]);
		stacks->count_a++;
		stack->next_element->count = &(stacks->count_a);
		stack = stack->next_element;
		ft_set_new_min_max_a(stacks);
	}
}

t_stack	*ft_init_stack_b(t_stacks *stacks)
{
	if (!stacks->stack_a)
		return (NULL);
	stacks->stack_b = stacks->stack_a;
	if (stacks->stack_a->next_element)
		stacks->stack_a = stacks->stack_a->next_element;
	else
		stacks->stack_a = NULL;
	if (stacks->stack_a)
		stacks->stack_a->previous_element = NULL;
	stacks->stack_b->next_element = NULL;
	stacks->stack_b->count = &(stacks->count_b);
	stacks->stack_b->step++;
	stacks->min_b = stacks->stack_b->value;
	stacks->max_b = stacks->stack_b->value;
	return (stacks->stack_b);
}

int	ft_close_stack(t_stack *stack)
{
	t_stack	*curent_stack;
	t_stack	*next_stack;

	curent_stack = NULL;
	next_stack = stack;
	while (next_stack != NULL)
	{
		curent_stack = next_stack;
		next_stack = next_stack->next_element;
		free(curent_stack);
	}
	return (0);
}
