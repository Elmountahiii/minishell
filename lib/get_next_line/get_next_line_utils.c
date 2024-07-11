/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:42:59 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 21:45:34 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strchr(char *str, int c)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i ++;
	}
	return (NULL);
}

char	*ft_gnl_strdup(char *str)
{
	char	*str_dup;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len == 0)
		return (NULL);
	str_dup = malloc(sizeof(char) * (len + 1));
	if (str_dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_dup[i] = str[i];
		i ++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

char	*ft_gnl_strjoin(char *rest, char *buffer)
{
	char	*str_join;
	int		s1_len;
	int		i;

	if (!rest && buffer)
		return (ft_gnl_strdup(buffer));
	s1_len = ft_strlen(rest);
	if (s1_len == 0 || ft_strlen(buffer) == 0)
		return (NULL);
	str_join = malloc(s1_len + ft_strlen(buffer) + 1);
	i = 0;
	if (str_join == NULL)
		return (NULL);
	while (rest[i])
	{
		str_join[i] = rest[i];
		i ++;
	}
	i = 0;
	while (buffer[i])
	{
		str_join[s1_len + i] = buffer[i];
		i ++;
	}
	return (free(rest), str_join[s1_len + i] = '\0', str_join);
}
