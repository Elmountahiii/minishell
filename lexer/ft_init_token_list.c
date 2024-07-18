/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:53:54 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/18 16:44:04 by yel-moun         ###   ########.fr       */
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
	if (ft_strncmp(token, "$", 1) == 0)
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
		{
			in_single_quote = !in_single_quote;
			i ++;
			if (i == index)
				return (IN_SINGLE_QUOTE);
		}else if (tokens[i][0	] == '\"')
		{
			in_double_quote = !in_double_quote;
			i ++;
			if (i == index)
				return (IN_DOUBLE_QUOTE);
			
		}else
			i++;
	}
	if (in_single_quote )
		return IN_SINGLE_QUOTE;
	if (in_double_quote)
		return IN_DOUBLE_QUOTE;
	return NORMAL;
}

// t_tokens_list	*ft_fill_tokens_list(char **tokens_words)
// {
// 	int i;
// 	t_tokens_list *list;
// 	t_tokens_list *head;

// 	i = 0;
// 	head = NULL;
// 	if (tokens_words[i] != NULL)
// 	{
// 		list = calloc(1, sizeof(t_tokens_list));
// 		if (!list)
// 			return NULL;
// 		head = list;
// 	}
// 	else
// 		return NULL;
// 	while (tokens_words[i])
// 	{
// 		list->token = calloc(1,sizeof(t_token));
// 		if (!list->token)
// 			return (NULL);
// 		list->token->value = ft_strdup(tokens_words[i]);
// 		list->token->token_type = ft_token_analyzer(tokens_words[i]);
// 		if (list->token->token_type == SINGLE_QUOTE || list->token->token_type == DOUBLE_QUOTE)
// 			list->token->word_type = NORMAL;
// 		else
// 			list->token->word_type = ft_word_type_analyzer(tokens_words, i);
// 		list->next = calloc(1,sizeof(t_tokens_list));
// 		if (!list->next)
// 			return (NULL);
// 		list = list->next;
// 		i++;
// 	}
// 	list = NULL;
// 	return (head);
// }

t_tokens_list	*ft_fill_tokens_list(char **tokens_words)
{
    int				i = 0;
    t_tokens_list	*list;
    t_tokens_list	*tmp = NULL;
    t_tokens_list	*head = NULL;

    while (tokens_words[i])
    {
        list = calloc(1, sizeof(t_tokens_list));
        if (!list)
            return (NULL);
        list->token = calloc(1, sizeof(t_token));
        if (!list->token)
            return (NULL);
        if (head == NULL)
            head = list;
        else
            tmp->next = list;
        list->token->value = ft_strdup(tokens_words[i]);
        list->token->token_type = ft_token_analyzer(tokens_words[i]);
        if (list->token->token_type == SINGLE_QUOTE || list->token->token_type == DOUBLE_QUOTE)
            list->token->word_type = NORMAL;
        else
            list->token->word_type = ft_word_type_analyzer(tokens_words, i);
        list->next = NULL;
        tmp = list;
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
	int i = 0;
	while (tokens_words[i])
	{
		// printf("'%s'\n", tokens_words[i]);
		i++;
	}
	printf("count -> %i\n", i);

	tokens_list =ft_fill_tokens_list(tokens_words);
	if (!tokens_list)
		return (NULL);
	// check ft_fill_tokens_list return value if return value is 1 then free tokens_list
	// you must free tokens_words regardless of the return value of ft_fill_tokens_list
	// ft_fill_tokens_list(tokens_list, tokens_words);
	return (tokens_list);
}