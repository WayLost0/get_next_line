/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:54:35 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/13 15:57:31 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(const char *str1, const char *str2);
int		ft_strlen(char *str);

#endif
