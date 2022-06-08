/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:10:53 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/23 21:23:06 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_memory;
	void	*pointer;
	size_t	i;
	char	*holder;

	i = 0;
	total_memory = nmemb * size;
	if (nmemb != 0 && total_memory / nmemb != size)
		return (NULL);
	pointer = malloc(total_memory);
	holder = (char *)pointer;
	if (!pointer)
		return (NULL);
	while (total_memory > i)
	{
		holder[i] = '\0';
		i++;
	}
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1s2_size;
	char	*new_string;
	int		i;
	int		i_s2;

	if (!s1 || !s2)
		return (NULL);
	s1s2_size = (ft_strlen(s1)) + (ft_strlen(s2)) + 1;
	new_string = ft_calloc(s1s2_size, sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	i_s2 = i;
	i = 0;
	while (s2[i] != '\0')
	{
		new_string[i_s2 + i] = s2[i];
		i++;
	}
	return (new_string);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
