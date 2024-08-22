/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:20:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/22 13:17:05 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_get_token_name(t_tokens_list **tokens)
{
	char	*value;
	char	*tmp;

	if (!tokens || !*tokens)
		return (NULL);
	value = ft_strdup("");
	while (*tokens)
	{
		if (ft_check_word_valid((*tokens)->type))
		{
			tmp = ft_strdup((*tokens)->value);
			value = ft_strjoin_free(value, tmp);
			free(tmp);
		}
		else
			break ;
		if (*tokens)
			*tokens = (*tokens)->next;
	}
	return (value);
}

void	ft_handle_redirection(t_command_files *file,
	t_tokens_list **tokens, t_env_list *env_list)
{
	char			*value;
	t_tokens_list	*tmp;

	if (!file || !tokens || !*tokens || !env_list)
		return ;
	value = NULL;
	file->type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (*tokens && (*tokens)->type == SPACE_TOKEN)
		*tokens = (*tokens)->next;
	if (!*tokens)
		return ;
	tmp = *tokens;
	value = ft_get_token_name(&tmp);
	file->file_name = ft_get_file_name(tokens, env_list);
	if (ft_check_ambig(file))
	{
		file->ambiguous_name = ft_strdup(value);
		file->is_ambiguous = true;
	}
	else
		file->is_ambiguous = false;
	free(value);
}

int	ft_is_valid_redirection(t_token_type type)
{
	if (type == REDIRECTION_IN || type == REDIRECTION_OUT || type == APPEND)
		return (1);
	return (0);
}

int	ft_check_redirection(t_tokens_list *tokens)
{
	t_tokens_list	*tmp;

	if (!tokens)
		return (0);
	tmp = tokens;
	while (tmp)
	{
		if (ft_is_valid_redirection(tmp->type))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_command_files	*ft_create_files(t_tokens_list **tokens, t_env_list *env_list)
{
	t_command_files	*files;

	if (!tokens || !*tokens)
		return (NULL);
	if (!ft_check_redirection(*tokens))
		return (NULL);
	files = ft_calloc(1, sizeof(t_command_files));
	if (!files)
		return (NULL);
	files->fd = -1;
	files->is_ambiguous = false;
	while (*tokens && (*tokens)->type != PIPE)
	{
		if (ft_is_valid_redirection((*tokens)->type))
		{
			ft_handle_redirection(files, tokens, env_list);
			break ;
		}
		if (*tokens)
			(*tokens) = (*tokens)->next;
	}
	return (files);
}
