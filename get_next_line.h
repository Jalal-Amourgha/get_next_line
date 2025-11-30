/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:37:46 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/30 11:28:07 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# elif BUFFER_SIZE == -1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_check_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_edit_reminder(char *line, int n_idx);
int		ft_free_both(char *line, char *buffer);
char	*ft_free_line(char *line);
int		ft_find_line(int fd, char **line, char *buffer, char **reminder);
char	*get_next_line(int fd);

#endif
