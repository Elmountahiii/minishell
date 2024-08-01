/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:49:55 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/01 18:59:19 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_node(t_env_list *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	our_unset(char *var, t_env_list   **list)
{
	t_env_list	*tmp;
	t_env_list	*previous;

	tmp = *list;
	previous = NULL;
	while (tmp)
	{
		if (!ft_strcmp(var, tmp->key))
		{
			if (*list == tmp)
			{
				*list = (*list)->next;
				free_env_node(tmp);
			}else {
				previous->next = tmp->next;
				free_env_node(tmp);
			}
			break;
		}
		previous = tmp;
		tmp = tmp->next;
	}
}
