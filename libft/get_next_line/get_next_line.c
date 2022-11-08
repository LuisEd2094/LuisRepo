/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:53:32 by lsoto-do          #+#    #+#             */
/*   Updated: 2022/10/20 12:00:44 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*parse_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*buffer_prep(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free_strs(&buffer, 0));
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (ft_free_strs(&buffer, 0));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	ft_free_strs (&buffer, 0);
	return (line);
}

char	*join_buff(char *buffer, char *reader)
{
	char	*temp;

	temp = ft_strjoin(buffer, reader);
	if (!temp)
		return (ft_free_strs(&buffer, &reader));
	ft_free_strs(&buffer, 0);
	return (temp);
}

char	*read_file(int fd, char *buffer, int bytes_read)
{
	char	*reader;

	reader = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!reader)
		return (ft_free_strs(&buffer, &reader));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, reader, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free_strs(&buffer, &reader));
		reader[bytes_read] = '\0';
		buffer = join_buff(buffer, reader);
		if (!buffer)
			return (NULL);
		if (ft_strchr(reader, '\n'))
			break ;
	}
	ft_free_strs(&reader, 0);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{	
		if (buffer)
			ft_free_strs(&buffer, 0);
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (ft_free_strs(&buffer, 0));
	bytes_read = 1;
	buffer = read_file(fd, buffer, bytes_read);
	if (!buffer)
		return (NULL);
	line = parse_line(buffer);
	if (!line || *line == '\0')
		return (ft_free_strs(&buffer, &line));
	buffer = buffer_prep(buffer);
	return (line);
}
