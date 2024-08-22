/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:35:05 by aet-tale          #+#    #+#             */
/*   Updated: 2024/08/22 21:08:08 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exe_built_cmds(t_be_executed *to_exe, t_command *command, int procss)
{
	if (command->fd_in != STDIN_FILENO)
		dup2(command->fd_in, STDIN_FILENO);
	if (command->fd_out != STDOUT_FILENO)
		dup2(command->fd_out, STDOUT_FILENO);
	if (ft_strcmp(command->command_args[0], "echo") == 0)
		our_echo(command, procss);
	else if (ft_strcmp(command->command_args[0], "cd") == 0)
		our_cd(command, to_exe, procss);
	else if (ft_strcmp(command->command_args[0], "pwd") == 0)
		our_pwd(command, to_exe, procss);
	else if (ft_strcmp(command->command_args[0], "unset") == 0)
		ft_unset(command, to_exe, procss);
	else if (ft_strcmp(command->command_args[0], "env") == 0)
		our_env(command, to_exe, procss);
	else if (ft_strcmp(command->command_args[0], "export") == 0)
		ft_export(command, to_exe, procss);
	else if (ft_strcmp(command->command_args[0], "exit") == 0)
		our_exit(command, to_exe, procss);
}

void	execute_built_in(t_command	*command, t_be_executed	*to_exe, int procss)
{
	int	std_out;
	int	std_int;

	std_out = 0;
	std_int = 0;
	if (ft_is_executed(command) == 0)
	{
		close_pipes(to_exe->list_pipes);
		if (procss)
			exit(1);
		g_exit_status = 1;
		return ;
	}
	assign_input(command, to_exe);
	assign_output(command, to_exe);
	if (procss)
		close_other_pipes(command, to_exe->list_pipes);
	std_out = dup(STDOUT_FILENO);
	std_int = dup(STDIN_FILENO);
	exe_built_cmds(to_exe, command, procss);
	dup2(std_out, 1);
	dup2(std_int, 0);
	close(std_out);
	close(std_int);
}

void	create_commands(t_be_executed *to_execute, pid_t *pid)
{
	int			i;
	t_command	*commands_list;

	i = 0;
	commands_list = to_execute->commands_list;
	while (commands_list)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (is_built_in(commands_list->command_args[0]))
				execute_built_in(commands_list, to_execute, 1);
			else
				execute_command(commands_list, to_execute);
		}
		commands_list = commands_list->next;
		i++;
	}
}

void	close_then_wait(t_be_executed *to_execute, pid_t *pid)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	close_pipes(to_execute->list_pipes);
	while (i < to_execute->list_size)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_exit_status = WTERMSIG(status) + 128;
		i++;
	}
	free(pid);
}

void	execute_things(t_be_executed	*to_execute)
{
	t_command	*commands_list;
	pid_t		*pid;

	commands_list = to_execute->commands_list;
	if (to_execute->list_size == 1
		&& is_built_in(commands_list->command_args[0]))
	{
		execute_built_in(commands_list, to_execute, 0);
		return ;
	}
	pid = malloc(sizeof(pid_t) *(to_execute->list_size));
	signal(SIGINT, SIG_IGN);
	create_commands(to_execute, pid);
	close_then_wait(to_execute, pid);
}
