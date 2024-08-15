/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_list_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:39:02 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/05 11:06:23 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipe	*give_node_pipe(void)
{
	t_pipe	*node;

	node = malloc(sizeof(t_pipe));
	if (!node)
		return (NULL);
	if (pipe(node->fd) == -1)
	{
		perror("pipe");
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

int	add_new_node(t_pipe	**list)
{
	t_pipe	*tmp;
	t_pipe	*node;

	tmp = *list;
	node = give_node_pipe();
	if (node == NULL)
	{
		perror("pipe");
		return (1);
	}
	if (!(*list))
	{
		*list = node;
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (0);
}

void free_pipe_list(t_pipe *pipes_list)
{
	t_pipe	*tmp;

	while (pipes_list)
	{
		tmp = pipes_list;
		pipes_list = pipes_list->next;
		close(tmp->fd[0]);
		close(tmp->fd[1]);
		free(tmp);
	}
}

t_pipe	*give_list_pipes(t_tokens_list	*tokens_list)
{
	t_pipe	*pipes_list;

	pipes_list = NULL;
	while (tokens_list)
	{
		if (tokens_list->type == PIPE)
		{
			if (add_new_node(&pipes_list))
			{
				free_pipe_list(pipes_list);
				return (NULL);
			}
		}
		tokens_list = tokens_list->next;
	}
	return (pipes_list);
}
