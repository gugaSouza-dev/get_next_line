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
#include <stdio.h>
#include <unistd.h>

static char	*read_file(char *line_tracker, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		total_read;

	total_read = 1;
	if (!line_tracker)
		line_tracker = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_strchr(buffer, '\n') == NULL && total_read)
	{
		total_read = read(fd, buffer, BUFFER_SIZE);
		line_tracker = ft_strjoin(line_tracker, buffer);
		printf("%s", line_tracker);
	}
	return (line_tracker);
}

char	*get_next_line(int fd)
{
	static char	*line_tracker;
	char		*line;
	int			i;

	if (fd == -1)
		return (NULL);
	i = 0;
	line_tracker = read_file(line_tracker, fd);
	while (line_tracker[i] != '\n' && line_tracker[i])
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	line = ft_memcpy(line, line_tracker, i + 1);
	line_tracker += i + 1;
	return (line);
}
