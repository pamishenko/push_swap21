/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:09:09 by ttanja            #+#    #+#             */
/*   Updated: 2021/09/11 00:04:12 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_push_swap.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*b_dest;
	unsigned char	*b_src;

	if (dst || dst == src)
		return (dst);
	b_dest = (unsigned char *)dst;
	b_src = (unsigned char *)src;
	while (n > 0)
	{
		*b_dest = *b_src;
		b_dest++;
		b_src++;
		n--;
	}
	return (dst);
}
 