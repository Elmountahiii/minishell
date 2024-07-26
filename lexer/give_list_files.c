/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_list_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:22:42 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/26 17:23:58 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef enum {
// 	WORD,
// 	SPACE,
// 	PIPE,
// 	SINGLE_QUOTE_WORD,
// 	DOUBLE_QUOTE_WORD,
// 	REDIRECTION_IN,
// 	REDIRECTION_OUT,
// 	APPEND,
// 	HEREDOC,
// 	ENV,
// } t_token_type;

#include "../minishell.h"

t_list_files	*creat_file_node(char *str, t_token_type type)
{
	t_list_files	*node;

	node = malloc(sizeof(t_list_files));
	if (!node)
		return (NULL);
	if (type == REDIRECTION_IN)
		node->fd = open(str, O_RDONLY);
	else if (type == REDIRECTION_OUT)
		node->fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEND)
		node->fd = open(str, O_CREAT | O_WRONLY | O_APPEND);
	node->name = str;
	node->next = NULL;
	// close(node->fd);
	return (node);
}

void	add_file(t_list_files	**list, char	*str, t_token_type type)
{
	t_list_files	*tmp;

	tmp = *list;
	if (!(*list))
	{
		*list = creat_file_node(str, type);
		return ;
	}
	while (tmp->next) 
		tmp = tmp->next;
	tmp->next = creat_file_node(str, type);
}

t_list_files	*give_list_files(t_tokens_list	*list_tokens)
{
	t_list_files	*list_files;
	t_token_type	type;

	list_files = NULL;
	while (list_tokens)
	{
		if (list_tokens->type == REDIRECTION_IN || list_tokens->type == REDIRECTION_OUT || list_tokens->type == APPEND)
		{
			type = list_tokens->type;
			list_tokens  = list_tokens->next;
			if (list_tokens && list_tokens->type == SPACE)
				list_tokens = list_tokens->next;
			if (list_tokens && (list_tokens->type == WORD || list_tokens->type == SINGLE_QUOTE_WORD || list_tokens->type == DOUBLE_QUOTE_WORD ))
			{
				// printf("list_tokens->value: %s\n", list_tokens->value);
				add_file(&list_files, list_tokens->value , type);
			}
			else
				write(2, "after a redirection a word should exist\n", 40);
		}
		if (list_tokens)
			list_tokens = list_tokens->next;
	}
	return (list_files);
}
