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
	while (s[len] != '\0')
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

	total_memory = nmemb * size;
	if (nmemb != 0 && total_memory / nmemb != size)
		return (NULL);
	pointer = malloc(total_memory);
	if (!pointer)
		return (NULL);
	while (total_memory > 0)
	{
		*(char *)pointer = '\0';
		pointer++;
		total_memory--;
	}
	return (pointer);
}

static int	ft_join(char const *s1, char const *s2, char *new_string)
{
	int		i;
	int		i_s2;

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
	return (i_s2 + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		full_len;
	size_t	s1s2_size;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	s1s2_size = (ft_strlen(s1)) + (ft_strlen(s2)) + 1;
	new_string = ft_calloc(s1s2_size, sizeof(char));
	if (!new_string)
		return (NULL);
	full_len = ft_join(s1, s2, new_string);
	new_string[full_len] = '\0';
	return (new_string);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!(dest) && !(src))
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	i = -1;
	if (!src && !dest)
		return (NULL);
	if (csrc < cdest)
	{
		while (n--)
			*(cdest + n) = *(csrc + n);
	}
	else
	{
		while (++i < n)
			*cdest++ = *csrc++;
	}
	return (dest);
}
