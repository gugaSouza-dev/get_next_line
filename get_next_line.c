/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:38:50 by gusouza-          #+#    #+#             */
/*   Updated: 2022/06/13 06:05:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*read_file(char *line_tracker, int fd, int *total_read)
{
	char	*buffer;
	char	*bananinha;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line_tracker == NULL)
		line_tracker = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_strchr(line_tracker, '\n') == NULL && *total_read > 0)
	{
		*total_read = read(fd, buffer, BUFFER_SIZE);
		if (*total_read <= 0 && line_tracker[0] == '\0')
		{
			free(buffer);
			free(line_tracker);
			return (NULL);
		}
		if (*total_read != BUFFER_SIZE && *total_read > 0)
			buffer[*total_read] = '\0';
		if (*total_read == 0)
			break ;
		bananinha = line_tracker;
		line_tracker = ft_strjoin(line_tracker, buffer);
		free(bananinha);
	}
	free(buffer);
	return (line_tracker);
}

static char	*waste_skipper(char *line_tracker, int index, int *total_read)
{
	int		str_len;
	char	*track_holder;

	if (*(line_tracker + index - 1) == '\0')
		return (NULL);
	str_len = ft_strlen(line_tracker + index);
	if (str_len == 0 && *total_read < 0)
		return (NULL);
	track_holder = ft_calloc(str_len + 1, sizeof(char));
	if (BUFFER_SIZE == 1)
		ft_strlcpy(track_holder, line_tracker + index, BUFFER_SIZE + 1);
	else
		ft_strlcpy(track_holder, line_tracker + index, BUFFER_SIZE);
	free(line_tracker);
	line_tracker = track_holder;
	return (track_holder);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s1_caster;
	unsigned char	*s2_caster;

	if (!s1 || !s2)
		return (-1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	i = 0;
	s1_caster = (unsigned char *)s1;
	s2_caster = (unsigned char *)s2;
	while ((s1_caster[i] && s2_caster[i]))
	{
		if (s1_caster[i] != s2_caster[i])
			return (s1_caster[i] - s2_caster[i]);
		i++;
	}
	return (0);
}

static int	line_preset(char **line, char *line_tracker)
{
	int	i;

	i = 0;
	while (line_tracker[i] != '\n' && line_tracker[i])
		i++;
	*line = ft_calloc((i + 2), sizeof(char));
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*line_tracker;
	char		*line;
	char		*track_holder;
	int			i;
	int			total_read;

	if ((BUFFER_SIZE < 1) || (fd < 0) || (fd > 1024))
		return (NULL);
	total_read = 1;
	line_tracker = read_file(line_tracker, fd, &total_read);
	if (line_tracker == NULL)
		return (NULL);
	i = line_preset(&line, line_tracker);
	ft_strlcpy(line, line_tracker, i + 2);
	track_holder = waste_skipper(line_tracker, i + 1, &total_read);
	if (track_holder)
		line_tracker = track_holder;
	if ((ft_strncmp(line_tracker, line) == 0) && (total_read < BUFFER_SIZE)
		&& (i > 0))
	{
		free(line_tracker);
		line_tracker = NULL;
		return (line);
	}
	return (line);
}
