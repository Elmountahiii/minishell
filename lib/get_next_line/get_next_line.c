/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:48:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 21:39:15 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **str)
{
	free(*str);
	*str = NULL;
}

char	*extract_new_line(char **rest)
{
	int		i;
	char	*new_line;

	i = 0;
	while ((*rest)[i] && (*rest)[i] != '\n')
		i++;
	new_line = malloc (sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while ((*rest)[i] && (*rest)[i] != '\n')
	{
		new_line[i] = (*rest)[i];
		i ++;
	}
	if ((*rest)[i] == '\n')
	{
		new_line[i] = '\n';
		i ++;
	}
	new_line[i] = '\0';
	*rest = clean(rest);
	return (new_line);
}

char	*read_line(int fd, char **rest)
{
	char	*buffer;
	int		byte_count;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_count = read(fd, buffer, BUFFER_SIZE);
	buffer[byte_count] = '\0';
	while (byte_count > 0)
	{
		*rest = ft_gnl_strjoin(*rest, buffer);
		if (ft_strchr(*rest, '\n'))
			break ;
		byte_count = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_count] = '\0';
	}
	free_and_null(&buffer);
	if (*rest && !ft_gnl_strchr(*rest, '\n'))
		return (temp = *rest, *rest = NULL, temp);
	if (*rest && ft_gnl_strchr(*rest, '\n'))
		return (extract_new_line(rest));
	return (*rest);
}

char	*clean(char **rest)
{
	char	*temp;
	char	*newline;

	newline = ft_gnl_strchr(*rest, '\n');
	if (!newline)
		return (NULL);
	temp = ft_gnl_strdup(newline + 1);
	free(*rest);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(rest), rest = NULL, NULL);
	if (ft_gnl_strchr(rest, '\n'))
		return (extract_new_line(&rest));
	return (read_line(fd, &rest));
}
