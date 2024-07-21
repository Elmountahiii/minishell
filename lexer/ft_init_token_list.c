/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:53:54 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/21 18:12:58 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int	ft_check_single_quote

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
	if (token && token[0] == '\'')
		return SINGLE_QUOTE_WORD;
	if (token && token[0] == '\"')
		return DOUBLE_QUOTE_WORD;
	if (ft_strcmp(token, " ") == 0)
		return SPACE;
	if (ft_strncmp(token, "$", 1) == 0)
		return ENV;
	return WORD;
}

t_tokens_list	*ft_fill_tokens_list(char **tokens_words)
{
    int				i = 0;
    t_tokens_list	*token;
    t_tokens_list	*tmp = NULL;
    t_tokens_list	*head = NULL;

    while (tokens_words[i])
    {
        token = calloc(1, sizeof(t_tokens_list));
        if (!token)
            return (NULL);
        if (head == NULL)
            head = token;
        else
            tmp->next = token;
        token->value = ft_strdup(tokens_words[i]);
        token->type = ft_token_analyzer(tokens_words[i]);
        token->next = NULL;
        tmp = token;
        i++;
    }
    return (head);
}

t_tokens_list	*ft_init_token_list(char *line)
{
	char **tokens_words;
	t_tokens_list *tokens_list;

	tokens_words = ft_extract(line);
	if (!tokens_words)
		return (NULL);
	tokens_list =ft_fill_tokens_list(tokens_words);
	if (!tokens_list)
		return (NULL);
	// check ft_fill_tokens_list return value if return value is 1 then free tokens_list
	// you must free tokens_words regardless of the return value of ft_fill_tokens_list
	// ft_fill_tokens_list(tokens_list, tokens_words);
	return (tokens_list);
}