/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:40:38 by tohsumi           #+#    #+#             */
/*   Updated: 2021/05/01 21:03:16 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		n = (int) -1 * n;
	return (n);
}

static int	diginum(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	size = diginum(n);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
		ptr[0] = '-';
	if (n == 0)
		ptr[0] = '0';
	ptr[size] = '\0';
	while (n != 0)
	{
		ptr[--size] = "0123456789"[ft_abs(n % 10)];
		n /= 10;
	}
	return (ptr);
}
