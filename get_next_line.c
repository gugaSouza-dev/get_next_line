/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:38:50 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/24 21:34:09 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*read_file(char *line_tracker, int fd)
{
	char	*buffer;
	char	*bananinha;
	int		total_read;

	total_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line_tracker == NULL)
		line_tracker = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_strchr(line_tracker, '\n') == NULL && total_read)
	{
		total_read = read(fd, buffer, BUFFER_SIZE);
		if (total_read <= 0)
		{
			free(buffer);
			free(line_tracker);
			return (NULL);
		}
		if (total_read != BUFFER_SIZE)
			buffer[total_read] = '\0';
		bananinha = line_tracker;
		line_tracker = ft_strjoin(line_tracker, buffer);
		free(bananinha);
	}
	free(buffer);
	return (line_tracker);
}

static char	*waste_skipper(char *line_tracker)
{
	int		str_len;
	int		i;
	char	*track_holder;

	i = -1;
	str_len = ft_strlen(line_tracker);
	if (str_len == 0)
		return (NULL);
	track_holder = ft_calloc(str_len + 1, sizeof(char));
	while (line_tracker[i++] != '\0')
		track_holder[i] = line_tracker[i];
	return (track_holder);
}

char	*get_next_line(int fd)
{
	static char	*line_tracker;
	char		*line;
	char		*track_holder;
	int			i;

	if (fd == -1)
		return (NULL);
	i = 0;
	line_tracker = read_file(line_tracker, fd);
	if (line_tracker == NULL)
		return (NULL);
	while (line_tracker[i] != '\n' && line_tracker[i])
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	ft_strlcpy(line, line_tracker, i + 2);
	track_holder = waste_skipper(line_tracker + i + 1);
	free(line_tracker);
	line_tracker = track_holder;
	return (line);
}
