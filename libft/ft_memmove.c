/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:47:51 by tohsumi           #+#    #+#             */
/*   Updated: 2021/05/02 17:14:35 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	uint8_t	*from;
	uint8_t	*to;

	from = (uint8_t *)src;
	to = (uint8_t *)dst;
	if (from == to || len == 0)
		return (dst);
	if (to > from && to - from < (int)len)
	{
		i = len;
		while (--i >= 0)
			to[i] = from[i];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
