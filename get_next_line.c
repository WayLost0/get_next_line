/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryildiri <ryildiri@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:51:49 by ryildiri          #+#    #+#             */
/*   Updated: 2025/08/21 21:13:57 by ryildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
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

static char	*clean_stat(char *star)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_str;

	i = 0;
	if (!star || star[i] == '\0')
	{
		free(star);
		return (NULL);
	}
	while (star[i] && star[i] != '\n')
		i++;
	if (star[i] == '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(star) - i + 1));
	if (!new_str)
		return (NULL);
	j = 0;
	while (star[i])
		new_str[j++] = star[i++];
	free(star);
	new_str[j] = '\0';
	return (new_str);
}

static char	*read_line(int fd, char *star)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(star, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		buffer[read_bytes] = '\0';
		star = ft_strjoin(star, buffer);
		if (!star)
			break;
	}
	free (buffer);
	return(star);
}

char	*get_next_line(int fd)
{
	static char	*stat = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat = read_line(fd, stat);
	if (!stat)
		return (NULL);
	line = clean_line(stat);
	if (!line)
		return (NULL);
	stat = clean_stat(stat);
	if(!stat)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
