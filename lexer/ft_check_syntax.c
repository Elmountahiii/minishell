/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:24:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 14:15:20 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_append_syntax(t_tokens_list *list)
{
	if (!list)
		return (1);
	if (list->type == APPEND)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == APPEND)
				return (syntax_error('a'));
			else if (list->type == REDIRECTION_IN)
				return (syntax_error('<'));
			else if (list->type == REDIRECTION_OUT)
				return (syntax_error('>'));
		}
		else
			return (syntax_error('n'));
	}
	return (0);
}

int	ft_check_herdoc_syntax(t_tokens_list *list)
{
	if (!list)
		return (1);
	if (list->type == HEREDOC)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == HEREDOC)
				return (syntax_error('a'));
			else if (list->type == REDIRECTION_IN)
				return (syntax_error('<'));
			else if (list->type == REDIRECTION_OUT)
				return (syntax_error('>'));
			else if (list->type == APPEND)
				return (syntax_error('a'));
		}
		else
			return (syntax_error('n'));
	}
	return (0);
}

int	ft_check_word_syntax(t_tokens_list *token)
{
	int len;

	len = 0;
	if (token && (token->type == SINGLE_QUOTE_WORD ||  token->type == DOUBLE_QUOTE_WORD))
	{
		len = ft_strlen(token->value);
		if (len == 1)
			return (syntax_error('n'));
	}		
	return (0);
}

int	ft_check_syntax(t_tokens_list *list)
{
	t_tokens_list	*tmp;

	tmp = list;
	ft_skip_tokens_spaces(&tmp);
	if (tmp && tmp->type == PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		return (1);
	}
	while (tmp)
	{
		if (ft_check_word_syntax(tmp) || ft_check_pipe_syntax(tmp))
			return (1);
		if (ft_check_redin_syntax(tmp) || ft_check_redout_syntax(tmp))
			return (1);
		if (ft_check_append_syntax(tmp) || ft_check_herdoc_syntax(tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
