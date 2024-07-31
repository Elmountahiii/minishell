/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_command_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:43:22 by yel-moun          #+#    #+#             */
/*   Updated: 2024/07/31 19:11:05 by yel-moun         ###   ########.fr       */
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

char	**ft_append_to_list_tokens(char **list, t_tokens_list **tokens)
{
	int		len;
	char	**new_list;

	len = 0;
	while (list[len])
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
	new_list[len] = ft_join(NULL, tokens);
	new_list[len + 1] = NULL;
	return (new_list);
}

char	**ft_append_to_list(char **list, char *command)
{
	int		len;
	char	**new_list;

	if (!command)
		return (list);
	len = 0;
	while (list[len])
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
	new_list[len] = ft_clean_string(ft_split_clean(command));
	new_list[len + 1] = NULL;
	return (new_list);
}

void	ft_handle_word(t_command *node, t_tokens_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	if (*tokens && ((*tokens)->type == WORD
			|| (*tokens)->type == SINGLE_QUOTE_WORD
			|| (*tokens)->type == DOUBLE_QUOTE_WORD
			|| (*tokens)->type == ENV))
	{
		node->command_args = ft_append_to_list_tokens(node->command_args,
				tokens);
		if (*tokens)
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
	}
	else if ((*tokens)->type == REDIRECTION_OUT)
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
