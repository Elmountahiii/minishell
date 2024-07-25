/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:06:51 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/25 15:39:08 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_skip_tokens_spaces(t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	while (*tokens && (*tokens)->type == SPACE)
		*tokens = (*tokens)->next;
}

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

void 	ft_handle_word(t_command *node, t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
		
	if ((*tokens)->type == WORD 
		|| (*tokens)->type == SINGLE_QUOTE_WORD 
		||(*tokens)->type == DOUBLE_QUOTE_WORD 
		|| (*tokens)->type == ENV)
	{
		node->command_args = ft_append_to_list(node->command_args, (*tokens)->value);
		*tokens = (*tokens)->next;
	}
}

void	ft_handle_redirection(t_command *node, t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	if ((*tokens)->type == REDIRECTION_IN)
	{
		node->in_type = FILE_IO;
		*tokens = (*tokens)->next;
		ft_skip_tokens_spaces(tokens);
		if (*tokens)
		{
			node->in_file = ft_strdup((*tokens)->value);
			*tokens = (*tokens)->next;	
		}
	}else if ((*tokens)->type == REDIRECTION_OUT)
	{
		node->out_type = FILE_IO;
		*tokens = (*tokens)->next;
		ft_skip_tokens_spaces(tokens);
		if (*tokens)
		{
			node->out_file = ft_strdup((*tokens)->value);
			*tokens = (*tokens)->next;
		}
	}
}

void	ft_handle_append(t_command *node, t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	if ((*tokens)->type == APPEND)
	{
		node->out_type = FILE_IO;
		node->is_append = true;
		*tokens = (*tokens)->next;
		ft_skip_tokens_spaces(tokens);
		if (*tokens)
		{
			node->out_file = ft_strdup((*tokens)->value);
			*tokens = (*tokens)->next;	
		}
	}
}

void	ft_handle_heredoc(t_command *node, t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	if ((*tokens)->type == HEREDOC)
	{
		node->in_type = FILE_IO;
		node->is_heredoc = true;
		*tokens = (*tokens)->next;
		ft_skip_tokens_spaces(tokens);
		if (*tokens)
		{
			node->in_file = ft_strdup((*tokens)->value);
			*tokens = (*tokens)->next;
		}
	}
}
void	until_pipe(t_command *node,t_tokens_list *tokens)
{
	
	while (tokens &&tokens->type != PIPE)
	{
		ft_handle_redirection(node, &tokens);
		ft_handle_append(node, &tokens);
		ft_handle_heredoc(node, &tokens);
		ft_handle_word(node, &tokens);
		if (tokens && tokens->type == SPACE)
			tokens = tokens->next;
	}
	if (node->out_type == STDIN_IO)
	{
		node->out_type = STDOUT_IO;
		node->out_file = NULL;
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
		until_pipe(commands_list, tokens_list);
		while (tokens_list && tokens_list->type != PIPE)
				tokens_list = tokens_list->next;
		if (tokens_list && tokens_list->type == PIPE)
		{
			if (commands_list->out_type == STDOUT_IO)
				commands_list->out_type = PIPE_IO;
			tokens_list = tokens_list->next;
		}
		else
		{
			commands_list->next = NULL;
			break;
		}
		commands_list->next = calloc(1, sizeof(t_command));
		commands_list->next->command_args = calloc(1, sizeof(char *));
		if (!commands_list->next)
			return (NULL);
		commands_list = commands_list->next;
		commands_list->in_type = PIPE_IO;
	}
	return (head);
}
