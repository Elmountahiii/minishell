/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:53:54 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/15 16:45:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token_type	ft_token_analyzer(char *token)
{
	if (ft_strcmp(token, "|") == 0)
		return PIPE;
	if (ft_strcmp(token, "<") == 0)
		return REDIRECTION_IN;
	if (ft_strcmp(token, ">") == 0)
		return REDIRECTION_OUT;
	if (ft_strcmp(token, ">>") == 0)
		return APPEND;
	if (ft_strcmp(token, "<<") == 0)
		return HEREDOC;
	if (ft_strcmp(token, "\'") == 0)
		return SINGLE_QUOTE;
	if (ft_strcmp(token, "\"") == 0)
		return DOUBLE_QUOTE;
	if (ft_strcmp(token, " ") == 0)
		return SPACE;
	if (ft_strcmp(token, "$") == 0)
		return ENV;
	return WORD;
}

t_word_type	ft_word_type_analyzer(char  **tokens, int index)
{
	int i;
	bool in_single_quote;
	bool in_double_quote;

	i = 0;
	in_single_quote = false;
	in_double_quote = false;
	while (i < index)
	{
		if (tokens[i][0] == '\'')
			in_single_quote = !in_single_quote;
		if (tokens[i][0	] == '\"')
			in_double_quote = !in_double_quote;
		i++;
	}
	if (in_single_quote)
		return IN_SINGLE_QUOTE;
	if (in_double_quote)
		return IN_DOUBLE_QUOTE;
	return NORMAL;
}

int	ft_fill_tokens_list(t_tokens_list *tokens_list, char **tokens_words)
{
	int i;
	t_tokens_list *head;

	i = 0;
	head = tokens_list;
	while (tokens_words[i])
	{
		tokens_list->token = calloc(1,sizeof(t_token));
		if (!tokens_list->token)
			return 1;
		tokens_list->token->value = ft_strdup(tokens_words[i]);
		tokens_list->token->token_type = ft_token_analyzer(tokens_words[i]);
		tokens_list->token->word_type = ft_word_type_analyzer(tokens_words, i);
		tokens_list->next = calloc(1,sizeof(t_tokens_list));
		if (!tokens_list->next)
			return 1;
		tokens_list = tokens_list->next;
		i++;
	}
	return 0;
}

t_tokens_list	*ft_init_token_list(char *line)
{
	char **tokens_words;
	t_tokens_list *tokens_list;

	tokens_words = ft_extract(line);
	if (!tokens_words)
		return (NULL);
	tokens_list = calloc(1,sizeof(t_tokens_list));
	if (!tokens_list)
		return (NULL);
	// check ft_fill_tokens_list return value if return value is 1 then free tokens_list
	// you must free tokens_words regardless of the return value of ft_fill_tokens_list
	ft_fill_tokens_list(tokens_list, tokens_words);
	return (tokens_list);
}