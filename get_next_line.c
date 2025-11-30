/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 09:17:38 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/08 15:31:33 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_line(char *line)
{
	free(line);
	return (NULL);
}

int	ft_find_line(int fd, char **line, char *buffer, char **reminder)
{
	int	n_idx;
	int	c;

	c = 1;
	while (c > 0)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c < 0)
			return (ft_free_both(*line, buffer));
		buffer[c] = '\0';
		*line = ft_strjoin(*line, buffer);
		n_idx = ft_check_newline(*line);
		if (n_idx > -1)
		{	
			*reminder = ft_edit_reminder(*line, n_idx);
			(*line)[n_idx + 1] = '\0';
			break ;
		}
		if (c == 0)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*reminder;
	char			*line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = reminder;
	reminder = NULL;
	if (!ft_find_line(fd, &line, buffer, &reminder))
		return (NULL);
	free(buffer);
	if (!line || !*line)
		return (ft_free_line(line));
	return (line);
}
