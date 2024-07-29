/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_until_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:01:16 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 14:36:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_list_skip_spaces(char **tokens,int index)
{
	while (tokens[index])
	{
		if (ft_is_all_space(tokens[index]))
			break;
		index++;
	}
	return (index);
}


char *ft_join_until_space(char **tokens, int index)
{
	char *new_str;
	
	new_str = NULL;
	while (tokens[index])
	{
		if (ft_is_all_space(tokens[index]) )
			break;
		new_str = ft_strjoin(new_str, tokens[index]);
		index++;
	}
	return (new_str);
}

int	ft_is_valid_word(t_tokens_list *t)
{
	if (t->type == WORD || t->type == SINGLE_QUOTE_WORD || t->type == DOUBLE_QUOTE_WORD)
		return (1);
	return (0);
}



char *ft_custom_strjoin(char *old, t_tokens_list *token)
{
	char *new_str;
	char quote_to_remove;
	int i;
	int j;

	if (token->type == WORD)
		return (ft_strjoin(old, token->value));
	quote_to_remove = token->value[0];
	new_str = ft_calloc(ft_strlen(old) + ft_strlen(token->value) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = ft_strcpy(new_str, old);
	j = 0;
	while (token->value[j])
	{
		if (token->value[j] == quote_to_remove)
		{
			j++;
			continue;
		}
		new_str[i] = token->value[j];
		i++;
		j++;
	}
	return (new_str[i] = '\0', new_str);
}

char *ft_join(char *old, t_tokens_list **tokens)
{
	char *new_str;
	char *tmp;
	
	new_str = ft_strdup(old);
	free(old);
	tmp = NULL;
	while (*tokens && ft_is_valid_word(*tokens))
	{
		tmp = new_str;
		new_str = ft_custom_strjoin(new_str, (*tokens));
		free(tmp);
		*tokens = (*tokens)->next;
	}	
	return (new_str);
}
