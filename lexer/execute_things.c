/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:35:05 by aet-tale          #+#    #+#             */
/*   Updated: 2024/07/28 16:50:15 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void execute_one_command(t_command *command, t_list_files *list_of_files)
{
	(void)command;
	(void)list_of_files;
	
	return ;
}

char **give_array_str(t_env_list *env_list)
{
	char **env;
	char *line;

	env = NULL;
	line = NULL;
	while (env_list)
	{
		line = ft_strjoin(env_list->key, env_list->value);
		ft_append_to_list(env, line);
		// don't forget to free the array
		free(line);
		env_list = env_list->next;
	}
	return (env);
}

void execute_command(t_command *command, t_list_files *list_of_files)
{
	// (void)command;
	(void)list_of_files;
	char **env = give_array_str(command->env_list);
	// dup2(command->fd_in, 0);
	// dup2(command->fd_out, 1);
	// check if builtin
	// close pipes 
	execve(command->path, command->command_args, env);
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
			pid = fork();
		else
			execute_command(tmp, list_of_files);
		tmp = tmp->next;
	}
}
