/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:04:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 16:50:59 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_print_token_type(t_token_type token_type)
{
	if (token_type == WORD)
		return ("WORD");
	if (token_type == SPACE_TOKEN)
		return ("SPACE");
	if (token_type == PIPE)
		return ("PIPE");
	if (token_type == SINGLE_QUOTE_WORD)
		return ("SINGLE_QUOTE_WORD");
	if (token_type == DOUBLE_QUOTE_WORD)
		return ("DOUBLE_QUOTE_WORD");
	if (token_type == REDIRECTION_IN)
		return ("REDIRECTION_IN");
	if (token_type == REDIRECTION_OUT)
		return ("REDIRECTION_OUT");
	if (token_type == APPEND)
		return ("APPEND");
	if (token_type == HEREDOC)
		return ("HEREDOC");
	if (token_type == ENV)
		return ("ENV");
	return ("UNKNOWN");
}

void	ft_print_tokens(t_tokens_list *tokens_list)
{
	t_tokens_list	*tmp;

	tmp = tokens_list;
	while (tmp)
	{
		printf("value: '\033[32m%s\033[0m' , type: \033[34m%s\033[0m .\n",
			tmp->value, ft_print_token_type(tmp->type));
		tmp = tmp->next;
	}
}
