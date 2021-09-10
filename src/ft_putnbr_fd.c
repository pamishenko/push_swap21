/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:56:33 by ttanja            #+#    #+#             */
/*   Updated: 2021/08/29 11:02:43 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

int	ft_is_positive(int nb)
{
	if (nb < 0)
		return (0);
	return (1);
}

int	ft_count(int nb)
{
	int	length;
	int	temp;

	temp = nb;
	length = 1;
	while (temp / 10 != 0)
	{
		length++;
		temp = temp / 10;
	}
	if (!ft_is_positive(nb))
		length++;
	return (length);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		length;
	int		temp;
	char	result[100];

	length = ft_count(nb);
	temp = nb;
	result[length] = '\0';
	while (length-- > 0)
	{
		if (!ft_is_positive(nb))
			result[length] = (temp % 10) * -1 + '0';
		else
			result[length] = (temp % 10) + '0';
		temp = temp / 10;
	}
	if (!ft_is_positive(nb))
		result[0] = '-';
	ft_putstr_fd(result, fd);
}
