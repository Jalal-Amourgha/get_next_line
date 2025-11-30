/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:53:07 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/30 11:21:05 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024];
	char		*line;
	char		*buffer;
	int			c;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	c = 1;
	while (ft_check_newlinw(stack[fd]) < 0 && c > 0)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c < 0)
			return (ft_free(buffer));
		buffer[c] = '\0';
		stack[fd] = ft_strjoin(stack[fd], buffer);
	}
	free(buffer);
	line = ft_get_line(stack[fd]);
	stack[fd] = ft_save_rest(stack[fd]);
	return (line);
}
