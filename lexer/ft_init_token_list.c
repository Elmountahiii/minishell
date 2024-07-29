/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:53:54 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 14:34:34 by yel-moun         ###   ########.fr       */
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
	if (ft_is_all_space(token))
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
        token->type = ft_token_analyzer(tokens_words[i]);
		token->value = ft_strdup(tokens_words[i]);
		i ++;
        token->next = NULL;
        tmp = token;
    }
    return (head);
}

t_tokens_list	*ft_init_token_list(char *line)
{
	char **tokens_words;
	t_tokens_list *tokens_list;

	tokens_words = ft_extract(line);

	// int i = 0;
	// while (tokens_words[i])
	// {
	// 	printf("tokens_words[%d] = %s\n", i, tokens_words[i]);
	// 	i++;
	// }
	// exit(0);
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