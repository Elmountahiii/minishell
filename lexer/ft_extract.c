/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:43:12 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/15 13:13:41 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *ft_lexer_substr(char *line)
{
	int  i;
	int  len;
	char *token;

	i = 0;
	len = ft_count_skip(line);
	token = malloc(sizeof(char) * (len + 1));
	if (!token)
		return (NULL);
	while (i < len)
	{
		token[i] = line[i];
		i++;
	}
	token[i] = '\0';
	return (token);
}

char **ft_extract(char *line)
{
	char **tokens;
	int i;
	int index;

	if (!line)
		return (NULL);
	i = 0;
	index = 0;
	tokens = malloc(sizeof(char *) * (ft_count_lexer_tokens(line) + 1));
	if (!tokens)
		return (NULL);
	while (line[i])
	{
		tokens[index] = ft_lexer_substr(line + i);
		index ++;
		i += ft_count_skip(line + i);
	}
	tokens[index] = NULL;
	return (tokens);
}
