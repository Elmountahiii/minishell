/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:49:55 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/03 15:43:39 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_node(t_env_list *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	our_unset(t_command *command, t_be_executed	*to_execute, int procss)
{
	t_env_list	*tmp;
	t_env_list	*previous;
	int			exit_stts;

	tmp = *to_execute->env_list;
	previous = NULL;
	exit_stts = 0;
	while (tmp)
	{
		if (!ft_strcmp(command->command_args[1], tmp->key))
		{
			if (*to_execute->env_list == tmp)
			{
				*to_execute->env_list = (*to_execute->env_list)->next;
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
	if (procss)
		exit(exit_stts);
}
