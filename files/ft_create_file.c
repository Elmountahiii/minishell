/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:20:38 by yel-moun          #+#    #+#             */
/*   Updated: 2024/08/15 19:09:16 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handle_redirection(t_command_files *file, t_tokens_list **tokens, t_env_list *env_list)
{
	char	*value;
	
	if (!file || !tokens || !*tokens || !env_list)
		return ;
	value = NULL;
	file->type = (*tokens)->type;
	*tokens = (*tokens)->next;
	if (*tokens && (*tokens)->type == SPACE_TOKEN)
		*tokens = (*tokens)->next;
	if (!*tokens)
		return ;
	if (*tokens && (*tokens)->type == DOUBLE_QUOTE_WORD)
		value = ft_remove_quotes((*tokens)->value);
	else
		value = strdup((*tokens)->value); 
	file->files = ft_get_expand_split(value, env_list);
	// ft_print_array(file->files);
	// printf("array len = %d\n", ft_array_len(file->files));
	if (ft_array_len(file->files) > 1)
	{
		file->ambiguous_name = strdup((*tokens)->value);
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
	files = calloc(1,sizeof(t_command_files));
	if (!files)
		return (NULL);
	files->fd = -1;
	files->is_ambiguous = false;
	while (*tokens && (*tokens)->type != PIPE)
	{
		if (ft_is_valid_redirection((*tokens)->type))
		{
			ft_handle_redirection(files, tokens, env_list);
			if (*tokens)
				(*tokens) = (*tokens)->next;
			break;
		}
		if (*tokens)
			(*tokens) = (*tokens)->next;
	}
	return (files);
}
