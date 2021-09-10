/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:23:28 by ttanja            #+#    #+#             */
/*   Updated: 2021/08/29 10:33:48 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	ft_atoi(const char *str)
{
	char				pozitive;
	long long int		result;

	pozitive = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
		pozitive *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str <= '9' && *str >= '0')
			result = (result * 10) + *str - 48;
		else
			break ;
		str++;
	}
	return (result * pozitive);
}
