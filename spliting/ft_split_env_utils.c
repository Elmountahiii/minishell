/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_env_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:29:33 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 15:41:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_skip_env(char **line)
{
	int	i;

	i = 0;
	if (!*line)
		return (0) ;
	(*line)++;
	i++;
	while (**line)
	{
		if (ft_is_space_v2(**line) || **line == '|' || **line == '>'
			|| **line == '<' || **line == '$')
			break ;
	(*line)++;
	i++;
	}
	return (i);
}

char	*ft_create_env(char **line)
{
	char	*word;
	char	*tmp;
	int		len;	
	
	if (!*line)
		return (NULL);
	tmp = strdup(*line);
	len = ft_skip_env(&tmp);
	word = calloc((len + 1), sizeof(char));
	free(tmp - len);
	if (!word)
		return (NULL);
	strncpy(word, *line, len);
	word[len] = '\0';
	*line += len;
	return (word);
}