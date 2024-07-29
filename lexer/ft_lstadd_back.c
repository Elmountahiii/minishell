/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:13:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/29 18:02:53 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_tokens_add_back(t_tokens_list **tokens, t_tokens_list *new)
{
	t_tokens_list	*last;

	if (!tokens || !new)
		return ;
	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	last = *tokens;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_commands_dd_back(t_command **commands, t_command *new)
{
	t_command	*last;

	if (!commands || !new)
		return ;
	if (!*commands)
	{
		*commands = new;
		return ;
	}
	last = *commands;
	while (last->next)
		last = last->next;
	last->next = new;
}
