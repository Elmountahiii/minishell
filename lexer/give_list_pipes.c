/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_list_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:39:02 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/26 18:23:18 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_pipe	*give_node_pipe(void)
{
	t_pipe	*node;

	node = malloc(sizeof(t_pipe));
	if (!node)
		return (NULL);
	pipe(node->fd);
	node->next = NULL;
	return (node);
}

void	add_new_node(t_pipe	**list)
{
	t_pipe	*tmp;

	tmp = *list;
	if (!(*list))
	{
		*list = give_node_pipe();
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = give_node_pipe();
}


t_pipe	*give_list_pipes(t_tokens_list	*tokens_list)
{
	t_pipe			*pipes_list;

	pipes_list = NULL;
	while (tokens_list)
	{
		if (tokens_list->type == PIPE)
			add_new_node(&pipes_list);
		tokens_list = tokens_list->next;
	}
	return (pipes_list);
}