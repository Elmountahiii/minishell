/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_command_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:43:22 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/17 20:47:52 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_skip_tokens_spaces(t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	while (*tokens && (*tokens)->type == SPACE_TOKEN)
		*tokens = (*tokens)->next;
}

char	**ft_append_to_list_tokens(char **list, t_tokens_list **tokens)
{
	int		len;
	char	**new_list;

	len = 0;
	while (list[len])
		len++;
	new_list = ft_calloc(len + 2, sizeof(char *));
	if (!new_list)
		return (NULL);
	len = 0;
	while (list[len])
	{
		new_list[len] = ft_strdup(list[len]);
		len++;
	}
	if (*tokens && (*tokens)->type == ENV)
	{
		new_list[len] = ft_strdup((*tokens)->value);
		*tokens = (*tokens)->next;
	}
	else
		new_list[len] = ft_join(NULL, tokens);
	new_list[len + 1] = NULL;
	ft_free_array(list);
	return (new_list);
}

char	**ft_append_to_list(char **list, char *command)
{
	int		len;
	char	**new_list;

	if (!command)
		return (list);
	len = 0;
	while (list && list[len])
		len++;
	new_list = ft_calloc(len + 2, sizeof(char *));
	if (!new_list)
		return (NULL);
	len = 0;
	while ( list && list[len])
	{
		new_list[len] = ft_strdup(list[len]);
		len++;
	}
	new_list[len] = command;
	new_list[len + 1] = NULL;
	ft_free_array(list);
	return (new_list);
}

void	ft_handle_word(t_command *node, t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	if (((*tokens)->type == WORD
			|| (*tokens)->type == SINGLE_QUOTE_WORD
			|| (*tokens)->type == DOUBLE_QUOTE_WORD
			|| (*tokens)->type == ENV))
	{
		
		if (!(*tokens)->value  || ft_strlen((*tokens)->value) == 0)
		{
			*tokens = (*tokens)->next;
			return ;
		}
		node->command_args = ft_append_to_list_tokens(node->command_args,
				tokens);
	}
}

void	ft_handle_redirection(t_command *node, t_tokens_list **tokens)
{
	t_token_type 	type;
	char			*file_name;
	t_command_files	*new;
	
	if (!tokens || !*tokens)
		return ;
	file_name = NULL;
	if ((*tokens)->type == REDIRECTION_IN || (*tokens)->type == REDIRECTION_OUT)
	{
		if((*tokens)->type == REDIRECTION_IN)
			node->is_heredoc = false;
		else
			node->is_append = false;
		type = (*tokens)->type;
		if (type == REDIRECTION_IN)
			node->in_type = FILE_IO;
		else
			node->out_type = FILE_IO;
		*tokens = (*tokens)->next;
		ft_skip_tokens_spaces(tokens);
		file_name = ft_handle_file_name(tokens);
		new = ft_create_file_node(file_name, type);
		ft_files_addback(&node->files_list, new);
		free(file_name);
	}
}
