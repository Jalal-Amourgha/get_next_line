/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:45:42 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/08 15:31:24 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_check_newline(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*updated_line;
	int		i;
	int		j;

	if (!s2)
		return (s1);
	updated_line = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!updated_line)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		updated_line[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		updated_line[i++] = s2[j++];
	updated_line[i] = '\0';
	free(s1);
	return (updated_line);
}

char	*ft_edit_reminder(char *line, int n_idx)
{
	char	*new_reminder;
	int		i;

	new_reminder = malloc(ft_strlen(line + n_idx + 1) + 1);
	if (!new_reminder)
		return (NULL);
	i = 0;
	while (line[n_idx + i + 1])
	{
		new_reminder[i] = line[n_idx + i + 1];
		i++;
	}
	new_reminder[i] = '\0';
	return (new_reminder);
}

int	ft_free_both(char *line, char *buffer)
{
	free(line);
	free(buffer);
	return (0);
}
