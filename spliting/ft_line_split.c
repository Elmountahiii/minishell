/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:22:19 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 20:32:46 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_split_line(char *line)
{
	char **tokens;
	int	index;

	tokens = ft_calloc((ft_count_line_tokens(line) + 1), sizeof(char *));
	if (!tokens)
		return (NULL);
	index = 0;
	while (*line)
	{
		if (ft_get_token_type(line) == WORD || ft_get_token_type(line) == ENV)
				tokens[index++] = ft_create_word(&line);
		else if (ft_get_token_type(line) == SPACE_TOKEN)
			tokens[index++] = ft_create_space(&line);
		else if (ft_get_token_type(line) == HEREDOC || ft_get_token_type(line) == APPEND)
			tokens[index++] = ft_create_redirection(&line);
		else if (ft_get_token_type(line) == PIPE || ft_get_token_type(line) == REDIRECTION_OUT
				|| ft_get_token_type(line) == REDIRECTION_IN)
			tokens[index++] = ft_substrl(line++, 0, 1);
		else if (ft_get_token_type(line) == DOUBLE_QUOTE_WORD || ft_get_token_type(line) == SINGLE_QUOTE_WORD)
			tokens[index++] = ft_crate_quote(&line);
	}
	tokens[index] = NULL;
	return (tokens);
}
