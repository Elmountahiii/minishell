/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:37:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 11:14:20 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_command_tmp(t_tokens_list **tokens)
{
	char	*tmp;

	if ((*tokens)->type == SINGLE_QUOTE_WORD
		|| (*tokens)->type == DOUBLE_QUOTE_WORD)
		tmp = ft_remove_quotes((*tokens)->value);
	else
		tmp = ft_strdup((*tokens)->value);
	return (tmp);
}

int	ft_get_command_value(char **value, char **expand,
	char **tmp, t_tokens_list **tokens)
{
	if ((*tokens)->type == SINGLE_QUOTE_WORD)
		*value = ft_strjoin_free(*value, *tmp);
	else
	{
		if (ft_strlen(*expand) == 0 && (*tokens)->type != DOUBLE_QUOTE_WORD)
		{
			ft_free_command_value(*value, *expand, *tmp);
			return (1);
		}
		*value = ft_strjoin_free(*value, *expand);
	}
	free(*expand);
	free(*tmp);
	return (0);
}

int	ft_check_redirection_valid(t_token_type type)
{
	if (type == REDIRECTION_IN
		|| type == REDIRECTION_OUT
		|| type == APPEND
		|| type == HEREDOC)
		return (1);
	return (0);
}

int	ft_check_word_valid(t_token_type type)
{
	if (type == WORD
		|| type == SINGLE_QUOTE_WORD
		|| type == DOUBLE_QUOTE_WORD
		|| type == ENV)
		return (1);
	return (0);
}

char	**ft_expand_value(char *value)
{
	char	**expanded;

	expanded = ft_calloc(2, sizeof(char *));
	if (ft_strchr(value, ' '))
	{
		expanded[0] = ft_strdup(value);
		expanded[1] = NULL;
	}
	else if (value == NULL)
	{
		expanded[0] = NULL;
		expanded[1] = NULL;
	}
	else if (ft_strlen(value) == 0)
	{
		expanded[0] = ft_strdup("");
		expanded[1] = NULL;
	}
	else
	{
		ft_clean_array(expanded);
		expanded = ft_split_dil(value, ' ');
	}
	free(value);
	return (expanded);
}
