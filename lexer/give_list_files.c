/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_list_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:22:42 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/09 16:44:31 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

t_list_files	*creat_file_node(char *str, t_token_type type, t_command *command, t_token_type token_type)
{
	t_list_files	*node;
	char			*unquoted;

	node = malloc(sizeof(t_list_files));
	if (!node)
		return (NULL);
	if (token_type == SINGLE_QUOTE_WORD || token_type == DOUBLE_QUOTE_WORD) 
		unquoted = ft_remove_quotes(str);
	else
		unquoted = ft_strdup(str);
	if (type == REDIRECTION_IN)
		node->fd = open(unquoted, O_RDONLY);
	else if (type == REDIRECTION_OUT)
		node->fd = open(unquoted, O_CREAT | O_RDWR | O_TRUNC, 0666);
	else if (type == APPEND)
		node->fd = open(unquoted, O_CREAT | O_RDWR | O_APPEND, 0666);
	node->name = unquoted;
	node->next = NULL;
	if (command)
		node->id = command->index;
	return (node);
}

int	add_file(t_list_files	**list, char	*str, t_token_type type ,t_command *command , t_token_type token_type)
{
	t_list_files	*tmp;
	t_list_files	*node;

	tmp = *list;
	node = NULL;
	if (!(*list))
	{
		node = creat_file_node(str, type, command , token_type);
		*list = node;
		if (!node)
			return (-1);
		return ((*list)->fd);
	}
	while (tmp->next) 
		tmp = tmp->next;
	node =  creat_file_node(str, type, command, token_type);
	tmp->next = node;
	if (!node)
		return (-1);
	return (tmp->next->fd);
}

t_list_files	*give_list_files(t_tokens_list	*list_tokens, t_command *command)
{
	t_list_files	*list_files;
	t_token_type	type;
	t_command		*tmp;
	int 			result;

	list_files = NULL;
	tmp = command;
	result = 0;
	while (list_tokens && tmp)
	{
		if (list_tokens && (list_tokens->type == REDIRECTION_IN || list_tokens->type == REDIRECTION_OUT || list_tokens->type == APPEND || list_tokens->type == ENV))
		{
			type = list_tokens->type;
			list_tokens  = list_tokens->next;
			if (list_tokens && list_tokens->type == SPACE_TOKEN)
				list_tokens = list_tokens->next;
			if (list_tokens && (list_tokens->type == WORD || list_tokens->type == SINGLE_QUOTE_WORD || list_tokens->type == DOUBLE_QUOTE_WORD  || list_tokens->type == ENV))
			{
				result = add_file(&list_files, list_tokens->value , type, tmp, list_tokens->type);
				if (result == -1)
				{
					if (tmp)
						tmp = tmp->next;
					while (list_tokens && list_tokens->type != PIPE)
					{
						if (list_tokens)
							list_tokens = list_tokens->next;
					}
				}
					
				if (list_tokens)
					list_tokens = list_tokens->next;
			} 
		}else if (list_tokens && list_tokens->type == PIPE)
		{
			if (tmp)
				tmp = tmp->next;
			
			if (list_tokens)
				list_tokens = list_tokens->next;
		}
		else
		{
			if (list_tokens)
				list_tokens = list_tokens->next;	
		}
	}
	return (list_files);
}
