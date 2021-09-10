/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_instruction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 09:24:59 by ttanja            #+#    #+#             */
/*   Updated: 2021/08/29 10:33:48 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	ft_set_instruction(t_stacks *stacks, char *str)
{
	t_instruction	*new_instructions;
	t_instruction	*temp;

	if (!str || !stacks)
		return (1);
	new_instructions = ft_calloc(1, sizeof(t_instruction));
	ft_memcpy(new_instructions->instr, str, ft_strlen(str));
	if (!stacks->instruct)
		stacks->instruct = new_instructions;
	else
	{
		temp = stacks->instruct;
		while (temp->next_instruction)
			temp = temp->next_instruction;
		temp->next_instruction = new_instructions;
	}
	return (0);
}

int	ft_get_all_instructions(t_stacks *stacks)
{
	t_instruction	*temp_instruction;

	if (!stacks)
		return (1);
	temp_instruction = stacks->instruct;
	while (temp_instruction)
	{
		ft_putstr_fd(temp_instruction->instr, 1);
		ft_putstr_fd("\n", 1);
		temp_instruction = temp_instruction->next_instruction;
	}
	return (0);
}

int	ft_close_instructions(t_instruction *instruction)
{
	t_instruction	*temp_instruction;

	if (!instruction)
		return (1);
	temp_instruction = instruction;
	while (instruction->next_instruction)
	{
		temp_instruction = instruction->next_instruction;
		free(instruction);
		instruction = temp_instruction;
	}
	free(temp_instruction);
	return (0);
}
