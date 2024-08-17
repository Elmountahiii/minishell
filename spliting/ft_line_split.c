/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:22:19 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 22:37:58 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_process_token(char **line, char **tokens, int *index)
{
	t_token_type	type;

	type = ft_get_token_type(*line);
	if (type == WORD || type == ENV)
		tokens[(*index)++] = ft_create_word(line);
	else if (type == SPACE_TOKEN)
		tokens[(*index)++] = ft_create_space(line);
	else if (type == HEREDOC || type == APPEND)
		tokens[(*index)++] = ft_create_redirection(line);
	else if (type == PIPE || type == REDIRECTION_OUT
		|| type == REDIRECTION_IN)
	{
		tokens[(*index)++] = ft_substrl(*line, 0, 1);
		(*line)++;
	}
	else if (type == DOUBLE_QUOTE_WORD || type == SINGLE_QUOTE_WORD)
		tokens[(*index)++] = ft_crate_quote(line);
}

char	**ft_split_line(char *line)
{
	char	**tokens;
	int		index;

	tokens = ft_calloc((ft_count_line_tokens(line) + 1), sizeof(char *));
	if (!tokens)
		return (NULL);
	index = 0;
	while (*line)
	{
		ft_process_token(&line, tokens, &index);
	}
	return (tokens[index] = NULL, tokens);
}
