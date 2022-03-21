/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tohsumi <tohsumi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:46:36 by tohsumi           #+#    #+#             */
/*   Updated: 2022/03/21 04:07:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_new_line_pos(const char *s, int chr)
{
	char	c;
	int		i;

	c = (char)chr;
	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	if (ptr == s1)
		return (ptr);
	i = 0;
	while (i < (int)n)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	my_free(char **ptr1, char **ptr2, char **ptr3, char **ptr4)
{
	if (ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	if (ptr3)
	{
		free(*ptr3);
		*ptr3 = NULL;
	}
	if (ptr4)
	{
		free(*ptr4);
		*ptr4 = NULL;
	}
	return (-1);
}
