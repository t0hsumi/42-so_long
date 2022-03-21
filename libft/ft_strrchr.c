/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 21:18:27 by tohsumi           #+#    #+#             */
/*   Updated: 2021/05/04 10:33:20 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	size_t	len;

	len = ft_strlen((char *)str);
	if (chr == 0)
		return ((char *)&str[len]);
	while (len-- > 0)
	{
		if (str[len] == (char)chr)
			return ((char *)&str[len]);
	}
	return (NULL);
}
