/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:35:05 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/28 16:27:11 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void execute_one_command(t_command *command, t_list_files *list_of_files)
{
	(void)command;
	(void)list_of_files;
	return;
}

void execute_command(t_command *command, t_list_files *list_of_files)
{
	(void)command;
	(void)list_of_files;
	// change the stdin to command->fd_in
	// change the stdout to command->fd_out
	execve(command->path, command->command_args, NULL);
	return;
}

int	check_path(t_command *command_list)
{
	while (command_list)
	{
		if (command_list->path == NULL)
		{
			write(2, "command not found\n", 19);
			return (1);
		}
		command_list = command_list->next;
	}
	return (0);
}

void execute_things(t_command *command_list, t_list_files *list_of_files)
{
	t_command	*tmp;
	pid_t		pid;

	tmp = command_list;
	pid = 1;
	if (check_path(command_list))
		return ;
	if (command_list->next == NULL)
	{
		execute_one_command(command_list, list_of_files);
		return ;
	}
	while (tmp)
	{
		if (pid != 0)
		{
			pid = fork();
		}else
		{
			execute_command(tmp, list_of_files);
		}
		tmp = tmp->next;
	}
}
