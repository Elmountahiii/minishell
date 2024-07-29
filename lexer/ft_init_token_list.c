/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:53:54 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 17:52:18 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token_type	ft_token_analyzer(char *token)
{
	if (ft_strcmp(token, "|") == 0)
		return (PIPE);
	if (ft_strcmp(token, "<") == 0)
		return (REDIRECTION_IN);
	if (ft_strcmp(token, ">") == 0)
		return (REDIRECTION_OUT);
	if (ft_strcmp(token, ">>") == 0)
		return (APPEND);
	if (ft_strcmp(token, "<<") == 0)
		return (HEREDOC);
	if (token && token[0] == '\'')
		return (SINGLE_QUOTE_WORD);
	if (token && token[0] == '\"')
		return (DOUBLE_QUOTE_WORD);
	if (ft_is_all_space(token))
		return (SPACE);
	if (ft_strncmp(token, "$", 1) == 0)
		return (ENV);
	return (WORD);
}

t_tokens_list	*ft_fill_tokens_list(char **tokens_words)
{
	int				i;
	t_tokens_list	*token;
	t_tokens_list	*tmp;
	t_tokens_list	*head;

	i = 0;
	tmp = NULL;
	head = NULL;
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
	char			**tokens_words;
	t_tokens_list	*tokens_list;

	tokens_words = ft_extract(line);
	if (!tokens_words)
		return (NULL);
	tokens_list = ft_fill_tokens_list(tokens_words);
	if (!tokens_list)
		return (NULL);
	return (tokens_list);
}
