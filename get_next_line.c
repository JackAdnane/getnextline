/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aech-chi <aech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:22:50 by aech-chi          #+#    #+#             */
/*   Updated: 2024/04/18 14:14:07 by aech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void read_and_append(char **line, int fd);

/*function for read_line*/

char	*get_next_line(int fd)
{
	static char *line;
	char *str;
	int i;

	i = 0;
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_and_append(&line, fd);
	if (!line)
		return (NULL);
	while( line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
	{
		str = ft_strsub(line, 0, i, 0);
		free (line);
		line = (NULL);
		return (str);
	}
	str = ft_strsub(line, 0, i + 1, 0);
	line = ft_strsub(line, i + 1, ft_strlen(line) - i, 1);
	if (!line)
		return (NULL);
	return (str);
	
}

void read_and_append(char **line, int fd)
{
	char *buf;
	int byte_r;
	
	byte_r = 1;
	buf = ft_strnew(BUFFER_SIZE);
	while(byte_r > 0 && !ft_strchr(*line, '\n'))
	{
		byte_r = read(fd, buf, BUFFER_SIZE);
		if (byte_r < 0)
		{
			free(buf);
			*line = (NULL);
			return ;
		}
		buf[byte_r] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
}