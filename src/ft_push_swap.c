/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:07:59 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/08 20:51:31 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	main(int argc, char *argv[])
{
	static t_stacks	*stacks;

	if (ft_double_checker(argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	stacks = ft_init_stacks(argc, argv);
	if (!ft_is_sorted(stacks))
		ft_sort(stacks);
	ft_get_all_instructions(stacks);
	ft_close_stacks(stacks);
	return (0);
}
