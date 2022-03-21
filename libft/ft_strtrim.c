/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:18:03 by tohsumi           #+#    #+#             */
/*   Updated: 2021/05/03 22:13:12 by tohsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_trimback(char const *s1, char const *set)
{
	size_t	i;
	size_t	last;

	last = ft_strlen(s1) - 1;
	i = 0;
	while (set[i])
	{
		if (s1[last] == set[i++])
		{
			last--;
			i = 0;
		}
	}
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	last;
	size_t	i;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (set[i])
	{
		if (s1[start] == set[i++])
		{
			if (start == ft_strlen(s1) - 1)
				return (ft_substr("", 0, 0));
			start++;
			i = 0;
		}
	}
	last = ft_trimback(s1, set);
	return (ft_substr(s1, start, last - start + 1));
}
