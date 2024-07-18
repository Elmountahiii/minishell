/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:06:51 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/18 16:49:12 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **ft_append_to_list(char **list,char *command)
{
	int len;
	char **new_list;
	
	if (!command)
		return (list);
	len = 0;
	while ( list[len])
		len++;
	new_list = calloc(len + 2, sizeof(char *));
	if (!new_list)
		return (NULL);
	len = 0;
	while (list[len])
	{
		new_list[len] = ft_strdup(list[len]);
		len++;
	}
	new_list[len] = ft_strdup(command);
	new_list[len + 1] = NULL;
	return (new_list);	
}

void	until_pipe(t_command *node,t_tokens_list *tokens)
{
	
	while (tokens && tokens->token &&tokens->token->token_type != PIPE)
	{
		if (tokens->token->token_type != SPACE)
			node->command_args = ft_append_to_list(node->command_args, tokens->token->value);
		tokens = tokens->next;
	}
}
t_command  *ft_split_to_command(t_tokens_list *tokens_list)
{
	t_command *commands_list;
	t_command *head;


	commands_list = calloc(1, sizeof(t_command));
	head = commands_list;
	if (!commands_list)
		return (NULL);
	commands_list->command_args = calloc(1, sizeof(char *));
	if (!commands_list->command_args)
		return (NULL);
	while (tokens_list)
	{
		// joining the tokens into commands
	
		until_pipe(commands_list, tokens_list);
		while (tokens_list && tokens_list->token && tokens_list->token->token_type != PIPE)
				tokens_list = tokens_list->next;
		if (tokens_list && tokens_list->token && tokens_list->token->token_type == PIPE)
			tokens_list = tokens_list->next;
		else
		{
			commands_list->next = NULL;
			break;
		}
		commands_list->next = calloc(1, sizeof(t_command));
		if (!commands_list->next)
			return (NULL);
		commands_list = commands_list->next;
	}
	return (head);
}
