/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:33:07 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/19 14:46:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	syntax_error(char token)
{
	(void)token;
	ft_putstr_fd("minishell: syntax error\n", STDERR_FILENO);
	g_exit_status = 258;
	return (1);
}

int	ft_check_pipe_syntax(t_tokens_list *list)
{
	if (!list)
		return (1);
	if (list->type == PIPE)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == PIPE)
				return (syntax_error('|'));
		}
		else
			return (syntax_error('n'));
	}
	return (0);
}

int	ft_check_redin_syntax(t_tokens_list *list)
{
	if (!list)
		return (1);
	if (list->type == REDIRECTION_IN)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == REDIRECTION_IN)
				return (syntax_error('<'));
			else if (list->type == PIPE)
				return (syntax_error('|'));
			else if (list->type == REDIRECTION_OUT)
				return (syntax_error('>'));
			else if (list->type == APPEND)
				return (syntax_error('a'));
		}
		else
			return (syntax_error('<'));
	}
	return (0);
}

void	ft_skip_tokens_spaces(t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	while (*tokens && (*tokens)->type == SPACE_TOKEN)
		*tokens = (*tokens)->next;
}

int	ft_check_redout_syntax(t_tokens_list *list)
{
	if (!list)
		return (1);
	if (list->type == REDIRECTION_OUT)
	{
		list = list->next;
		ft_skip_tokens_spaces(&list);
		if (list)
		{
			if (list->type == REDIRECTION_OUT)
				return (syntax_error('>'));
			else if (list->type == REDIRECTION_IN)
				return (syntax_error('<'));
			else if (list->type == APPEND)
				return (syntax_error('a'));
			else if (list->type == PIPE)
				return (syntax_error('|'));
		}
		else
			return (syntax_error('n'));
	}
	return (0);
}
