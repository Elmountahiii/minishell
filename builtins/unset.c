/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:49:55 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/15 12:44:38 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_node(t_env_list *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	our_unset(char *key, t_be_executed	*to_execute)
{
	t_env_list	*tmp;
	t_env_list	*previous;

	tmp = *to_execute->env_list;
	previous = NULL;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
		{
			if (*to_execute->env_list == tmp)
				*to_execute->env_list = (*to_execute->env_list)->next;
			else
				previous->next = tmp->next;
			break ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
}

void	hand_er(char *arg, int procss, int *exit_stts)
{
	write(2, "minishell: unset: `", 20);
	write(2, arg, ft_strlen(arg));
	write(2, "': not a valid identifier\n", 26);
	if (procss)
	{
		if (*exit_stts == 0)
			*exit_stts = 1;
	}
	else
	{
		if (exit_status == 0)
			exit_status = 1;
	}
}

void	check_first(t_command *command, int procss)
{
	if (command->command_args[1] == NULL)
	{
		if (procss)
			exit(0);
		else
			exit_status = 0;
	}
}

void	ft_unset(t_command *command, t_be_executed	*to_execute, int procss)
{
	int		exit_stts;
	char	**args;
	int		i;

	i = 0;
	args = command->command_args;
	exit_stts = 0;
	check_first(command, procss);
	while (args[i])
	{
		if (!check_every_arg(args[i]))
			our_unset(args[i], to_execute);
		else
			hand_er(args[i], procss, &exit_stts);
		i++;
	}
	if (procss)
		exit(exit_stts);
}
