/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:06:51 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/10 13:33:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handle_append(t_command *node, t_tokens_list **tokens)
{
	char			*file_name;
	t_command_files	*file;
	t_token_type	type;
	
	if (!tokens || !*tokens) 
		return ;
	file_name = NULL;
	if ((*tokens)->type == APPEND)
	{
		type = (*tokens)->type;
		node->is_append = true;
		node->out_type = FILE_IO;
		*tokens = (*tokens)->next;
		ft_skip_tokens_spaces(tokens);
		file_name = ft_handle_file_name(tokens);
		file = ft_create_file_node(file_name, type);
		ft_files_addback(&node->files_list, file);
		free(file_name);
	}
}

void	ft_handle_heredoc(t_command *node, t_tokens_list **tokens, t_command *head)
{
	if (!tokens || !*tokens)
		return;
	if ((*tokens)->type == HEREDOC)
	{
		node->in_type = FILE_IO;
		node->is_heredoc = true;
		*tokens = (*tokens)->next;
		ft_skip_tokens_spaces(tokens);
		if (*tokens)
		{
			ft_heredoc_addback(&node->heredoc_list, ft_create_heredoc(head, (*tokens)->value, (*tokens)->type));
			*tokens = (*tokens)->next;
		}
	}
}

void	until_pipe(t_command *node, t_tokens_list *tokens , t_command *head)
{
	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == SPACE_TOKEN)
		{
			tokens = tokens->next;
			continue ;
		}
		ft_handle_word(node, &tokens);
		ft_handle_redirection(node, &tokens);
		ft_handle_append(node, &tokens);
		ft_handle_heredoc(node, &tokens, head);
	}
	if (node->out_type == STDIN_IO)
	{
		node->out_type = STDOUT_IO;
		node->fd_out = STDOUT_FILENO;
		node->out_file = NULL;
	}
}

t_command	*ft_split_to_command(t_tokens_list *tokens_list)
{
	t_command	*commands_list;
	t_command	*head;
	int			index;

	index = 0;
	commands_list = ft_command_allocate();
	head = commands_list;
	while (commands_list && tokens_list)
	{
		commands_list->index = index;
		until_pipe(commands_list, tokens_list, head);
		while (tokens_list && tokens_list->type != PIPE)
			tokens_list = tokens_list->next;
		if (ft_command_next(&commands_list, &tokens_list))
			break ;
		commands_list->next = ft_command_allocate();
		commands_list = commands_list->next;
		commands_list->in_type = PIPE_IO;
		index++;
	}
	return (head);
}
