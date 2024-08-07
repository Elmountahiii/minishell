/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_command_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:04:28 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/07 11:59:45 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command	*ft_command_allocate(void)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	if (!command)
		return (NULL);
	command->command_args = calloc(1, sizeof(char *));
	if (!command->command_args)
		return (NULL);
	return (command);
}

int	ft_command_next(t_command **commands_list, t_tokens_list **tokens_list)
{
	if (*tokens_list && (*tokens_list)->type == PIPE)
	{
		if ((*commands_list)->out_type == STDOUT_IO)
			(*commands_list)->out_type = PIPE_IO;
		*tokens_list = (*tokens_list)->next;
	}
	else
	{
		(*commands_list)->next = NULL;
		return (1);
	}
	return (0);
}
