/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:37:34 by ttanja            #+#    #+#             */
/*   Updated: 2021/08/29 10:33:48 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}
