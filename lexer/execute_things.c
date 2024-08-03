/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tale <aet-tale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:35:05 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/03 11:01:18 by aet-tale         ###   ########.fr       */
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
		ft_append_to_list(env, line);
		// don't forget to free the array
		free(line);
		env_list = env_list->next;
	}
	return (env);
}

void print_error(char *prefix, char *command)
{
	write(2, prefix, ft_strlen(prefix));
	write(2, command, ft_strlen(command));
	write(2, ": ", 2);
	if (errno == 14)
		write(2, "command not found\n", 18);
	// else if (errno == 2)
	// {
			
	// }
}

void	execute_command(t_command *command, t_pipe *list_of_pipes)
{
	char **env;
	(void)list_of_pipes;
	(void)command;

	// workd on out ad in files
	env = give_array_str(command->env_list);
	execve(command->path, command->command_args, env);
	print_error("minishell: ", command->command_args[0]);
	// printf("erno: %i\n", errno);
	// perror("mini:");
	// printf("comaand: %i\n", command->index);
	// (void)command;
	// dup2(command->fd_in, 0);
	// dup2(command->fd_out, 1);
	// check if builtin
	// close pipes
	exit(errno);
}

int	is_built_in(char	*command)
{
	if (ft_strcmp(command, "echo") == 0)
		return (1);
	else if (ft_strcmp(command, "cd") == 0)
		return (1);
	else if (ft_strcmp(command, "pwd") == 0)
		return (1);
	else if (ft_strcmp(command, "export") == 0)
		return (1);
	else if (ft_strcmp(command, "unset") == 0)
		return (1);
	else if (ft_strcmp(command, "env") == 0)
		return (1);
	else if (ft_strcmp(command, "exit") == 0)
		return (1);
	return (0);
}

void	execute_built_in(t_command	*command, t_pipe *list_of_pipes, t_env_list **env_list, int procss)
{
	// (void)command;
	// work on output and input files
	if (ft_strcmp(command->command_args[0], "echo") == 0)
		our_echo(command->command_args, procss);
	else if (ft_strcmp(command->command_args[0], "cd") == 0)
		our_cd(command->command_args, env_list, procss);
	else if (ft_strcmp(command->command_args[0], "pwd") == 0)
		our_pwd();
	else if (ft_strcmp(command->command_args[0], "unset") == 0)
		our_unset(command->command_args[1], env_list, procss);
	else if (ft_strcmp(command->command_args[0], "env") == 0)
		our_env(*env_list, procss);
	else if (ft_strcmp(command->command_args[0], "export") == 0 && command->command_args[1])
		ft_export(command->command_args[1], env_list, procss);
	else if (ft_strcmp(command->command_args[0], "export") == 0 && !command->command_args[1])
		ft_export_env(*env_list, procss);
	else if (ft_strcmp(command->command_args[0], "exit") == 0 && command->command_args[1])
		our_exit(ft_atoi(command->command_args[1]));
	else if (ft_strcmp(command->command_args[0], "exit") == 0 && !command->command_args[1])
		our_exit(exit_status);
	(void)list_of_pipes;
}

void	execute_things(t_be_executed	*to_execute)
{
	t_command	*commands_list;
	int 		status;
	pid_t		*pid;
	int			i;

	i = 0;
	commands_list = to_execute->commands_list;
	if (to_execute->list_size == 1 && is_built_in(commands_list->command_args[0]))
	{
		execute_built_in(commands_list, to_execute->list_pipes, to_execute->env_list, 0);
		return ;
	}
	pid = malloc(sizeof(pid_t)*(to_execute->list_size));
	while (commands_list)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (is_built_in(commands_list->command_args[0]))
			{
				execute_built_in(commands_list, to_execute->list_pipes, to_execute->env_list, 1);
			}
			else
				execute_command(commands_list, to_execute->list_pipes);
		}
		i++;
		commands_list = commands_list->next;
	}
	i = 0;
	while (i < to_execute->list_size)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			exit_status = WTERMSIG(status);
		i++;
	}
}
