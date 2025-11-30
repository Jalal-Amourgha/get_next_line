/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamourgh <jamourgh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:08:06 by jamourgh          #+#    #+#             */
/*   Updated: 2025/11/30 11:22:08 by jamourgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# elif BUFFER_SIZE == -1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_check_newlinw(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *stack);
char	*ft_save_rest(char *stack);
char	*get_next_line(int fd);

#endif
