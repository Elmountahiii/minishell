/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_uils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:36:00 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 15:04:02 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_expandable(t_token_type type)
{
	if (type == WORD
		|| type == SINGLE_QUOTE_WORD
		|| type == DOUBLE_QUOTE_WORD
		|| type == ENV)
		return (1);
	return (0);
}

char	*ft_get_tmp(t_tokens_list *token, t_env_list *env_list)
{
	char	*tmp;
	char	*unquoted;

	if (!token)
		return (NULL);
	if (token->type == SINGLE_QUOTE_WORD)
		return (ft_remove_quotes(token->value));
	else if (token->type == DOUBLE_QUOTE_WORD)
	{
		unquoted = ft_remove_quotes(token->value);
		tmp = ft_expand(unquoted, env_list);
		free(unquoted);
		return (tmp);
	}
	else
		return (ft_expand(token->value, env_list));
}

char	*ft_get_value_name(t_tokens_list **tokens, t_env_list *env_list)
{
	char	*value;
	char	*tmp;

	if (!tokens || !*tokens)
		return (NULL);
	value = ft_strdup("");
	while (*tokens)
	{
		if (ft_check_expandable((*tokens)->type))
		{
			tmp = ft_get_tmp(*tokens, env_list);
			value = ft_strjoin_free(value, tmp);
			free(tmp);
		}
		else
			break ;
		*tokens = (*tokens)->next;
	}
	return (value);
}

char	*ft_get_file_name(t_tokens_list **tokens, t_env_list *env_list)
{
	if (!tokens || !*tokens || !env_list)
		return (NULL);
	if (ft_check_word_valid((*tokens)->type))
		return (ft_get_value_name(tokens, env_list));
	return (NULL);
}
