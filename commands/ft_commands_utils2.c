/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 14:37:36 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/22 21:43:08 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_command_tmp(t_tokens_list **tokens)
{
	char	*tmp;

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
