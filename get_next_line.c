/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:51:49 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/13 20:46:08 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char	*clean_line(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_str;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 1));
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (str[j] && j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static char	*clean_stat(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_str;

	if (!str || *str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	char		*buffer;
	char		*line;
	ssize_t		read_bytes;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stat, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes ==  0)
			break;
		buffer[read_bytes] = '\0';
		if (!stat)
			stat = ft_strdup(buffer);
		else
			stat = ft_strjoin(stat, buffer);
	}
	line = clean_line(stat);
	stat = clean_stat(stat);
	return (line);
}
