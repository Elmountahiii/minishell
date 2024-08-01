/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:35:05 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/01 11:25:53 by aet-tale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**give_array_str(t_env_list *env_list)
{
	char **env;
	char *line;

	env = NULL;
	line = NULL;
	while (env_list)
	{
		line = ft_strjoin(env_list->key, env_list->value);
		// 
		ft_append_to_list(env, line);
		// don't forget to free the array
		free(line);
		env_list = env_list->next;
	}
	return (env);
}

void	execute_one_command(t_command *command, t_pipe *list_of_pipes)
{
	(void)command;
	(void)list_of_pipes;
	char **env;

	env = give_array_str(command->env_list);
	execve(command->path, command->command_args, env);
	return ;
}


void execute_command(t_command *command, t_pipe *list_of_pipes)
{
	char **env;
	(void)list_of_pipes;
	(void)command;

	env = give_array_str(command->env_list);
	execve(command->path, command->command_args, env);
	// printf("comaand: %i\n", command->index);
	// (void)command;
	// dup2(command->fd_in, 0);
	// dup2(command->fd_out, 1);
	// check if builtin
	// close pipes
	return;
}

// int	check_path(t_command *command_list)
// {
// 	while (command_list)
// 	{
// 		if (command_list->path == NULL)
// 		{
// 			write(2, "command not found\n", 19);
// 			return (1);
// 		}
// 		command_list = command_list->next;
// 	}
// 	return (0);
// }

void	execute_things(t_be_executed	*to_execute)
{
	t_command	*commands_list;
	int 		status;
	pid_t		pid;

	commands_list = to_execute->commands_list;
	pid = 1;
	// if (check_path(commands_list))
	// 	return ;
	if (commands_list->next == NULL)
	{
		execute_one_command(commands_list, to_execute->list_pipes);
		return ;
	}
	while (commands_list)
	{
		pid = fork();
		if (pid == 0)
		{
			// printf("comaand: %i\n", commands_list->index);
			execute_command(commands_list, to_execute->list_pipes);
			exit(0);
		}
		commands_list = commands_list->next;
	}
	while (waitpid(-1, &status, 0) > 0);
}
