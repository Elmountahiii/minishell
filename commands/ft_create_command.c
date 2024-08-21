/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:45:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/21 10:32:47 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_to_array(char **old, char **buffer, char **new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (old && old[i])
	{
		buffer[i] = ft_strdup(old[i]);
		i++;
	}
	while (new && new[j])
	{
		buffer[i + j] = ft_strdup(new[j]);
		j++;
	}
	buffer[i + j] = NULL;
}

void	ft_add_args(t_command *command, t_tokens_list **token,
	t_env_list *env_list)
{
	char	**expanded;
	char	**tmp;
	char	*value;

	if (!command || !token)
		return ;
	tmp = NULL;
	if (!command->command_args)
		command->command_args = ft_calloc(1, sizeof(char *));
	else
		tmp = command->command_args;
	value = ft_join_token_value(token, env_list);
	expanded = ft_expand_value(value);
	command->command_args
		= ft_calloc((ft_array_len(tmp) + ft_array_len(expanded) + 1),
			sizeof(char *));
	if (!command->command_args)
		return (ft_clean_array(tmp), ft_clean_array(expanded));
	ft_add_to_array(tmp, command->command_args, expanded);
	ft_clean_array(tmp);
	ft_clean_array(expanded);
}

void	ft_change_input_type(t_command *command, t_tokens_list **tokens)
{
	t_token_type	type;

	if (!command || !tokens || !*tokens)
		return ;
	type = (*tokens)->type;
	if (type == SPACE_TOKEN)
		return ;
	if (type == REDIRECTION_IN || type == HEREDOC)
	{
		if (type == HEREDOC)
			command->is_heredoc = true;
		else
			command->is_heredoc = false;
		command->in_type = FILE_IO;
	}
	else if (type == REDIRECTION_OUT || type == APPEND)
	{
		if (type == APPEND)
			command->is_append = true;
		else
			command->is_append = false;
		command->out_type = FILE_IO;
	}
}

void	ft_skip_that_token(t_tokens_list **tokens)
{
	if (*tokens)
		(*tokens) = (*tokens)->next;
	if (*tokens && (*tokens)->type == SPACE_TOKEN)
		(*tokens) = (*tokens)->next;
	while (*tokens && ft_check_word_valid((*tokens)->type))
		(*tokens) = (*tokens)->next;
}

t_command	*ft_create_command(t_tokens_list **tokens, t_env_list *env_list)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	if (!command)
		return (NULL);
	command->out_type = STDOUT_IO;
	command->command_args = ft_calloc(1, sizeof(char *));
	while (*tokens && (*tokens)->type != PIPE)
	{
		if (ft_check_word_valid((*tokens)->type))
		{
			ft_add_args(command, tokens, env_list);
			if (*tokens && (*tokens)->type == PIPE)
				break ;
		}
		if (*tokens && ft_check_redirection_valid((*tokens)->type))
		{
			ft_change_input_type(command, tokens);
			ft_skip_that_token(tokens);
			continue ;
		}
		if (*tokens)
			(*tokens) = (*tokens)->next;
	}
	return (command);
}
